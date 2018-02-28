// main.cpp
#include <iostream>
#include "SmartPointer.h"

using namespace std;

class Test
{
private:
    string m_name;

public:
    Test()
    {
        m_name = "SantaClaus";
        cout <<"Hello, " << m_name << "." << endl;
    }

    Test(const char* name)
    {
        m_name = name;
        cout <<"Hello, " << m_name << "." << endl;
    }

    void print()
    {
        cout << "I'm " << m_name << "." << endl;
    }

    ~Test()
    {
        cout << "Good bye, " << m_name << "." << endl;
    }
};

int main()
{
    // 本质上智能指针是个对象（而不是指针，只是重载了->操作符）
    SmartPointer<int> pi = new int(5);
    SmartPointer<float> pf(new float(10.05f));

    cout <<"*pi=" << *pi <<", *pf="<<*pf<<endl;

    SmartPointer<Test> pt(new Test("SantaClaus"));
    pt->print();

    SmartPointer<Test> ppt(pt);

    if (ppt == pt)
    {
        cout <<"ppt == pt" << endl;
    }

    return 0;
}
/* 运行结果
*pi=5, *pf=10.05
Hello, SantaClaus.
I'm SantaClaus.
ppt == pt
Good bye, SantaClaus.
*/

