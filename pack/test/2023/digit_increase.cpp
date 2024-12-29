// 求出10000以内的所有符合如下条件的数：其高位数字小于低位数字。如12，238，3578等。但21，548不符合条件

#include <iostream>
using namespace std;

int main()
{
    int i;
    int a, b, c, d;

    for (i = 0; i < 10000; i++)
    {
        a = i % 10;
        b = i / 10 % 10;
        c = i / 100 % 10;
        d = i / 1000;
        if (i > 9 && i < 100)
        {
            if (a > b)
                cout << i << " ";
        }
        if (i > 99 && i < 1000)
        {
            if (a > b && b > c)
                cout << i << " ";
        }
        if (i > 999 && i < 10000)
        {
            if (a > b && b > c && c > d)
                cout << i << " ";
        }
    }

    cout << endl;

    return 0;
}
