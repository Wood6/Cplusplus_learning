// new时，在静态存储区创建动态对象
#include <iostream>

using namespace std;

class Test
{
private:
    // 存储在静态区中Test对象的最大数量
    static const unsigned int COUNT = 4;
    // 用于存储Test对象的静态内存区，注意为static变量
    static char c_buffer[];
    // 用于标识内存空间的使用情况
    static char c_map[];

public:
    Test()
    {
        cout << "Test()" << endl;
    }
    ~Test()
    {
        cout << "~Test()" << endl;
    }

    // 默认为静态函数，重载new操作符，将对象分配在静态区（而非堆上！）
    void* operator new (size_t size) throw()
    {
        void* ret = NULL;

        // 查找静态区中的内存空闲
        for(unsigned int i=0; i<COUNT; i++)
        {
            if(c_map[i] != 1)   // 空闲时
            {
                ret = c_buffer + sizeof(Test) * i;
                c_map[i] = 1;   // 标志为正在使用
                cout << "success to allocate memory: " << ret << endl;

                break;
            }
        }

        return ret;

        // 当返回后，编译器继继会生成调用构造函数来初始化这片内存空间的代码
    }

    // 默认为静态函数，重载delete操作符，将释放对应的内存空间（标志为空闲）
    void operator delete (void* p) throw()
    {
        if(p != NULL)
        {
            char* mem = reinterpret_cast<char*>(p);
            int index = (mem - c_buffer) / sizeof(Test);
            int flag = (mem - c_buffer) % sizeof(Test);

            if((0 == flag) && (0 <= index) && (index < COUNT))
            {
                c_map[index] = 0; // 标记为空闲
            }

            cout << "succeed to free memory: " << p << endl;
        }

        // 函数返回后，编译器自动生成调用析构函数的代码
    }
};

char Test::c_buffer[sizeof(Test) * Test::COUNT] = {0};
char Test::c_map[Test::COUNT] = {0};

int main()
{
    cout << "===== Test Single Object =====" << endl;

    Test* pt = new Test;
    delete pt;

    cout << "===== Test Object Array =====" << endl;

    Test* pa[5] = {0};

    // 模拟内存管理，因内存区最多只能分配4个Test对象，当申请第5个
    // 对象时，会返回NULL。这个例子也可结合二阶构造来生成《多例模式》
    for(int i=0; i<5; i++)
    {
        pa[i] = new Test;
        cout << "pa[" << i << "] = " << pa[i] << endl;
    }

    // 释放
    for(int i=0; i<5; i++)
    {
        cout << "delete " << pa[i] << endl;
        delete pa[i];
    }

    return 0;
}
/* 运行结果
success to allocate memory: 0x406038
Test()
~Test()
succeed to free memory: 0x406038
===== Test Object Array =====
success to allocate memory: 0x406038
Test()                                 // 释放内存后自动调用了析构函数
pa[0] = 0x406038
success to allocate memory: 0x406039
Test()
pa[1] = 0x406039
success to allocate memory: 0x40603a
Test()
pa[2] = 0x40603a
success to allocate memory: 0x40603b
Test()
pa[3] = 0x40603b
pa[4] = 0                              // 第5个对象分配失败
delete 0x406038
~Test()                                // 分配内存后自动调用了构造函数
succeed to free memory: 0x406038
delete 0x406039
~Test()
succeed to free memory: 0x406039
delete 0x40603a
~Test()
succeed to free memory: 0x40603a
delete 0x40603b
~Test()
succeed to free memory: 0x40603b
delete 0
*/
