//  C/C++中的const
#include <stdio.h>

const int x = 5;  // C/C++ 都是将x放在只读存储区
                  // 但是C语言中本质还是将其视为一个变量,
                  // 只不过这个变量用指针都不能改,因为被放在只读存储区了
                  // C++将其视为一个常量

int main()
{
    const int a = 0;          // C语言中会为变量a分配内存
                              // C++会将标识符a和值0放入常量表中
    int* p = (int*)&a;        // C++中遇到&，为a分配内存

    printf("Begin...\n");

    *p = 5;                   // C语言是直接变量a被改为5
                              // C++是分配的内存中的值被改为5,常量表中0值没变

    printf("a = %d\n", a);    // C语言会输出内存中的5.
                              // C++中会从符号表（而不是内存）中取值,所以为0.

    printf("*p = %d\n", *p);  // C/C++都是 *p = 5
    printf("&a = %p\n", &a);  // C/C++都是 *p = 5
    printf("p = %p\n", p);    // C/C++都是 *p = 5

    printf("End...\n");

    int array[x] = {0};       // C++可以，说明x是个常量
                              // C报error: variable-sized object may not be initialized
    int *px = (int*)&x;       // 但对于这个全局变量，C++遇到&没有另外分配内存地址
    printf("x = %p\n", &x);
    printf("px = %p\n", px);  // px变量放的地址就是x在只读存储区的地址
    printf("*px = %d\n", *px);
    // x = 1               // 程序会异常结束
    // *px = 1;            // 程序也会异常结束,因为const修饰全局变量放在只读存储区
                           // 对于const修饰全局变量这个，C/C++ 相同
    return 0;
}
/* C语言环境运行结果     C++环境运行结果
   Begin...            Begin...
   a = 5               a = 0
   *p = 5              *p = 5
   End...              End...
   x = 00404064
   px = 00404064
   *px = 0
*/
