/*
用数组存储数据，实现筛选法求素数问题的求解。要求求出2到1000之间的所有素数。
筛选法(埃拉托斯特尼筛法)求出2～N间的所有素数的方法是：
首先将这些数全部放入一个数组中，然后重复下面的操作直到数组为空为止：
        a.找出其中的最小数K，则K一定是一个素数，因此可输出。
        b.从数组中删除K及其所有倍数。
下面的代码稍作修改实现上述功能，并将所有素数存入文件，请填空。
*/

#include <fstream>
using namespace std;

int main()
{
    int a[1001];    // 储存对应数字是否被删除或是否为素数
    int i, j, k, m;
    int sum = 0;    // 储存素数个数

    // ofstream 是一个类，outfile 是它的对象
    // 打开或创建一个名为 recorder.dat 的文件
    // 以输出(覆写)模式（ios::out）写入数据
    ofstream outfile("recorder.dat", ios::out);

    for (i = 0; i <= 1000; i++)
    {
        a[i] = true; // 数组初始化状态:全部数字尚未被删除且均为素数
    }

    for (i = 2; i <= 1000; i++) // 遍历所有数字
    {
        if (a[i] == true) // 数字尚未被删除, 且为素数
        {
            outfile << i << " ";   // 输出素数i到文件里，素数之间要有空格相隔
            sum++; // 素数个数加1

            k = 2;     // 倍数初始化为2
            m = i * k; // m初始为i的2倍

            while (m <= 1000)
            {
                a[m] = false; // i的k倍m不是素数，设置标志
                k++;          // 倍数加1
                m = i * k;    // 改变m的值, 使其成为i的k倍
            }

            if (sum % 10 == 0) // 每10个素数一行
            {
                outfile << endl;
            }
        }
    }

    outfile.close(); // 关闭文件流

    return 0;
}
