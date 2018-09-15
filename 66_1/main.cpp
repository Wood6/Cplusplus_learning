// 动态类型识别：利用多态获取动态类型
#include <iostream>
#include <string>

using namespace std;

class Base
{
public:
    // 在基类中提供个用来判断类型的虚函数
    // 并且所有的派生类中都必须实现这个函数
    virtual string type()
    {
        return "Base";   // 手动返回一个用于识别的标识符
    }
};

class Derived : public Base
{
public:
    string type()
    {
        return "Derived";
    }

    void print()
    {
        cout << "I'm a Derived." << endl;
    }
};

class Child : public Base
{
public:
    string type()
    {
        return "Child";
    }
};

void test(Base* b)
{
    // 危险的转换方式。因为b实际类型可能不是Derived的类型
    // Derived* d = static_cast<Derived*>(b);
    if(b->type() == "Derived")
    {
        Derived* d = static_cast<Derived*>(b);
        d->print();
    }

    // 如果类中没有虚函数表，则调用dynamic_cast会直接报错，编译不过。
    // 当父、子类没有继承关系时，dynamic_cast返回0，否则会转换后
    // 实际对象的地址
    cout << std::boolalpha  << dynamic_cast<Derived*>(b) << endl;
}

int main()
{
    Base b;
    Derived d;
    Child c;

    cout << "---------- &b ---------------" << endl;
    test(&b);    // Base与Base没有继承关系，dynamic_cast返回0
    cout << "---------- &d ---------------" << endl;
    test(&d);    // Derived与Base有继承关系，dynamic_cast转换后对象的地址
    cout << "---------- &c ---------------" << endl;
    test(&c);    // Child与Derived没有继承关系，返回0

    return 0;
}
/* 运行结果
---------- &b ---------------
0
---------- &d ---------------
I'm a Derived.
0x61fe98
---------- &c ---------------
0
*/
