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
        mi = 0;
        printf("Test::Test()\n");
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

Test func()
{
    return Test(2);
}

int main()
{
    Test t1 = Test(1);  // ==> Test t = 1，临时对象被编译器给“优化”掉了
                        // 说明：如果不优化，该行代码的行为：调用Test(10)
                        // 将产生一个临时对象，并用这个对象去初始化t对象，会
                        // 先调用Test(int i)，再调用Test(const Test& t)


    t1.print();
    printf("-----------------------\n");

    Test a = func();   // ==> Test a = Test(2);==>Test a = 2;
                        // 说明：如果不优化，该行代码的行为：在func内部调用
                        // Test(2)，此时func函数中将产生一个临时对象,此时
                        // (Test(int i)被调用，然后按值返回，会调用拷贝构
                        // 造函数Test(const Test&)，此时在main函数中会产
                        // 生第2个临时对象来接收func的返回值，最后用第2个临
                        // 时对象去初始化a对象,将再次调用Test(const Test& t)

    a.print();
    printf("-----------------------\n");

    return 0;
}
/* Windows中QtCreator默认编译后运行结果（优化后）
Test::Test(int v),v = 1
mi = 1
-----------------------
Test::Test(int v),v = 2
mi = 2
-----------------------
Test::~Test() mi = 2
Test::~Test() mi = 1

 ** Windows中QtCreator在.pro禁止优化编译后运行结果 **
Test::Test(int v),v = 1
Test::Test(const Test& obj)
Test::~Test() mi = 1
mi = 1
-----------------------
Test::Test(int v),v = 2
Test::Test(const Test& obj)
Test::~Test() mi = 2
Test::Test(const Test& obj)
Test::~Test() mi = 2
mi = 2
-----------------------
Test::~Test() mi = 2
Test::~Test() mi = 1
*/

