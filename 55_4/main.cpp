// dynamic_cast使用的注意点
#include <iostream>

using namespace std;

class Base
{
public:
    Base() {cout << "Base::Base()" << endl;}
    virtual ~Base() {cout << "Base::~Base()" << endl;}
};

class Derived : public Base
{
public:
    Derived() {cout << "Derived::Derived()" << endl;}
    ~Derived() {cout << "Derived::~Derived()" << endl;}
};

int main()
{
    /* 上行转换，子类转换为父类是安全转换 */
    Derived* pd = new Derived;
    // 注意pd所指的类中一定要有虚函数，本例中，析构函数声明为虚函数。
	// 因为dynamic_cast转换是在运行时进行转换，运行时转换就需要知道
	// 类对象的信息（继承关系等）。如何在运行时获取到这个信息——虚函数表。
	// 所以dynamic_cast转换的类中一定要有虚函数表

    Base* pb = dynamic_cast<Base*>(pd);
    // 注意,这里也提醒我们,可以用dynamic_cast来判断一个类是不是另一个类父类的
    // 方法，具体方法Base* p = dynamic_cast(Base* p)(pDerived);即，子类能否转
    // 为父类。如果返回值不为NULL，表示有父子关系。否则没有。


    if( pb != NULL )  // 转换成功。
    {
        cout << "pb = " << pb << endl;
    }
    else              // 转换失败，返回空指针NULL
    {
        cout << "Cast Error!" << endl;
    }

    delete pd;
    cout << endl;

    // 下行转换，父类转换为子类是不安全转换
    Base* p = new Base;
    Derived* ppd = dynamic_cast<Derived*>(p);

    if( ppd != NULL )
    {
        cout << "ppd = " << ppd << endl;
    }
    else
    {
        cout << "Cast Error!" << endl;
    }

    delete p;

    return 0;
}
/* 运行结果
Base::Base()
Derived::Derived()
pb = 0x2f510c8         // 证明Derived是Base的子类
Derived::~Derived()
Base::~Base()

Base::Base()
Cast Error!            // 不安全转换，被检测出来
Base::~Base()
*/
