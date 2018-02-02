// 定义一个初始化普遍函数
#include <stdio.h>

class Test
{
private:
    int mi;

    // 正确的做法，提供一个用来初始化的普通函数
    void init(int v)
    {
        mi = v;
    }

public:
    // 带参构造函数
    Test(int v)
    {
        init(v);
        printf("Test::Test(int v),v = %d\n",v);
    }

    // 不带参构造函数
    Test()
    {
        // 调用普通的初始化函数，而不是带参的构造函数Test(int v);
        init(0);
    }

    Test(const Test& obj)
    {
        mi = obj.mi;
        printf("Test::Test(const Test& obj)\n");
    }

    ~Test()
    {
        printf("Test::~Test() mi = %d\n", mi);
    }

    void print()
    {
        printf("mi = %d\n", mi);
    }
};

int main()
{
    Test t1;

    t1.print();  // 预期的0
    printf("-----------------------\n");

    Test t2 = 2;

    t2.print();
    printf("-----------------------\n");

    return 0;
}
/* 运行结果
mi = 0
-----------------------
Test::Test(int v),v = 2
mi = 2
-----------------------
Test::~Test() mi = 2
Test::~Test() mi = 0
*/
