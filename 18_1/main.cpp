// 根据传参自动调用对应的构造函数
#include <stdio.h>

class Test
{
public:
    // 不带参的构造函数
    Test()
    {
        printf("Test()\n");
    }

    // 带参的构造函数
    Test(int v)
    {
        printf("Test(int v),v = %d\n", v);
    }
};

int main()
{
    Test t;         // 调用Test();
    Test t1(1);     // 调用Test(int v)
    Test t2 = 2;    // 调用Test(int v)

    int i(100);     // C++添加的普遍变量初始化方式,C报Error
    printf("i = %d\n", i);

    return 0;
}
/* 运行结果
Test()
Test(int v),v = 1
Test(int v),v = 2
i = 100
*/
