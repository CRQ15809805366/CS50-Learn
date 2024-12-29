#include <iostream>
using namespace std;

// 链队列节点结构
struct Node
{
    int data;   // 数据域
    Node *next; // 指针域
};

// 链队列类
class Queue {
  private:
    Node *front; // 队首指针
    Node *rear;  // 队尾指针

  public:
    // 构造函数，初始化队列
    Queue()
    {
        front = rear = nullptr;
    }

    // 析构函数，销毁队列
    ~Queue()
    {
        destroyQueue();
    }

    // 入队操作
    void enqueue(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (rear)
        {
            rear->next = newNode; // 连接到队尾
        }
        else
        {
            front = newNode; // 如果队列为空，设置队首为新节点
        }
        rear = newNode; // 更新队尾指针
        cout << "元素 " << value << " 入队成功。\n";
    }

    // 出队操作
    void dequeue()
    {
        if (!front)
        {
            cout << "队列为空，无法出队！\n";
            return;
        }
        Node *temp = front;
        int data = front->data;
        front = front->next;
        if (!front)
        {
            rear = nullptr; // 如果队列为空，更新队尾指针
        }
        delete temp;
        cout << "元素 " << data << " 出队成功。\n";
    }

    // 显示队列中的元素
    void displayQueue()
    {
        if (!front)
        {
            cout << "队列为空。\n";
            return;
        }
        Node *current = front;
        cout << "队列元素：";
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // 销毁队列，释放内存
    void destroyQueue()
    {
        Node *current = front;
        while (current)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        front = rear = nullptr;
        cout << "队列已撤销。\n";
    }
};

// 菜单功能
void menu()
{
    cout << "\n--- 链队列操作菜单 ---\n";
    cout << "1. 入队\n";
    cout << "2. 出队\n";
    cout << "3. 显示队列\n";
    cout << "4. 撤销队列\n";
    cout << "5. 退出\n";
    cout << "---------------------\n";
}

int main()
{
    Queue q;
    int choice, value;

    while (true)
    {
        menu();
        cout << "请选择操作(1-5) : ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "请输入入队元素值：";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.displayQueue();
                break;
            case 4:
                q.destroyQueue();
                break;
            case 5:
                cout << "退出系统。\n";
                return 0;
            default:
                cout << "无效选择，请重新输入！\n";
        }
    }
    return 0;
}
