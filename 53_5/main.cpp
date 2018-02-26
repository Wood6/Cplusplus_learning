// 钻石型虚继承 虚函数表的内存模型
#include <iostream>
#include <string>

using namespace std;

typedef void (*FuncPtr)();

void visitVtbl(int **vtbl, int count)
{
    cout << vtbl << endl;
    cout << "\t[-1]: " << (long)vtbl[-1] << endl;

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

// 利用虚继承解决数据冗余问题
class Base1 : virtual public Base
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

// 利用虚继承解决数据冗余问题
class Base2 : virtual public Base
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
    visitVtbl((int**)*(int**)p, 3);
    p += sizeof(int**);

    cout << *(int*)p << endl;
    p += sizeof(int);

    visitVtbl((int**)*(int**)p, 2);
    p += sizeof(int**);

    cout << *(int*)p << endl;
    p += sizeof(int);

    cout << *(int*)p << endl;
    p += sizeof(int);

    visitVtbl((int**)*(int**)p, 2);
    p += sizeof(int**);

    cout << *(int*)p << endl;

    return 0;
}
/* 运行结果 Windows下QtCreator的运行结果
0x40443c
    [-1]: 4211648
    [0]: 0x402c60 -> Derived::funcA()
    [1]: 0x402b4c -> Base1::funcB()
    [2]: 0x402c94 -> Derived::funcD()
101
0x404454
    [-1]: 4211648
    [0]: 0x402d40 -> Derived::funcA()
    [1]: 0x402bf0 -> Base2::funcC()
102
1001
0x40446c
    [-1]: 4211648
程序异常结束。

 ** linux下g++运行结果 **
0x8048e4c
        [-1]: 134516576
        [0]: 0x8048cc8 -> Derived::funcA()
        [1]: 0x8048b64 -> Base1::funcB()
        [2]: 0x8048c9c -> Derived::funcD()
101
0x8048e64
        [-1]: 134516576
        [0]: 0x8048cf4 -> Derived::funcA()
        [1]: 0x8048bfe -> Base2::funcC()
102
1001
0x8048e7c
        [-1]: 134516576
        [0]: 0x8048cfb -> Derived::funcA()
        [1]: 0x8048aca -> Base::funcX()
11
*/
