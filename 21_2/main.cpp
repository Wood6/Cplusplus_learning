// 堆对象的构造顺序
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
    Test *p1 = new Test(0);

    while(++i<3)
    {
        // 注意：t2的作用域只在这个大括号内
        // 所以，每执行1次，构造一次t2
        new Test(i);
    }

    if( i < 4 )
    {
        new Test(*p1);   // 拷贝构造
    }
    else
    {
        new Test(100);
    }

    return 0;
}
/* 运行结果
Test::Test(int v),v = 0
Test::Test(int v),v = 1
Test::Test(int v),v = 2
Test(const Test& obj)
*/
