// 统一编译器的new行为、new带参用法示例
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

    void* operator new (size_t size) throw()
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

    void* operator new[](unsigned int size) throw()
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

// 统一编译器的new行为
void func2()
{
    // 上个演示：new失败结果不同，而导致行为不同，那怎么可以做到统一呢？

    // 为了统一编译器的行为，在operator new函数后加throw()异常
    // 规格说明，表示该函数不会抛出异常。这样编译器在调用对象的构造函数
    // 前就会主动判断对象指针是否为NULL，如果为NULL则不调用构造函数。

    // 创建对象
    Test* pt = new Test();
    cout << "pt = " << pt << endl;
    delete pt;

    // 创建数组对象
    pt = new Test[5];
    cout << "pt = " << pt << endl;
    delete[] pt;
}

// 使用单次动态内存分配
void func3()
{
    // 使用nothrow指明new不抛出异常，看代码时注意是int类型不是Test
    // nothrow 表示不抛出异常，需要自行判断 p 是否为 NULL
    int* p = new(nothrow) int[10];

    // ....

    delete[] p;

    // new 的其它带参用法，参数指定内存申请的空间
    int bb[2]={0};

    struct ST
    {
        int x;
        int y;
        ~ST()
        {
            cout << "~ST(): " << "(x, y) = ";
            cout << "(" << x << ", " << y << ")" << endl;
        }
    };

    // 在bb数组栈空间new一个对象
    ST* pt = new(bb) ST();
    pt->x = 1;
    pt->y = 2;

    cout << bb[0] << endl;    // 输出：1
    cout << bb[1] << endl;    // 输出：2


    pt->~ST();    // 这样显示指定的空间，必须显式调用析构函数释放空间
    //delete pt;  // 程序会异常结束，delete会去堆空间释放使程序崩溃
}

int main()
{
    cout << "======== func2 test ==========" << endl;
    func2();
    cout << "======== func3 test ==========" << endl;
    func3();
}
/* 运行结果
** Windows下qtCreator5.9.6的编译运行结果
======== func2 test ==========
operator new: 4
pt = 0
operator new[]: 24
pt = 0
======== func3 test ==========
1
2
~ST(): (x, y) = (1, 2)

** linux g++ 编译运行结果
======== func2 test ==========
operator new: 4
pt = 0
operator new[]: 24
pt = 0
======== func3 test ==========
1
2
~ST(): (x, y) = (1, 2)

** VS2017编译运行结果
======== func2 test ==========
operator new: 4
pt = 00000000
operator new[]: 24
pt = 00000000
======== func3 test ==========
1
2
~ST(): (x, y) = (1, 2)

结论：
1、fun2测试结果：原来不同的编译器new行为这下便全部统一了
   工程上也常用这种方式统一不同编译器之间new的行为
2、就是new的一些带参用法示例了
*/
