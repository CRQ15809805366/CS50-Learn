// 下面是数组类的定义和实现，请填空：
#include <iostream>
using namespace std;

class Array {
  public:
    Array(int n); // 构造函数
    ~Array();     // 析构函数

    // 运算符重载
    int &operator[](int n);
    Array &operator=(Array &obj);
    bool operator==(Array &obj);

    // 获取数组大小
    int getSize()
    {
        return size;
    }

  private:
    int size; // 数组大小
    int *ptr; // 数组指针
};

Array::Array(int n)
{
    size = n;
    if (size > 0)
        ptr = new int[n]; // 申请包含n个数组元素的整型数组内存
    else
        ptr = NULL;
}

Array::~Array()
{
    if (size > 0)
        delete[] ptr; // 撤销申请的整型数组内存
}

int &Array::operator[](int i)
{
    /* 实现运算符[]的重载，返回整型数组的第i个元素
     引用，注意i要防止越界*/
    if (i >= 0 && i < size)
        return ptr[i];
}

bool Array::operator==(Array &obj)
{
    int _size = obj.getSize();
    if (size != _size)
        return false;

    for (int i = 0; i < size; i++)
    {
        /* 如果两个数组类对应的整型数组元素不等，则返
        回false*/
        if (obj[i] != ptr[i])
            return false;
    }

    return true;
}

int main()
{
    cout << "Hello World!\n";

    Array a(5), b(5);
    for (int i = 0; i < 5; i++)
    {
         // 此处可给a对象和b对象的内部数组元素赋任意值
         a[i] = i + 1;
         b[i] = i + 1;
    }

    if (a == b)
        cout << true;

    cout << endl;
}
