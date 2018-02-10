// 构造顺序：父类对象->成员对象->构造函数体
#include <iostream>

using namespace std;

class Object
{
private:
    string m_s;

public:
    Object(string s) : m_s(s)
    {
        cout << "Object(string s): " << s << endl;
    }

    ~Object()
    {
        cout << "~Object(): " << m_s << endl;
    }
};

class Parent : public Object
{
private:
    string m_s;

public:
    // 必须显式调用，因为父类Object没有提供无参构造函数，而默认
    // 调用只会调用无参（或带默认参数）的构造函数
    Parent() : Object("Default") , m_s("Default")
    {
        cout << "Parent()" << endl;
    }

    Parent(string s) : Object(s) , m_s(s)
    {
        cout << "Parent(string s): " << s << endl;
    }

    ~Parent()
    {
        cout << "~Parent(): " << m_s << endl;
    }
};

class Child : public Parent
{
private:
    Object m_o1;
    Object m_o2;
    string m_s;

public:
    // 默认调用Parent()进行初始化
    Child() : m_o1("Default"), m_o2("Default"), m_s("Default")
    {
        cout << "Child(): " << endl;
    }

    // 在初始化列表中显式调用父类带参的Parent(string s)
    // 构造函数，并对成员变量mO1和mO2进行初始化
    Child(string s) : Parent(s), m_o1(s + " 1"), m_o2(s + " 2"), m_s(s)
    {
        cout << "Child(string s): " << s << endl;
    }

    ~Child()
    {
        cout << "~Child(): " << m_s << endl;
    }
};

int main()
{
    Child t1("t1");

    cout << endl;

    return 0;
}
/* 运行结果
Object(string s): t1
Parent(string s): t1      // 父类初始化完毕
Object(string s): t1 1
Object(string s): t1 2    // 成员变量初始化完毕
Child(string s): t1       // 自身的初始化

~Child(): t1              // 析构自身
~Object(): t1 2
~Object(): t1 1           // 析构成员变量完毕
~Parent(): t1
~Object(): t1             //析构父类
*/
