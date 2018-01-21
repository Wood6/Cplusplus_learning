// 函数重载不能和函数默认参数一起作用同一个函数
#include <stdio.h>

int func(int a, int b, int c = 0)
{
    return a * b * c;
}

int func(int a, int b)
{
    return a + b;
}

int main()
{
    // 根据匹配原则：通过函数名找到两个候选函数
    // 并尝试先通过精确匹配会找到func(int,int)
    // 但这时并不会停止匹配，而是会尝试用默认参数去匹配
    // 所以会找到另一个func，即func(int,int,int = 0),因此
    // 出现了二义性，编译器直接报错。
    int c = func(1, 2);

    return 0;
}
/*
error: call of overloaded 'func(int, int)' is ambiguous
     int c = func(1, 2);
                      ^
*/
