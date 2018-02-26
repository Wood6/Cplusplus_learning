// 多重继承 虚函数表的内存模型
#include <iostream>
#include <string>

using namespace std;

void visitVtbl(int **vtbl, int count)
{
    cout << vtbl << endl;
    cout << "\t[-1]: " << (long)vtbl[-1] << endl;

    typedef void (*FuncPtr)();

    // linux的g++编译器会在虚函数表结尾加上结尾标志符,linux运行OK
    // windows下QtCreator编译器没有给虚函数表加上末尾标志符，所以
    // 运行第二个虚函数表时崩溃,因为第二个参数3使得i累加使虚函数越界访问
    for (int i = 0; vtbl[i] && i < count; ++i)
    {
        cout << "\t[" << i << "]: " << vtbl[i] << " -> ";
        FuncPtr func = (FuncPtr)vtbl[i];
        func();
    }
}

class Base1
{
public:
    Base1()
    {
        mBase1 = 101;
    }
    virtual void funcA()
    {
        cout << "Base1::funcA()" << endl;
    }
    virtual void funcB()
    {
        cout << "Base1::funcB()" << endl;
    }
private:
    int mBase1;
};

class Base2
{
public:
    Base2()
    {
        mBase2 = 102;
    }
    virtual void funcA()
    {
        cout << "Base2::funcA()" << endl;
    }
    virtual void funcC()
    {
        cout << "Base2::funcC()" << endl;
    }
private:
    int mBase2;
};

class Derived : public Base1, public Base2
{
public:
    Derived():
        Base1(),
        Base2()
    {
        mDerived = 1001;
    }
    virtual void funcD()
    {
        cout << "Derived::funcD()" << endl;
    }
    virtual void funcA()
    {
        cout << "Derived::funcA()" << endl;
    }
private:
    int mDerived;
};

int main()
{
    Derived d;
    char *p = (char*)&d;
    visitVtbl((int**)*(int**)p, 3);
    p += sizeof(int**);

    cout << *(int*)p << endl;
    p += sizeof(int);

    visitVtbl((int**)*(int**)p, 3);
    p += sizeof(int**);

    cout << *(int*)p << endl;
    p += sizeof(int);

    cout << *(int*)p << endl;

    return 0;
}
/* 运行结果 Windows下QtCreator的运行结果
0x404388
    [-1]: 4211492
    [0]: 0x402b60 -> Derived::funcA()
    [1]: 0x402a84 -> Base1::funcB()
    [2]: 0x402b94 -> Derived::funcD()
101
0x40439c
    [-1]: 4211492
    [0]: 0x402c0c -> Derived::funcA()
    [1]: 0x402b0c -> Base2::funcC()
程序异常结束。

 ** linux下g++运行结果 **
0x8048ce8
        [-1]: 134516032
        [0]: 0x8048b8a -> Derived::funcA()
        [1]: 0x8048a84 -> Base1::funcB()
        [2]: 0x8048b5e -> Derived::funcD()
101
0x8048cfc
        [-1]: 134516032
        [0]: 0x8048bb6 -> Derived::funcA()
        [1]: 0x8048af4 -> Base2::funcC()
102
1001
*/

