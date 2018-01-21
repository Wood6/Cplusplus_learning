// C到C++的升级一
#include <stdio.h>

int g_v;
// int g_v;     // 重复定义全局变量，C是合法的，会映射到同一个地址
// 但C++是非法的

int main()
{

    printf("Begin...\n");

    int c = 0;   // C++中变量可以随时定义
                 // 而不必像C那样必须在作用域开始的位置

    for (int i=1; i<=3;i++)  // 在for循环内定义变量i和j
    {
        for(int j=1; j<=3; j++)
        {
            c += i * j;
        }
    }

    printf("c = %d\n", c);

    register int a = 0;      // register变量

    printf("&a = %p\n", &a); // 对a取地址,C++会将a放到内存而不是寄存器
                             // 但在C语言中&a是非法的。

    printf("End...\n");

    return 0;
}
/* 运行结果：
Begin...
c = 36
&a = 0060FEA0
End...
* /
