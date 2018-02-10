// 继承示例
#include <iostream>

using namespace std;

class Parent
{
private:
    int m_i;

public:
    Parent(int i = 0) : m_i(i)
    {
        cout << "Parent::Parent(int i = 0)" << endl;
    }

    void method()
    {
        cout << "Parent::method()" << endl;
    }

    ~Parent()
    {
        cout << "Parent::~Parent()" << endl;
    }
};

class Child : public Parent
{
public:
    Child()
    {
        cout << "Child::Child()" << endl;
    }

    ~Child()
    {
        cout << "Child::~Child()" << endl;
    }

    void hello()
    {
        cout << "I'm Chilld class!" << endl;
    }
};

int main()
{
    Child c1;
    Parent p1 = c1;   // 用子类对象初始化父类对象
    Parent p2;
    p2 = c1;          // 用子类对象赋值给父类对象

    c1.hello();       // 子类调用自己的方法
    c1.method();      // 子类调用父类的方法

    return 0;
}
/* 运行结果
Parent::Parent(int i = 0)
Child::Child()
Parent::Parent(int i = 0)
I'm Chilld class!
Parent::method()
Parent::~Parent()
Parent::~Parent()
Child::~Child()
Parent::~Parent()
*/
