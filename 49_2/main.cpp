// 静态连编 和 动态连编
#include <iostream>

using namespace std;

class Parent
{
public:
    virtual void func()
    {
        cout << "Parent::func()" << endl;
    }

    virtual void func(int a)
    {
        cout << "Parent::func(int a)" << endl;
    }

    virtual void func(int a, int b)
    {
        cout << "Parent::func(int a, int b)" << endl;
    }
};

class Child : public Parent
{
public:
    void func(int a, int b)
    {
        cout << "Child::func(int a, int b)" << endl;
    }

    void func(int a, int b, int c)
    {
        cout << "Child::func(int a, int b, int c)" << endl;
    }
};

void run(Parent& p)
{
    p.func(1, 2);     // 展现多态的特性，动态联编
}

int main()
{
    Parent p;

    p.func();          // 静态联编
    p.func(1);         // 静态联编
    p.func(1, 2);      // 静态联编

    cout << endl;

    Child c;

    c.func(1, 2);       // 静态联编
    c.func(1, 2, 3);    // 静态联编

    cout << endl;

    run(p);
    run(c);

    cout << endl;

    Parent& rp = c;

    rp.func();           // 动态联编,virtual函数，尽管func()在Child中没有被重写
    rp.func(1, 2);       // 动态联编
    //error: no matching function for call to 'Parent::func(int, int, int)'
    //void func(int a, int b, int c) 不是virtual函数，不能多态，而父类中又没有这个函数，所以error
    //rp.func(1, 2, 3);

    return 0;
}
/* 运行结果
Parent::func()
Parent::func(int a)
Parent::func(int a, int b)

Child::func(int a, int b)
Child::func(int a, int b, int c)

Parent::func(int a, int b)
Child::func(int a, int b)

Parent::func()
Child::func(int a, int b)
*/
