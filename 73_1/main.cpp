// new_handler() 以及为何要统一new的行为！
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Test
{
private:
    int m_value;

public:
    Test() : m_value(0)
    {
        cout << "Test()" << endl;
    }

    ~Test()
    {
        cout << "~Test()" << endl;
    }

    void* operator new (size_t size)
    {
        cout << "operator new: " << size << endl;

        // return malloc(size);   // 屏蔽掉这个正常的，为func2()测试用

        return NULL;
    }

    void operator delete(void* p)
    {
        cout << "operator delete: " << p << endl;
        free(p);
    }

    void* operator new[](unsigned int size)
    {
        cout << "operator new[]: " << size << endl;

        //return malloc(size);

        return NULL;
    }

    void operator delete[](void* p)
    {
        cout << "operator delete[]: " << p << endl;
        free(p);
    }
};

// 自定义 new_handler()
void my_new_handler()
{
    cout << "void my_new_handler()" << endl;
}

// 判断是否存在默认的new_handler全局函数及其所抛出的异常类型
void func1()
{
    // 若该编译器有全局的 new_handler(),则set_new_handler()
    // 虽然会用我们自定义的my_new_handler() 替换new_handler()
    // 的函数功能，但set_new_handler()函数本身会返回编译器默认的
    // new_handler()的函数地址，所以这个特性就正好可以被利用测试
    // 当前编译器有没有全局的默认 new_handler() 函数
    new_handler func = set_new_handler(my_new_handler);

    try
    {
        // 该编译器默认的全局 new_handler()的函数地址
        cout << "func = " << func << endl;

        // 如果存在默认的new_handler函数，则执行它。
        // 默认下g++和VC++编译器没有设置这样一个函数。
        // 但bcc会存在这样的new_handler()，并且会抛出bad_alloc异常
        if( func )
        {
            func();    // 调用默认的 new_handler()
        }
    }
    catch(const bad_alloc&)
    {
        // 默认的 new_handler()抛出bad_alloc异常打印这句
        cout << "catch(const bad_alloc&)" << endl;
    }
}

// 为什么要统一编译器的new行为
void func2()
{
    // 出现段错误的原因及解决方案：
    // 当调用new operator时，会找到重载的operator new，紧接着
    // 调用Test的构造函数。如果重载的operator new函数未加异常规格
    // 说明，表示可以抛出任何类型的异常。qtCreator/g++编译器认为：
    // 未加异常说明的operator new，调用失败时是会抛出异常的。如果
    // 没有抛出异常就说明分配内存是成功的，所以会继续调用对象的构造
    // 函数。但由于我们重载的new返回的是NULL，这恰恰骗了qtCreator/g++
    // 编译器一把，所以会出现给0地址对象的成员(m_value)赋值。因此，
    // 出现段错误。而VS2017编译器不管抛不抛出异常，在调用构造函数前
    // 都会判断对象指针是否为NULL，为NULL则不调用构造函数。

    // 这就有了问题
    // new失败结果不同，而导致行为不同，那怎么可以做到统一呢？下节解决！

    // 创建对象
    Test* pt = new Test();
    cout << "pt = " << pt << endl;
    delete pt;

    // 创建数组对象
    pt = new Test[5];
    cout << "pt = " << pt << endl;
    delete[] pt;
}

int main()
{
    cout << "======== func1 test ==========" << endl;
    func1();
    cout << "======== func2 test ==========" << endl;
    func2();
}
/* 运行结果
** Windows下qtCreator5.9.6的编译运行结果
======== func1 test ==========
func = 0
======== func2 test ==========
operator new: 4
程序异常结束。
The process was ended forcefully.

** linux g++ 编译运行结果
======== func1 test ==========
func = 0
======== func2 test ==========
operator new: 4
Segmentation fault (core dumped)

** VS2017编译运行结果
======== func1 test ==========
func = 00000000
======== func2 test ==========
operator new: 4
pt = 00000000
operator new[]: 24
pt = 00000000

结论：
1、new_handler()上面三个编译器都没有全局的new_handler()，
   在这点上，都没有遵循C++规范而设计，网上查到bcc编译器是
   有new_handler()的，这个编译器返回的运行结果应该是
   func = 0x11111111
   catch(const bad_alloc&)
2、关于new失败编译器怎么处理见上面注释；
*/
