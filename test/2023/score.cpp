/*
3.某班联考成绩公布，如成绩形如（675，567，580，633，580，675，580，575）。
请编写程序，给对应的成绩给出相应的名次为（1，8，4，3，4，4，1，4，7），
要求不能改变成绩的次序，且相同的成绩要具有相同的编号，名次要累计前面的总人数。
例如：
       成绩顺序=(675 567 580 633 580 675 580 575)
       则输出名次应为：（1 8 4 3 4 1 4 7）
即成绩数组675依从高到低的名次为1，567依从高到低的名次为8，…
*/

#include <iostream>
#define stunum 8
using namespace std;

int main(void)
{
    int score[stunum] = {675, 567, 580, 633, 580, 675, 580, 575};
    int rank[stunum] = {0};

    for (int i = 0; i < stunum; i++)
    {
        int count = 0;
        for (int j = 0; j < stunum; j++)
        {
            if (score[i] < score[j])
                count++;
        }

        rank[i] = count + 1;
    }

    for (int i = 0; i < stunum; i++)
        cout << rank[i] << "\t";
    cout << endl;

    return 0;
}
