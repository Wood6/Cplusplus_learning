// 继承对象模型：单一继承单个虚函数
#include <iostream>

using namespace std;

class Parent
{
protected:
    int m_i;
    int m_j;

public:
    virtual void print()
    {
        cout << "m_i = " << m_i << endl
             << "m_j = " << m_j << endl;
    }
};

class Child : public Parent
{
private:
    int m_k;

public:
    Child(int i, int j, int k)
    {
        m_i = i;
        m_j = j;
        m_k = k;
    }

    void print()
    {
        cout << "m_i = " << m_i << endl
             << "m_j = " << m_j << endl
             << "m_k = " << m_k << endl;
    }
};

struct st
{
    void* p;
    int m_i;
    int m_j;
    int m_k;
};

int main()
{
     // 12，不是8，因为插入了一个虚函数表指针
    cout << "sizeof(Parent) = " << sizeof(Parent) << endl;
    cout << "sizeof(Child) = " << sizeof(Child) << endl;  // 16 原因同上

    Child c1(1, 2, 3);

    // 以下实验证明带有虚函数的 Child 的内存模型与 st 结构体是一致的
    // 1、大小相同。2、第1个成员变量是vptr指针；3、往后依次为mi、mj、mk

    st* s = reinterpret_cast<st*>(&c1);

    cout << "Before Change..." << endl;
    c1.print();

    s->m_i = 10;
    s->m_j = 20;
    s->m_k = 30;

    cout << "Before Change..." << endl;
    c1.print();

    return 0;
}
/* 运行结果
sizeof(Parent) = 12
sizeof(Child) = 16
Before Change...
m_i = 1
m_j = 2
m_k = 3
Before Change...
m_i = 10
m_j = 20
m_k = 30
*/
