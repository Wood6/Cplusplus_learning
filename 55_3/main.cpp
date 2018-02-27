// 构造函数中间接调用虚函数
#include <iostream>

using namespace std;

class Base
{
public:
    int m_i;

public:
    Base() : m_i(0)
    {
        test();
    }

    virtual void func()
    {
        cout << m_i << " ";
    }

    void test()
    {
        func();
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        test();
    }

    void func()
    {
        ++m_i;
        cout << m_i << " ";
    }
};

int main()
{
    Base* pb = new Derived;
    // new Derived时，会先构造父类Base，由于进入Base构造函数之前，Base的
    // 虚函数表己构造好。因此，调用Base构造函数时，会通过查找其虚函数表，因此
    // 调用Base::func。构造完父类后，开始构造子类Derived。在进入构造函数之前
    // 父类Base的虚函数表会被Derived所修改和覆盖，因此会调用到Derived::func

    /* 上面分析过程是错误的，原因很简单就是构造函数中调用虚函数不会发生多态*/

    pb->test();     // 多态，调用Derived::func

    cout << endl;

    return 0;
}
/* 运行结果
0 1 2 （注意分析为什么不是0 0 1? 见上面的分析）
*/
