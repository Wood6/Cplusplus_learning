// 继承对象模型：多重继承多个虚函数
#include <iostream>

using namespace std;

class Base1
{
private:
    int mBase1;

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
};

class Base2
{
private:
    int mBase2;

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
};

class Derived : public Base1, public Base2
{
private:
    int mDerived;

public:
    Derived(): Base1(), Base2()
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
};

int main()
{

    return 0;
}

