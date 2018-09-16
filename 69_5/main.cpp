// 指定内存区域创建C++对象
#include <iostream>
#include <cstdlib>   // for calloc函数

using namespace std;

class Test
{
private:
    // 存储在Test对象的最大数量
    static unsigned int c_count;
    // 用于存储Test对象的内存区
    static char* c_buffer;
    // 用于标识内存空间的使用情况
    static char* c_map;

public:
    Test()
    {
        cout << "Test()" << endl;
    }
    ~Test()
    {
        cout << "~Test()" << endl;
    }

    // 设置将对象存储在指定的内存地址处
    static bool setMemorySource(char* memory, unsigned int size)
    {
        bool ret = false;

        c_count = size / sizeof(Test);   // 计算对象的个数

        // calloc会初始化内存为0
        ret = ((memory != NULL) && (c_count != 0) && (c_map = reinterpret_cast<char*>(calloc(c_count, sizeof(char)))));
        if( ret )
        {
            c_buffer = memory;
        }
        else
        {
            free(c_map);
            c_map = NULL;
            c_buffer = NULL;
            c_count = 0;
        }

        return ret;
    }

    // 默认为静态函数，重载new操作符，将对象分配在静态区（而非堆上！）
    void* operator new (size_t size) throw()
    {
        void* ret = NULL;

        if(c_count > 0)
        {
            // 查找静态区中的内存空闲
            for(unsigned int i=0; i<c_count; i++)
            {
                if(c_map[i] != 1)   // 空闲时
                {
                    ret = c_buffer + sizeof(Test) * i;
                    c_map[i] = 1;   // 标志为正在使用
                    cout << "success to allocate memory: " << ret << endl;

                    break;
                }
                //空闲己满，直接返回NULL
            }
        }
        else
        {
            // 当没有调用SetMemorySource来要求在指定的地址上分配对象（默认情况）
            // 此时直接在堆上创建对象
            ret = malloc(size);
            cout << "allocate in Heap memory: " << ret << endl;
        }

        return ret;

        // 当返回后，编译器继继会生成调用构造函数来初始化这片内存空间的代码
    }

    // 默认为静态函数，重载delete操作符，将释放对应的内存空间（标志为空闲）
    void operator delete (void* p) throw()
    {
        if(p != NULL)
        {
            if(c_count > 0)
            {
                char* mem = reinterpret_cast<char*>(p);
                int index = (mem - c_buffer) / sizeof(Test);
                int flag = (mem - c_buffer) % sizeof(Test);

                if((0 == flag) && (0 <= index) && (index < c_count))
                {
                    c_map[index] = 0; // 标记为空闲
                    cout << "succeed to free memory: " << p << endl;
                }
            }
            else  // 对于默认在堆上对象的释放
            {
                free(p);
                cout << "free Heap memory: " << p << endl;
            }
        }
        // 函数返回后，编译器自动生成调用析构函数的代码
    }
};

unsigned int Test::c_count = 0;
char* Test::c_buffer = NULL;
char* Test::c_map = NULL;

int main()
{
    // 默认行为，new在堆空间创建对象
    cout << "===== Default Befavior =====" << endl;

    Test* pt = new Test;
    delete pt;

    cout << "===== Test Single Object =====" << endl;

    char buffer[3] = {0};
    // 指定new在栈上分配对象（最多3个对象）
    // Test内没有虚函数，没有成员变量，所以sizeof(Test) == 1
    // 空的类也有1Byte内存空间用来占位，以此作实例化对象的区分的
    Test::setMemorySource(buffer, sizeof(buffer));

    pt = new Test; //分配在栈上
    delete pt;

    cout << "===== Test Object Array =====" << endl;

    Test* pa[5] = {0};

    // 分配5个对象，但只有前3个会成功，后面两个返回NULL
    for(int i=0; i<5; i++)
    {
        pa[i] = new Test;
        cout << "pa[" << i << "] = " << pa[i] << endl;
    }

    for(int i=0; i<5; i++)
    {
        cout << "delete " << pa[i] << endl;
        delete pa[i];
    }

    return 0;
}
/* 运行结果
===== Default Befavior =====
allocate in Heap memory: 0x30b1180
Test()
~Test()
free Heap memory: 0x30b1180
===== Test Single Object =====
success to allocate memory: 0x61fe81
Test()
~Test()
succeed to free memory: 0x61fe81
===== Test Object Array =====
success to allocate memory: 0x61fe81
Test()
pa[0] = 0x61fe81
success to allocate memory: 0x61fe82
Test()
pa[1] = 0x61fe82
success to allocate memory: 0x61fe83
Test()
pa[2] = 0x61fe83
pa[3] = 0
pa[4] = 0
delete 0x61fe81
~Test()
succeed to free memory: 0x61fe81
delete 0x61fe82
~Test()
succeed to free memory: 0x61fe82
delete 0x61fe83
~Test()
succeed to free memory: 0x61fe83
delete 0
delete 0
*/
