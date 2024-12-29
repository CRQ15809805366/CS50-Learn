/*
声明并实现一个名为Person的基类，
Person类有数据成员name（姓名，string类型）、
sex（性别，char类型，'M'表示男，'F'表示女）。
定义有参构造函数，将姓名、性别设置为给定的参数；
定义成员函数print，输出姓名和性别, 用虚函数方式设计。

从Person类派生出Student类，
Student类有数据成员status（状态，string类型），
表示年级（Freshman、Sophomore、Junior、Senior），表示大一、大二、大三、大四学生。
定义有参构造函数，将姓名、性别、状态设置为给定的参数；
重新定义成员函数print，print函数输出姓名、性别和状态。

从Person类派生出Faculty类，
Faculty类有私有数据成员title（职称，string类型），
包括（Professor、Associate_Professor、Lecture）等职称，表示教授、副教授、讲师。
定义有参构造函数，将姓名、性别、级别设置为给定的参数；
重新定义成员函数print，输出姓名、性别和职称。

主函数中分别创建学生对象，职员对象，
通过基类Person类的指针调用print函数实现学生对象和职员对象相应信息的输出。
*/

#include <iostream>
#include <string>
using namespace std;

class Person {
  private:
    string name;
    char sex;

  public:
    string get_name()
    {
        return name;
    }

    char get_sex()
    {
        return sex;
    }

    Person(string n, char s)
    {
        name = n;
        sex = s;
    }

    virtual void print()
    {
        cout << "Name: " << get_name() << " " << "Sex: " << get_sex() << endl;
    }
};

class Student : public Person {
  private:
    string status;

  public:
    string get_status()
    {
        return status;
    }

    Student(string n, char s, string sta) : Person(n, s), status(sta) {}

    virtual void print()
    {
        cout << "Name: " << get_name() << " " << "Sex: " << get_sex() << " " << "Status: " << get_status() << endl;
    }
};

class Faculty : public Person {
  private:
    string title;

  public:
    string get_title()
    {
        return title;
    }

    Faculty(string n, char s, string t) : Person(n, s), title(t) {}

    virtual void print()
    {
        cout << "Name: " << get_name() << " " << "Sex: " << get_sex() << " " << "Title: " << get_title() << endl;
    }
};

int main(void)
{
    Person *ptr;

    Student stu("Bob", 'M', "Freshman");
    Faculty fac("Mike", 'M', "Professor");

    ptr = &stu;
    ptr->print();

    ptr = &fac;
    ptr->print();

    return 0;
}
