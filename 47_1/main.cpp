// 子类与父类有同名成员变量的情况
#include <iostream>

using namespace std;

class Parent
{
public:
    int m_i;

    Parent() : m_i(0)
    {
        cout << "Parent(),&m_i = " << &m_i << endl;
    }
};

class Child : public Parent
{
public:
    int m_i;

    Child() : m_i(1)
    {
        cout << "Child(),&m_i = " << &m_i << endl;
    }
};

int main()
{
    Child t1;

    t1.m_i = 100;         // 子类中的m_i
    t1.Parent::m_i = 200; // 父类中的m_i，被隐藏，须加作用域分辨符访问

    cout << "t1.m_i = " << t1.m_i << endl;
    cout << "&t1.m_i = " << &t1.m_i << endl;

    cout << "t1.Parent::m_i = " << t1.Parent::m_i << endl;
    cout << "&t1.Parent::m_i = " << &t1.Parent::m_i << endl;

    return 0;
}
/* 运行结果
Parent(),&m_i = 0x61fe98
Child(),&m_i = 0x61fe9c
t1.m_i = 100
&t1.m_i = 0x61fe9c
t1.Parent::m_i = 200
&t1.Parent::m_i = 0x61fe98
*/
