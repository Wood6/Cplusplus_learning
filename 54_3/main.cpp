// 类中有虚函数表时，强制类型转换时推荐使用 dynamic_cast
#include <iostream>

using namespace std;

class BaseA
{
public:
    virtual void funcA()
    {
        cout << "BaseA::funcA()" << endl;
    }
};

class BaseB
{
public:
    virtual void funcB()
    {
        cout << "BaseB::funcB()" << endl;
    }
};

class Derived : public BaseA, public BaseB
{

};

int main()
{
    Derived d;
    BaseA* pa = &d;
    BaseB* pb = &d;

    // 暴力强转，BaseB*指针的原意是期望指向d对象中的BaseB子对象部分，
    // 但暴力的强制转转会导致ppb指向对象的BaseA子对象，而不是期望的那样
    BaseB* ppb = (BaseB*)pa;

    // 使用dynamic_cast关键字来转换，编译器会先从d的地址这个对象
    // 然后从其继承树上找到该d对象中BaseB子对象的部分。从而能正
    // 确的进行指针间的转换。这也解决了上节内容同对象不同地址的问题
    BaseB* pbb = dynamic_cast<BaseB*>(pa);


    cout << "sizeof(d) = " << sizeof(d) << endl;

    cout << "Using pa to call funcA()..." << endl;
    pa->funcA();

    cout << "Using pb to call funcB()..." << endl;
    pb->funcB();

    cout << "Using ppb to call funcB()..." << endl;
    ppb->funcB();   // 期望调用BaseB::funcB，实际上调用的是BaseA::funcA！

    cout << "Using pbb to call funcB()..." << endl;
    pbb->funcB();   // 实际与期望的一致，都是调用BaseB::funcB

    cout << "pa = " << pa << endl;
    cout << "pb = " << pb << endl;
    cout << "ppb = " << ppb << endl;
    cout << "pbb = " << pbb << endl;

    return 0;
}
/* 运行结果
sizeof(d) = 8
Using pa to call funcA()...
BaseA::funcA()
Using pb to call funcB()...
BaseB::funcB()
Using ppb to call funcB()...
BaseA::funcA()
Using pbb to call funcB()...
BaseB::funcB()
pa = 0x61fe88
pb = 0x61fe8c
ppb = 0x61fe88
pbb = 0x61fe8c
*/
