# 编译器
CXX = g++

# 编译选项
CXXFLAGS = -Wall

# 输出的可执行文件
TARGET = Palindrome

# 源文件
SRC = Palindrome.cpp Stack.cpp

# 目标文件
OBJ = $(SRC:.cpp=.o)

# 默认目标（不调试）
all: $(TARGET)
	@echo "编译完成"
	@rm -f $(OBJ)

# 编译可执行文件
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# 编译 .cpp 文件
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 调试版本（自动启用 -g 并进入 gdb）
debug: CXXFLAGS += -g
debug: $(TARGET)
	@echo "调试版本编译完成，正在启动 gdb..."
	@rm -f $(OBJ)  # 删除目标文件
	@gdb -ex run --args ./$(TARGET)

# 清理
clean:
	rm -f $(OBJ) $(TARGET)