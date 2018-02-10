// 赋值兼容性
#include <iostream>

using namespace std;

class Parent
{
public:
    int m_v;

    void add(int a)
    {
        m_v += a;
    }

    void add(int a, int b)  // Parent中的两个add构成重载关系
    {
        m_v += (a + b);
    }
};

class Child : public Parent
{
public:
    int m_i;

    void add(int a, int b, int c)
    {
        m_i += (a + b + c);
    }
};

int main()
{
    Child c1;
    Parent p1(c1);      // 子类直接初始化父类对象
    Parent p2;

    c1.m_i = 100;

    p2 = c1;            // 子类直接赋值给父类（赋值兼容）

    Parent& rp = c1;    // 父类引用直接引用子类对象,c1退化为父类对象
    Parent* pp = &c1;   // 父类指针直接指向子类对象,c1退化为父类对象

    // 没有发生同名覆盖，因为使用的是父类的引用，会调用父类的函数
    rp.m_v = 200;
    rp.add(5);
    rp.add(10, 10);
    //rp.add(10, 10, 10);  // 报错

    //pp->m_i = 1000;      // 用父类指针，只能调用父类的成员变量
    //pp->add(1, 1, 1);    // 用父类指针，只能调用父类的成员函数

    // 原因分析
    // 编译期间，编译器只能根据指针的类型判断所指向的对象。
    // 根据赋值兼容，编译器认为父类指针指向的是父类对象，
    // 因此，编译结果只可能是调用父类中定义的同名函数！

    cout << "c1.m_i = " << c1.m_i << endl;
    cout << "c1.Parent::m_v = " << c1.Parent::m_v << endl;

    return 0;
}
/* 运行结果
c1.m_i = 100
c1.Parent::m_v = 225
*/

