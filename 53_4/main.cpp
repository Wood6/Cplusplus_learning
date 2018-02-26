// 单一虚继承 虚函数表的内存模型
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

int main()
{
    Base1 b1;
    char *p = (char*)&b1;
    visitVtbl((int**)*(int**)p, 2);
    p += sizeof(int**);

    cout << *(int*)p << endl;
    p += sizeof(int);

    visitVtbl((int**)*(int**)p, 2);
    p += sizeof(int**);

    cout << *(int*)p << endl;

    return 0;
}
/* 运行结果 Windows下QtCreator的运行结果
0x404344
    [-1]: 4211448
    [0]: 0x402aa8 -> Base1::funcA()
    [1]: 0x402adc -> Base1::funcB()
101
0x40435c
    [-1]: 4211448
程序异常结束。

 ** linux下g++运行结果 **
0x8048c2c
        [-1]: 134515824
        [0]: 0x8048ac0 -> Base1::funcA()
        [1]: 0x8048afc -> Base1::funcB()
101
0x8048c44
        [-1]: 134515824
        [0]: 0x8048aec -> Base1::funcA()
        [1]: 0x8048a58 -> Base::funcX()
11
*/
