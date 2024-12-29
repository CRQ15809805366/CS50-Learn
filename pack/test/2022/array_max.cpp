/*
在主函数中定义一个整型的二维数组A[3][4]，利用二重循环从键盘录入数组A的每个元素。
设计一个函数findmax，找出二维数组A中的某一列k，
在所有列中，第k列的所有元素之和最大，返回该列的序号；
在主函数中输出该列的序号和该列的所有元素。
*/

#include <iostream>
using namespace std;

int findmax(int arr[3][4])
{
    int c_sum[4] = {0};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c_sum[i] += arr[j][i];
        }
    }

    int i, count;
    for (i = 0, count = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (c_sum[i] < c_sum[j])
                count++;
        }

        int rank = count + 1;
        if (rank == 1)
            break;
    }

    return i;
}

int main(void)
{
    int A[3][4];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << "Please put in an integar: ";
            cin >> A[i][j];
        }
    }

    int max_column = findmax(A);
    cout << "Max column: " << max_column << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << A[i][max_column] << endl;
    }

    return 0;
}
