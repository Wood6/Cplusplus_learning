// 子类调用父类构造函数
#include <iostream>

using namespace std;

class Parent
{
public:
    Parent()
    {
        cout << "Parent()" << endl;
    }

    Parent(string s)
    {
        cout << "Parent(string s): " << s << endl;
    }

    ~Parent()
    {
        cout << "~Parent()" << endl;
    }
};

class Child : public Parent
{
public:
    Child() // 这里虽然没写，但会默认调用父类无参构造函数
    {
        cout << "Child()" << endl;
    }

    // 在初始化列表中显式调用父类带参的Parent(string s)构造函数
    // 如果不显式调用，则会默认调用父类无参的Parent()构造函数
    Child(string s) : Parent(s)
    {
        cout << "Child(string s): " << s << endl;
    }
};

int main()
{
    Child t1;
    Child t2("t2");

    return 0;
}
/* 运行结果
Parent()
Child()
Parent(string s): t2
Child(string s): t2
~Parent()
~Parent()
*/
