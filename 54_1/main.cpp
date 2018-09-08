// 多继承问题1：多继承得到的对象拥有不同地址
#include <iostream>

using namespace std;

class BaseA
{
protected:
    int m_a;

public:
    BaseA(int a) : m_a(a) {}

    int getMa() {return m_a;}
};

class BaseB
{
protected:
    int m_b;

public:
    BaseB(int b) : m_b(b) {}

    int getMb() {return m_b;}
};

class Derived : public BaseA, public BaseB
{
private:
    int m_c;

public:
    Derived(int a, int b, int c) : BaseA(a), BaseB(b), m_c(c) {}

    int getMc() {return m_c;}

    void print()
    {
        // m_a和m_b在父类中是protected权限，子类可以直接访问
        cout << "m_a = " << m_a << endl
             << "m_b = " << m_b << endl
             << "m_c = " << m_c << endl;
    }
};

int main()
{
    cout << "sizof(Derived) = " << sizeof(Derived) << endl;   // 12

    Derived d(1, 2, 3);

    d.print();
    cout << endl;

    cout << "d.getMa() = " << d.getMa() << endl;
    cout << "d.getMb() = " << d.getMb() << endl;
    cout << "d.getMc() = " << d.getMc() << endl;
    cout << endl;

    // 注意以下两行，都是将对象d的地址赋值给一个指针，表面上看似
    // pa指针应该等于pb指针，但实际上不会这样pa指向的是d对象中
    // BaseA的子对象，而pb指向的是d对象中BaseB子对象的部分。
    BaseA* pa = &d;
    BaseB* pb = &d;

    void* paa = pa;
    void* pbb = pb;

    if( paa == pbb )  // pa和pb不能直接转换
    {
        cout << "point to the same object!" << endl;
    }
    else
    {
        cout << "Error" << endl;  // 该行被输出！
    }

    cout << endl;
    cout << "pa = " << pa << endl;
    cout << "pb = " << pb << endl;

    cout << "paa = " << paa << endl;
    cout << "pbb = " << pbb << endl;

    return 0;
}
/* 运行结果
sizof(Derived) = 12
m_a = 1
m_b = 2
m_c = 3

d.getMa() = 1
d.getMb() = 2
d.getMc() = 3

Error

pa = 0x61fe84
pb = 0x61fe88
paa = 0x61fe84
pbb = 0x61fe88
*/
