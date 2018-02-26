// 重复继承 内存模型
#include <iostream>
#include <string>

using namespace std;

void visitVtbl(int **vtbl, int count)
{
    cout << vtbl << endl;
    cout << "\t[-1]: " << (long)vtbl[-1] << endl;

    typedef void (*FuncPtr)();

    // 很奇怪，同样在Windows下的QtCreator编译器中，这个重复继承模型
    // 的虚函数表似乎末尾给自动加上了结尾标志符，第二个虚函数表竟然完整
    // 运行了，没有崩溃
    for (int i = 0; vtbl[i] && i < count; ++i)
    {
        cout << "\t[" << i << "]: " << vtbl[i] << " -> ";
        FuncPtr func = (FuncPtr)vtbl[i];
        func();
    }
}

class Base
{
public:
    Base()
    {
        mBase = 11;
    }
    virtual void funcA()
    {
        cout << "Base::funcA()" << endl;
    }
    virtual void funcX()
    {
        cout << "Base::funcX()" << endl;
    }

protected:
    int mBase;
};

class Base1 : public Base
{
public:
    Base1():
        Base()
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

class Base2 : public Base
{
public:
    Base2():
        Base()
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

    visitVtbl((int**)*(int**)p, 4);
    p += sizeof(int**);

    cout << *(int*)p << endl;
    p += sizeof(int);

    cout << *(int*)p << endl;
    p += sizeof(int);

    visitVtbl((int**)*(int**)p, 3);
    p += sizeof(int**);

    cout << *(int*)p << endl;
    p += sizeof(int);

    cout << *(int*)p << endl;
    p += sizeof(int);

    cout << *(int*)p << endl;

    return 0;
}
/* 运行结果
0x4043d4
    [-1]: 4211536
    [0]: 0x402c50 -> Derived::funcA()
    [1]: 0x402ad4 -> Base::funcX()
    [2]: 0x402b5c -> Base1::funcB()
    [3]: 0x402c84 -> Derived::funcD()
11
101
0x4043ec
    [-1]: 4211536
    [0]: 0x402cfc -> Derived::funcA()
    [1]: 0x402ad4 -> Base::funcX()
    [2]: 0x402bf0 -> Base2::funcC()
11
102
1001
*/
