#!/bin/bash

# 确保当前在仓库根目录
cd "$(git rev-parse --show-toplevel)"

# 步骤 1: 更新 .gitignore 以忽略无扩展名的文件
echo "Step 1: Updating .gitignore to ignore extensionless files..."
if ! grep -q "/*" .gitignore; then
    echo "Adding rule to ignore extensionless files..."
    echo "/*" >> .gitignore
    echo "!/**/" >> .gitignore
    echo "!*.*" >> .gitignore
fi

# 步骤 2: 停止追踪并删除已被 Git 追踪的无扩展名文件（排除 LICENSE 和 README.md）
echo "Step 2: Untracking and removing extensionless files from Git (excluding LICENSE and README.md)..."
git ls-files | while read file; do
    if [[ "$file" != *.* && "$file" != "LICENSE" && "$file" != "README.md" ]]; then
        git rm --cached "$file"
    fi
done

# 步骤 3: 删除工作目录中所有无扩展名的文件（排除 LICENSE 和 README.md）
echo "Step 3: Deleting untracked extensionless files (excluding LICENSE and README.md)..."
find . -type f ! -name "*.*" ! -name "LICENSE" ! -name "README.md" -exec rm -f {} +

# 步骤 4: 提交 .gitignore 的更改
echo "Step 4: Committing .gitignore changes..."
git add .gitignore
git commit -m "Update .gitignore to ignore extensionless files"

# 步骤 5: 使用 git filter-repo 彻底清理历史记录中的无扩展名文件（排除 LICENSE 和 README.md）
echo "Step 5: Cleaning history with git filter-repo (excluding LICENSE and README.md)..."

# 安装 git filter-repo（如果未安装）
if ! command -v git-filter-repo &> /dev/null; then
    echo "Installing git-filter-repo..."
    pip install git-filter-repo
fi

# 运行 git filter-repo 清理历史记录中的无扩展名文件（排除 LICENSE 和 README.md）
git filter-repo --path-glob '*' --path-glob '!*.*' --path 'LICENSE' --path 'README.md' --invert-paths --force

# 步骤 6: 强制推送到远程仓库
echo "Step 6: Force pushing changes to remote..."
git push origin --force --all
git push origin --force --tags

echo "Cleanup complete! Extensionless files and their history have been removed (excluding LICENSE and README.md)."