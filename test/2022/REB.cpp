/*
球从高处下落，以一定速度接触到地面时，
地面会给球一个力使球不让弹性形变，而后球内的气体会有一个使球恢复原状的力，
这样在球恢复原状的过程中，球又会给地面一个力，
而由于力的作用是相互的，同时地面又会给篮球一个力，正是靠这个力将球弹起。

设一球从100米高度自由落下，每次落地后反跳回原高度的三分之二；
再落下，求它在第3次落地时，共经过多少米？第3次反弹多高？
*/

#include <iostream>
using namespace std;

int main(void)
{
    double hgt = 100;
    double dist = 0;

    for (int i = 0; i < 10; i++)
    {
        if (i == 0)
            dist += hgt;
        else
            dist += 2 * hgt;

        // 2/3结果必须为浮点数, 因此必须为2.0/3.0转化为浮点数除法
        hgt *= (2.0 / 3.0);
    }

    cout << "Distance: " << dist << endl;
    cout << "Height: " << hgt << endl;

    return 0;
}
