// 工程上面多继承使用方式：单继承+多接口
#include <iostream>

using namespace std;

class Base
{
protected:
    int m_i;

public:
    Base(int i) : m_i(i) {}

    int getMi() {return m_i;}

    // 以下是个技巧，用来判断指针是否指向同一个对象
    bool equal(Base* p)     // 传参用的单继承的基类类型
    {
        return (this == p);
    }
};

// 接口1
class Interface1
{
public:
    virtual void add(int v) = 0;
    virtual void minus(int v) = 0;
};

// 接口2
class Interface2
{
public:
    virtual void multiply(int v) = 0;
    virtual void division(int v) = 0;
};

// 单继承+多接口
class Derived : public Base, public Interface1, public Interface2
{
public:
    Derived(int i) : Base(i) {}

    void add(int v)
    {
        m_i += v;
    }

    void minus(int v)
    {
        m_i -= v;
    }

    void multiply(int v)
    {
        m_i *= v;
    }

    void division(int v)
    {
        if( !v )
        {
            m_i /= v;
        }
    }
};

int main()
{
    Derived d(22);

    // 子类调用函数
    d.add(1);
    cout << "d.m_i = " << d.getMi() << endl;
    d.minus(1);
    cout << "d.m_i = " << d.getMi() << endl;
    d.multiply(1);
    cout << "d.m_i = " << d.getMi() << endl;
    d.division(1);
    cout << "d.m_i = " << d.getMi() << endl;
    cout << endl;

    // 通过接口父类调用相应函数
    Interface1* pInt1 = &d;
    Interface2* pInt2 = &d;

    pInt1->add(1);
    cout << "d.m_i = " << d.getMi() << endl;
    pInt1->minus(1);
    cout << "d.m_i = " << d.getMi() << endl;

    pInt2->multiply(1);
    cout << "d.m_i = " << d.getMi() << endl;
    pInt2->division(1);
    cout << "d.m_i = " << d.getMi() << endl;
    cout << endl;

    // 判断pInt1和pInt2指向的是不是同一个对象
    cout << "pInt1 == pInt2 : "
         << (d.equal(dynamic_cast<Base*>(pInt1)) == d.equal(dynamic_cast<Base*>(pInt2)))
         << endl;
    // 注意，通过dynamic_cast将pInt1和pInt2指针转为指向d对象中Base
    // 对子对象部分，这样尽管pInt1和pInt2的值不同，但他们都转为同一个
    // Base指针，然后通过Base类的equal函数，判断转换后的两个指针是否
    // 相等，从而可以判断他们是不是指向同一个对象d。

    return 0;
}
/* 运行结果
d.m_i = 23
d.m_i = 22
d.m_i = 22
d.m_i = 22

d.m_i = 23
d.m_i = 22
d.m_i = 22
d.m_i = 22

pInt1 == pInt2 : 1
*/
