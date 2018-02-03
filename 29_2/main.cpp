// 函数重载
#include <stdio.h>

class Test
{
private:
    int m_i;

public:
    Test() : m_i(0)
    {
        printf("Test::Test()\n");
    }

    Test(int v) : m_i(v)
    {
        printf("Test::Test(int v)\n");
    }

    Test(const Test& obj)
    {
        m_i = obj.m_i;
        printf("Test::Test(const Test& obj)\n");
    }

    void func()
    {
        printf("Test::func()\n");
    }

    static void func(int v)
    {
        printf("Test::func(int v)\n");
    }
};

void func()
{
    printf("func()\n");
}

void func(int v)
{
    printf("func(int v)\n");
}

int main()
{
    //全局函数func和func(1)构成重载关系
    func();
    func(1);
    printf("----------------------------\n");

    //构造函数之间构成重载关系
    //Test t1();    // 没有创建对象 ???
    Test t1;
    Test t2(2);
    Test t3(t1);    // 若t1是这样创建 Test t1();报错
    printf("----------------------------\n");

    //全局函数与静态成员函数不构成重载（因为作用域不同）
    func(1);
    Test::func(1);
    printf("----------------------------\n");

    //全局函数与类的普通成员函数也不构成重载（作用域不同）
    func();
    t1.func();
    printf("----------------------------\n");

    //类中普通成员与静态成员构成重载关系（作用域相同，且符合重载条件）
    t1.func();
    Test::func(1);

    return 0;
}
/* 运行结果
func()
func(int v)
----------------------------
Test::Test()
Test::Test(int v)
Test::Test(const Test& obj)
----------------------------
func(int v)
Test::func(int v)
----------------------------
func()
Test::func()
----------------------------
Test::func()
Test::func(int v)
*/
