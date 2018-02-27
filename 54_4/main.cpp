// dynamic_cast 与 static_cast 对类类型转换的区别
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

    // 从子类到父类转换(上行转换是安全的)
    BaseA* pas = static_cast<BaseA*>(&d);
    BaseA* pad = dynamic_cast<BaseA*>(&d);
    BaseB* pbs = static_cast<BaseB*>(&d);
    BaseB* pbd = dynamic_cast<BaseB*>(&d);

    cout << "&d = " << &d << endl;
    cout << "pas = " << pas << endl;
    cout << "pad = " << pad << endl;
    cout << "pbs = " << pbs << endl;
    cout << "pbd = " << pbd << endl;
    cout << endl;

    BaseA a;
    // 从父类到子类转换(下行转换时不安全的)
    Derived* pds = static_cast<Derived*>(&a);   // 没有检查,直接转换
    Derived* pdd = dynamic_cast<Derived*>(&a);  // 就有检查,返回0

    cout << "&a = " << &a << endl;
    cout << "pds = " << pds << endl;
    cout << "pdd = " << pdd << endl;
    cout << endl;

    // 交叉转换
    //BaseB* pbbs = static_cast<BaseB*>(pad);  // Error：static_cast不能用于交叉转换
    BaseB* pbbd = dynamic_cast<BaseB*>(pad);

    //cout << "pbbs = " << pbbs << endl;
    cout << "pbbd = " << pbbd << endl;

    return 0;
}
/* 运行结果
&d = 0x61fe7c
pas = 0x61fe7c
pad = 0x61fe7c
pbs = 0x61fe80
pbd = 0x61fe80

&a = 0x61fe78
pds = 0x61fe78
pdd = 0

pbbd = 0x61fe80
*/
