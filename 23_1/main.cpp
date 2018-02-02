// 临时对象的产生
#include <stdio.h>

class Test
{
private:
    int mi;

public:
    // 带参构造函数
    Test(int v) : mi(v)
    {
        printf("Test::Test(int v),v = %d\n",v);
    }

    // 不带参构造函数
    Test()
    {
        // 程序的意图是把Test当成普通函数来使用以达到对mi赋值的目的
        // 但直接调用构造函数，将会产生临时对象。所以Test(0)相当于
        // 对新的临时对象的mi赋初值为0，而不是对这个对象本身的mi赋
        // 值,但因为是临时对象，就这一条语句的生命期，这句一执行完就
        // 调用析构函数销毁了这个临时对象
        Test(0);
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

    t1.print();  // 随机值不是预期的0
    printf("-----------------------\n");

    Test t2 = 2;

    t2.print();
    printf("-----------------------\n");

    return 0;
}
/* 运行结果
Test::Test(int v),v = 0
Test::~Test() mi = 0
mi = 4200491
-----------------------
Test::Test(int v),v = 2
mi = 2
-----------------------
Test::~Test() mi = 2
Test::~Test() mi = 4200491
*/
