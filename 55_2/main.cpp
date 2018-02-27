// 构造函数、析构函数、虚函数
#include <iostream>

using namespace std;

class Base
{
public:
    Base()  // 不能成为虚函数，加了virtual就编译报错;
    {
        cout << "Base::Base()" << endl;
        func();  // 不会发生多态，只会调用本类中的函数版本！
    }

    virtual void func()
    {
        cout << "Base::func()" << endl;
    }

    // 可以成为虚函数，并且建议析构函数写为虚函数(尤其有继承关系时)
    // 若不是虚析构函数,则主函数中delete pd 只调用
    // ~Base不会调用~Derived,可能就导致内存泄漏
    virtual ~Base()
    {
        cout << "Base::~Base()" << endl;
        func();  // 不会发生多态，只会调用本类中的函数版本！
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Derived::Derived()" << endl;
        func();  // 不会发生多态，只会调用本类中的函数版本！
    }

    void func()
    {
        cout << "Derived::func()" << endl;
    }

    ~Derived()
    {
        cout << "Derived::~Derived()" << endl;
        func();  // 不会发生多态，只会调用本类中的函数版本！
    }
};

int main()
{
    Base* pd = new Derived;
    // 注意是父类指针，如果这里直接声明为Derived* p = new  Derived()
    // 则delete p直接调用子类的构造函数。但我们本例的目的之一是为了演示
    // 析构函数的多态，所以声明为父类的针。

    cout << endl;

    delete pd;
    // delete会调用析构函数。从这行代码看，如果父类中析构函数没被声明为虚函数
    // 的话，delete一个父类的指针，由于静态绑定，所以会调用的是父类的析构函
    // 数，从而造成Derived的析构函数没被调用。当然，如果父类中析构函数被声明为
    // 虚函数，根据多态原理，将会调用子类的析构函数，结合析构的特点，会先调用子
    // 类自己的析构函数，再调用父类析构，从而正确的释放内存。

    return 0;
}
/* 运行结果
Base::Base()
Base::func()           // 注意，并没有发生多态
Derived::Derived()
Derived::func()        // 注意，并没有发生多态

Derived::~Derived()
Derived::func()        // 注意，并没有发生多态
Base::~Base()
Base::func()           // 注意，并没有发生多态
*/
