// 重载new[]、delete[]
#include <iostream>
#include <cstdlib>   // for malloc函数

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

    void* operator new (unsigned int size) throw()
    {
        void* ret = NULL;

        ret = malloc(size);
        cout << "operator new: " << ret << "size: " << size << endl;

        return ret;
    }

    void operator delete (void* p) throw()
    {
        cout <<"operator delete: " << p << endl;
        free(p);
    }

    void* operator new[] (unsigned int size) throw()
    {
        void* ret = NULL;

        ret = malloc(size);
        cout << "operator new[]: " << ret << "size: " << size << endl;

        return ret;
    }

    void operator delete[] (void* p) throw()
    {
        cout <<"operator delete[]: " << p << endl;
        free(p);
    }
};

int main()
{
    Test* pt = NULL;

    cout << "===== Test Single Object =====" << endl;

    pt = new Test;   // 注意使用new关键字与直接使用Test::operator new(...)函数是有区别的。
                     // new Test会调用Test的构造函数，而函数调用方式则不会。
    delete pt;

    cout << "===== Test Object Array =====" << endl;
    // 当用new Test[5]时，只须传入数组元素的个数，编译器会向operator new[](...)函数中
    // 传入的参数为5*sizeof(Test) + sizeof(unsigned int)，其中的sizeof(unsigned int)为额外
    // 空间，用于保存元素的个数。同理new Test[5]与直接使用Test::operator new[](...)是有区别的。
    // 前者会调用构造函数，后者则不会。
    pt = new Test[5]; // 相当于Test::operator new(5*sizeof(Test) + sizeof(unsigned int))
    delete[] pt;

    return 0;
}
/* 运行结果
===== Test Single Object =====
operator new: 0x2751180size: 4
Test()
~Test()
operator delete: 0x2751180
===== Test Object Array =====
operator new[]: 0x2751180size: 24    // 多出4Byte内存空间，存数组信息的
Test()
Test()
Test()
Test()
Test()
~Test()
~Test()
~Test()
~Test()
~Test()
operator delete[]: 0x2751180
*/
