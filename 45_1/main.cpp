// 继承 访问级别 的探索
#include <iostream>

using namespace std;

class Parent
{
protected:
    int m_pro;
private:
    int m_pri;
public:
    int m_pub;

    void setMember(int a, int b, int c)
    {
        m_pro = a;
        m_pri = b;
        m_pub = c;
    }
};

class Child_A : public Parent
{
public:
    void print()
    {
        cout << "m_pro = " << m_pro << endl;

        //任何方式都不能访问父类的私有成员
        //cout << "m_pri = " << m_pri << endl;

        cout << "m_pub = " << m_pub << endl;
    }
};

class Child_B : protected Parent
{
public:
    void print()
    {
        cout << "m_pro = " << m_pro << endl;
        //cout << "m_pri = " << m_pri << endl;
        cout << "m_pub = " << m_pub << endl;
    }
};

class Child_C : private Parent
{
public:
    void print()
    {
        cout << "m_pro = " << m_pro << endl;
        //cout << "m_pri = " << m_pri << endl;
        cout << "m_pub = " << m_pub << endl;
    }
};

int main()
{
    Child_A a;
    Child_B b;
    Child_C c;

    /* 继承过来的成员变量 */
    //a.m_pro = 100;   // 外界不能访问保护成员
    //a.m_pri = 100;   // 私有成员更是不能访问了
    a.m_pub = 100;     // 公开成员外界可以访问

    //b.m_pub = 100;   // Child_B,protected继承自parent，所以来自父类
                       // 的公有成员m_c变成了protected属性，外界无法访问

    //c.m_pub = 100;   // Child_C，private继承自parent，所以来自父类
                       // 的成员m_c变成了private属性，外界无法访问


    /* 继承过来的成员函数 */
    a.setMember(5, 5, 5);
    //b.setMember(6, 6, 6); // 继承方式protected,来自父类的函数无法被外界访问
    //c.setMember(7, 7, 7); // 继承方式private,来自父类的函数无法被外界访问

    /* 子类自己的函数访问父类成员变量 */
    a.print();
    cout << endl;      // 正常

    b.print();
    cout << endl;      // 输出结果不正常

    c.print();
    cout << endl;      // 输出结果不正常

    return 0;
}
/* 运行结果
m_pro = 1
m_pub = 3

m_pro = 0
m_pub = 49221144

m_pro = 4200495
m_pub = 65535
*/
