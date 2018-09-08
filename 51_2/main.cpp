// 继承对象模型：单一继承多个虚函数
#include <iostream>

using namespace std;

class Base
{
private:
    int mBase1;
    int mBase2;

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
};

class Derived : public Base
{
private:
    int mDerived1;
    int mDerived2;

public:
    Derived() : Base()
    {
        mDerived1 = 1001;
        mDerived2 = 1002;
    }

    void func2()
    {
        cout << "Derived::func2()" << endl;
    }

    virtual void func3()
    {
        cout << "Derived::func3()" << endl;
    }
};

int main()
{

    return 0;
}
