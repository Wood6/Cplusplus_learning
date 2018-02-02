// 析构函数初探
#include <stdio.h>

class Test
{
private:
    int m_i;
public:
    Test(int v) : m_i(v)
    {
        printf("Test::Test(int v),m_i = %d\n", m_i);
    }

    // 析构函数在当前对象销毁时会被编译器自动调用
    ~Test()
    {
        printf("Test::~Test(),m_i = %d\n", m_i);
    }
};

int main()
{
    Test t1(1);

    Test* p = new Test(2);
    delete p;   // 堆上对象不会自动销毁,需要手动delete销毁,delete这个
                // 动作就是去销毁p所指向的堆内存空间上的东西,而这个东西
                // 是Test对象,这个时候Test的析构函数就编译器自动调用了

                // 局部变量t1在栈上 在main()退出时会被自动销毁

    return 0;
}
/* 运行结果
Test::Test(int v),m_i = 1
Test::Test(int v),m_i = 2
Test::~Test(),m_i = 2
Test::~Test(),m_i = 1
*/
