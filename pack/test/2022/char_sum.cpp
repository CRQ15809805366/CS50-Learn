/*
从键盘输入一个有n个元素的字符数组，
分别统计其中的大写字母、小写字母、数字字符和其他字符的个数。
(说明：大写字母的范围是：'A'到'Z'；、小写字母的范围是'a'到'z'、数字字符的范围是'０'到'９')
*/

#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cout << "n: ";
    cin >> n;

    char c[n];
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    int upper_num = 0;
    int lower_num = 0;
    int number_num = 0;
    int other_num = 0;
    for (int i = 0; i < n; i++)
    {
        if (c[i] >= 'A' && c[i] <= 'Z')
            upper_num++;
        else if (c[i] >= 'a' && c[i] <= 'z')
            lower_num++;
        else if (c[i] >= '0' && c[i] <= '9')
            number_num++;
        else
            other_num++;
    }

    cout << "upper_num: " << upper_num << " " << "lower_num: " << lower_num << " " << "number_num: " << number_num
         << " " << "other_num: " << other_num << endl;

    return 0;
}
