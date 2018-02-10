// 子类与父类有同名成员函数时
#include <iostream>

using namespace std;

class Parent
{
public:
    int m_i;

    void add(int a)
    {
        m_i += a;
    }

    void add(int a, int b)  // Parent中的两个add构成重载关系
    {
        m_i += (a + b);
    }
};

/*
1、child中的2个add函数构成了重载关系
2、因child出现了以add命名的函数（只要有1个与父类同名的函数），所以
   父类的所有名为add的函数在子类中都会被隐藏起来
*/
class Child : public Parent
{
public:
    int m_i;

    void add(int a)
    {
        m_i += a;
    }

    void add(int a, int b, int c)
    {
        m_i += (a + b + c);
    }
};

int main()
{
    Child t1;

    t1.m_i = 100;
    t1.Parent::m_i = 200; // 父类中的m_i，被隐藏，须加作用域分辨符访问

    cout << "t1.m_i = " << t1.m_i << endl;
    cout << "t1.Parent::m_i = " << t1.Parent::m_i << endl;

    t1.add(1);             // 子类的add
    t1.add(1, 2 , 3);      // 父类的add，在子类中被隐藏，须加作用域访问符

    t1.Parent::add(10);    // 子类的add

    cout << "t1.m_i = " << t1.m_i << endl;
    cout << "t1.Parent::m_i = " << t1.Parent::m_i << endl;



    return 0;
}
/* 运行结果
t1.m_i = 100
t1.Parent::m_i = 200
t1.m_i = 107
t1.Parent::m_i = 210
*/
