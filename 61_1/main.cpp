// STL标准库中 智能指针auto_ptr使用示例
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Test
{
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
    // 智能指针，会自动销毁堆空间
    auto_ptr<Test> pt(new Test("SantaClaus")); // pt本质上是个对象，但重载了->操作符
    cout << "pt = " << pt.get() << endl;       // pt指针所指的内存地址

    pt->print();

    cout << endl;

    //同一个堆空间，每次只能有一个auto_ptr指针指向它
    auto_ptr<Test> pt1(pt);                // 让pt1指向pt所指的空间，会发生所有权的转移
    cout << "pt = " << pt.get() << endl;   // 所有权转移，pt == 0
    cout << "pt1 = " << pt1.get() << endl; // pt1指向原来的堆空间

    pt1->print();

    cout << endl;

    auto_ptr<Test> ptArray (new Test[10]); // auto_ptr指向堆数组，会发生内存泄漏！
    // 当释放时相当于delete ptArray 而不是delete[] ptArray

    return 0;
}
/* 运行结果
Hello, SantaClaus.
pt = 0x1310c8
I'm SantaClaus.

pt = 0
pt1 = 0x1310c8
I'm SantaClaus.

Hello, SantaClaus.
Hello, SantaClaus.
Hello, SantaClaus.
Hello, SantaClaus.
Hello, SantaClaus.
Hello, SantaClaus.
Hello, SantaClaus.
Hello, SantaClaus.
Hello, SantaClaus.
Hello, SantaClaus.
Good bye, SantaClaus.
Good bye, SantaClaus.  // 只释放了ptArray[0]
*/
