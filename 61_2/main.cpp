/* shared_ptr和weak_ptr的用法以及引用计数的循环引用问题
   g++ main.cpp -std=c++11
*/
/*
    在Man类内部通过shared_ptr指针引用一个Woman，Woman类内部也引用一个Man。
当一个man和一个woman是夫妻的时候，他们直接就存在了相互引用问题。man内部有个
用于管理wife生命期的shared_ptr变量，也就是说wife必定是在husband去世之后才能
去世。同样的，woman内部也有一个管理husband生命期的shared_ptr变量，也就是说
husband必须在wife去世之后才能去世。这就是循环引用存在的问题：husband的生命期
由wife的生命期决定，wife的生命期由husband的生命期决定，最后两人都死不掉，违
反了自然规律，导致了内存泄漏。

    解决hared_ptr循环引用问题的钥匙在weak_ptr手上。weak_ptr对象引用资源时
不会增加引用计数，但是它能够通过lock()方法来判断它所管理的资源是否被释放。另外很
自然地一个问题是：既然weak_ptr不增加资源的引用计数，那么在使用weak_ptr对象的
时候，资源被突然释放了怎么办呢？呵呵，答案是你根本不能直接通过weak_ptr来访问资
源。那么如何通过weak_ptr来间接访问资源呢？答案是：在需要访问资源的时候
weak_ptr为你生成一个shared_ptr，shared_ptr能够保证在shared_ptr没有被释放之
前，其所管理的资源是不会被释放的。创建shared_ptr的方法就是调用weak_ptr的
lock()方法。
*/

#include <iostream>
#include <memory>    // for 智能指针

using namespace std;

class Man;    // 前向声明

class Woman
{
private:
    shared_ptr<Man> _husband; // husband必须在wife去世之后才能去世。

public:
    void setHusband(shared_ptr<Man> man)
    {
        _husband = man;
    }

    void show()
    {
        cout << "age = 20, name = xishi" << endl;
    }

    ~Woman()
    {
        cout << "~Woman()" << endl;
    }
};

class Man
{
private:
    weak_ptr<Woman> _wife; // weak_ptr不能直接用来访问资源
    // shared_ptr<Woman> _wife; // 这句代表wife的生命期与Man一致，即
    // 妻子必须在丈夫去世后才能去世！这就是循环引用存在的问题
public:
    void setWife(shared_ptr<Woman> woman)
    {
        _wife = woman;
    }

    void doSomething()
    {
        // weak_ptr不能用来直接访问资源，可以通过lock()方法来创建
        // 一个临时对资源的拥有权的share_ptr指针
        if(shared_ptr<Woman> spt = _wife.lock())  // 判断资源是否被释放
        {
            spt->show();
        }
    }

    ~Man()
    {
        cout << "~Man" << endl;
    }
};

int main()
{
    shared_ptr<Man>  m(new Man());
    shared_ptr<Woman> w(new Woman());

    if( m &&  w)
    {
        m->setWife(w);
        w->setHusband(m);
    }

    m->doSomething();

    return 0;
}
/* 运行结果
age = 20, name = xishi
~Woman()
~Man
*/
