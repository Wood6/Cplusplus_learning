// 动态类型识别: typeid类型识别关键字
#include <iostream>
#include <string>
#include <typeinfo>       // for typeid

using namespace std;

class Base
{
public:
    virtual ~Base() {}
};

class Derived : public Base
{
public:
    void print()
    {
        cout << "I'm a Derived." << endl;
    }
};

void test(Base* b)
{
    // const type_info& tb = typeid(b);   // 判断b的类型, Base* 或 Derived*
    const type_info& tb = typeid(*b);     // 判断对象的类型

    cout << tb.name() << endl;
}

int main()
{
    int i = 0;

    const type_info& tiv = typeid(i);           // 判断变量的类型,编译期确定
    const type_info& tii = typeid(int);         // 判断类的类型,运行期确定

    cout << std::boolalpha << (tiv == tii) << endl;  // 相等

    Base b;
    Derived d;

    test(&b);        // 运行期确定
    test(&d);        // 运行期确定

    cout << typeid(Base).name() << endl;       // 编译期确定
    cout << typeid(Derived).name() << endl;    // 编译期确定

    return 0;
}
/* 运行结果
true
4Base             // g++ 下类名前面的数字表示类名的长度
7Derived
4Base
7Derived
*/
