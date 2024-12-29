/*
2.编写一个程序，实现录入某班（人数30）学生的姓名和数学成绩，
  然后通过函数降序输出不及格人员的姓名和成绩信息。
*/

#include <iostream>
#include <string>
using namespace std;

struct student
{
    string name;
    int math_point;
};

int main(void)
{
    student students[30];
    for (int i = 0; i < 30; i++)
    {
        cout << "name" << " " << "math_point" << " ";
        cin >> students[i].name >> students[i].math_point;
    }

    // 冒泡排序: 若有n个元素, 则进行n - 1轮, 每轮交换次数从n - 1递减
    // 本题数组内有30个元素, 则进行29轮
    for (int i = 0; i < 29; i++)
    {
        for (int j = 0; j < 29 - i; j++)
        {
            if (students[j].math_point < students[j + 1].math_point)
            {
                student tmp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = tmp;
            }
        }
    }

    for (int i = 0; i < 30; i++)
    {
        if (students[i].math_point < 60)
            cout << "name: " << students[i].name << "math_point: " << students[i].math_point
                 << endl;
    }

    return 0;
}
