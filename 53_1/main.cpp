// 单继承 虚函数表的内存模型
#include <iostream>
#include <string>

using namespace std;

void visitVtbl(int **vtbl)
{
    cout << vtbl << endl;
    cout << "\t[-1]: " << (long)vtbl[-1] << endl;

    typedef void (*FuncPtr)();
    int i=0;
    // 在linux下是是没有问题的，说明linux的g++编译器会在虚函数表
    // 结尾加上结尾标志符，但在windows下这个地方会运行崩溃
    while(vtbl[i]!=0)
    {
        cout << "\t[" << i << "]: " << vtbl[i] << " -> ";
        // 取出虚函数标表中的函数指针赋值给函数指针变量
        FuncPtr func = (FuncPtr)vtbl[i];
        // 通过函数指针变量调用函数，通过这里调用结果证明了虚函数表的内存模型
        func();
        ++i;
    }
}

class Base
{
public:
    Base()
    {
        mBase1 = 101;
        mBase2 = 102;
    }
    virtual void func1()
    {
        cout << "Base::func1()" << endl;
    }
    virtual void func2()
    {
        cout << "Base::func2()" << endl;
    }
private:
    int mBase1;
    int mBase2;
};

class Derived : public Base
{
public:
    Derived():
        Base()
    {
        mDerived1 = 1001;
        mDerived2 = 1002;
    }
    virtual void func2()
    {
        cout << "Derived::func2()" << endl;
    }
    virtual void func3()
    {
        cout << "Derived::func3()" << endl;
    }
private:
    int mDerived1;
    int mDerived2;
};

int main()
{
    Derived d;
    char *p = (char*)&d;
    // p指向d的地址，(int**)p将p强制转换为二重指针，为下一步服务
    // *(int**)p进入到d对象，d对象的首位置，也是虚函数表的位置
    // (int**)*(int**)p 将虚函数表的地址强制转换为二重指针
    visitVtbl((int**)*(int**)p);
    p += sizeof(int**);   // 跳过虚函数表指针

    cout << *((int*)p) << endl;
    p += sizeof(int);

    cout << *((int*)p) << endl;
    p += sizeof(int);

    cout << *((int*)p) << endl;
    p += sizeof(int);

    cout << *((int*)p) << endl;

    return 0;
}
/* 运行结果 Windows下QtCreator的运行结果
0x404334
    [-1]: 4211452
    [0]: 0x402a50 -> Base::func1()
    [1]: 0x402ae4 -> Derived::func2()
    [2]: 0x402b18 -> Derived::func3()
Error - RtlWerpReportException failed with status code :
-1073741823. Will try to launch the process directly
程序异常结束。

 ** linux下g++运行结果 **
0x404338
        [-1]: 4211452
        [0]: 0x402998 -> Base::func1()
        [1]: 0x402a20 -> Derived::func2()
        [2]: 0x402a50 -> Derived::func3()
101
102
1001
1002
*/
