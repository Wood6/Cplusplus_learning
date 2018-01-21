// 函数重载的本质
#include <stdio.h>

int add(int a, int b)         // 函数类型：int(int,int)
{
    return a + b;
}

int add(int a, int b, int c)  // 函数类型：int(int, int, int)
{
    return a + b + c;
}

int main()
{
    // 下面报错,因为函数的重载，在编译的结果中找不到这样的函数名
    // printf("%p\n", add);

    // 下面也报错，因为不存在bdd这个符号
    // printf("%p\n",(int (*)(int, int,int))bdd);

    // 以下两个printf显示出来，重载函数的本质是相互独立
    // 的两个函数，其函数地址是不同的。
    printf("%p\n",(int (*)(int, int))add);    // 在add前面加上类型，编译器就会
                                              // 就根据重载函数的命名规则找到
                                              // 被编译后的真正的函数名

    printf("%p\n",(int (*)(int, int,int))add);// 在add前面加上类型，编译器就会
                                              // 就根据重载函数的命名规则找到
                                              // 被编译后的真正的函数名
    return 0;
}
/*
00401630
0040163D
*/
