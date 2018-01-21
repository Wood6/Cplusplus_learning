// const与宏
#include <stdio.h>

void f()
{
    // 宏由预编译器处理（文本替换），其后面的宏起作用
    #define a 3
    const int b = 4;          // 编译器处理,有作用域检查
}

void g()
{
    printf("a = %d\n", a);    // 合法，只要是宏定义之后都可以使用
    // printf("b = %d\n", b); // 非法b的作用域仅限于f函数
}

int main()
{
    const int A = 1;
    const int B = 2;
    int array[A + B] = {0};   // C++中合法，因为A、B都是常量。
                              // 而C语言的const本质还是变量，这样数组大小就
                              // 得到运行期才能确定所以C语言中必定报错,数组大
                              // 小必须在编译期就确定,所以数组大小必须是常量

    int i = 0;

    for(i=0;i<(A + B); i++)
    {
        printf("array[%d] = %d\n", i, array[i]);
    }

    f();
    g();    // printf("a = %d\n", 3);

    return 0;
}
/*
array[0] = 0
array[1] = 0
array[2] = 0
a = 3
*/
