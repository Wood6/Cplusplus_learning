// 局部对象的构造顺序
#include <stdio.h>

class Test
{
private:
    int i;

public:
    Test()
    {
        i = 0;
        printf("Test::Test()\n");
    }

    Test(int v) : i(v)
    {
        printf("Test::Test(int v),v = %d\n", v);
    }

    Test(const Test& obj)
    {
        i = obj.i;
        printf("Test(const Test& obj)\n");
    }

    int getI() {return i;}
};

int main()
{
    int i = 0;
    Test t1 = i;

    while(i<3)
    {
        // 注意：t2的作用域只在这个大括号内
        // 所以，每执行1次，构造一次t2
        Test t2 = ++i;
    }
goto Labe;     // 因跳转，所以下列的t3/t4不会被构造
    if( i < 4 )
    {
        Test t3 = t1; // Test(const Test& obj) 但因goto,该对象不会被构造
    }
    else
    {
        Test t4(100);
    }
Labe:
    // goto容易打乱程序执行流,譬如下面语句就是因为有了goto语句就error了
    // 也正因为此，所以工程中一般都明确规定禁止使用 goto 语句
    // error: 't3' was not declared in this scope
    // printf("t3.i = %d\n",t3.getI());

    return 0;
}
/* 运行结果
Test::Test(int v),v = 0
Test::Test(int v),v = 1
Test::Test(int v),v = 2
Test::Test(int v),v = 3
*/
