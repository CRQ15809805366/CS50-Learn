/*
1. 题目：编写一个程序，计算一个居民区的水费。居民区的水费计算规则如下：

（1）每户每月用水量为20立方米，20立方米以内的每立方米收费2元。
（2）超过20立方米的部分，每立方米收费3.5元。
（3）如果居民区的总用水量超过1000立方米，可以享受8折优惠。
请编写一个程序，输入居民区的总用水量（立方米），输出居民区的水费（元）。
*/

#include <iostream>
using namespace std;

int main(void)
{
    // 获取总用水量
    int water;
    cout << "water capicity: ";
    cin >> water;

    // 计算水费
    int fee;
    if ((water - 20) > 20)
        fee = (water - 20) * 3.5 + 20 * 2;
    else
        fee = water * 2;

    if (fee > 1000)
        fee *= 0.8;

    // 输出水费
    cout << "water fee: " << fee << endl;
}
