// 链表中元素是一个结构体，由数据项和指针项组成。元素的指针项是指向下一个元素，如果是最一个元素，指针为空NULL。
#include <iostream>
using namespace std;

struct element
{
    // 定义链表中的结点结构
    int val;
    element *next;
};

class list {
  private:
    // 定义链表类
    element *elems;

  public:
    list()
    {
        elems = 0;
    }
    bool insert(int);
    void print();
};

bool list::insert(int val) // 定义list类中插入元素的成员函数
{
    element *elem = new element; // 为新元素分配存储
    if (elem != 0)
    {
        elem->val = val; // 将新元素插入到链表头
        elem->next = elems;
        elems = elem;
        return true;
    }
    else
        return false;
}

void list::print() // 输出链表中各元素
{
    if (elems == 0)
        return;
    for (element *elem = elems; elem != 0; elem = elem->next)
        cout << elem->val << "  ";
    cout << endl;
}

int main()
{
    list *ptr, list1;

    ptr = &list1;
    ptr->insert(30);
    ptr->insert(40);
    ptr->print();

    return 0;
}
