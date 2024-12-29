/*
创建一个动物类animal类，动物有自己的属性名字name，年龄age等，定义相应的数据成员和成员函数。
动物都会发出声音,定义一个统一的接口makesound函数。派生出猫cat，狗dog，鸭duck类等，
以不同的方式输出声音，如猫的声音是“miaomiao”，狗的声音是“wangwang”，鸭的声音是“gaga”等。
定义一个名为count的静态数据成员，用来存储各类对象的总数。
每个类都定义构造函数和析构函数（即使函数体为空），在构造函数中对name和age进行初始化。
主函数中分别创建猫类、狗类、鸭类各一个对象，通过调用makesound函数输出相应的声音，并调用相应的函数输出总共的动物个数。
*/

#include <iostream>
#include <string>
using namespace std;

class Animal {
  private:
    string name;
    int age;
    static int count; // 静态成员变量在类内声明时，只是告知编译器它的存在, 并不会分配内存

  public:
    Animal(string n, int a) : name(n), age(a)
    {
        count++;
    }

    ~Animal()
    {
        count--;
    }

    virtual void makesound() = 0;

    static void show_count()
    {
        cout << "Animal count: " << count << endl;
    }
};

// 静态成员变量是类级别的，不依赖于对象的实例化, 因此在类外定义
int Animal::count = 0; // 在类外定义时，编译器需要明确类型来分配内存

class Cat : public Animal {
  public:
    Cat(string n, int a) : Animal(n, a) {}
    ~Cat() {}
    virtual void makesound()
    {
        cout << "miaomiao" << endl;
    }
};

class Dog : public Animal {
  public:
    Dog(string n, int a) : Animal(n, a) {}
    ~Dog() {}
    virtual void makesound()
    {
        cout << "wangwang" << endl;
    }
};

class Duck : public Animal {
  public:
    Duck(string n, int a) : Animal(n, a) {}
    ~Duck() {}
    virtual void makesound()
    {
        cout << "gaga" << endl;
    }
};

int main(void)
{
    Animal *ptr;

    Cat cat("cat", 2);
    ptr = &cat;
    ptr->makesound();

    Dog dog("dog", 3);
    ptr = &dog;
    ptr->makesound();

    Duck duck("duck", 1);
    ptr = &duck;
    ptr->makesound();

    Animal::show_count();

    return 0;
}
