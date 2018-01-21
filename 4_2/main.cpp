// 引用初探
#include <stdio.h>

int main()
{
    int a = 4;
    int& b = a;     // b为a的别名

    b = 5;          // 操作b就是操作a

    printf("a = %d\n", a);   // 5
    printf("b = %d\n", b);   // 5

    printf("&a = %p\n", &a);
    printf("&b = %p\n", &b); // &b等于&a

    // C++中的三目运算符
    int m = 1;
    int n = 2;

    printf("m = %d, n = %d\n", m, n);

    (m < n ? m : n) = 3;   // ?后的m、n都是变量，返回的是引用，
                           // 将3赋值给一个变量的引用，是合法的


    //(m < n ? m : 2) = 3; // ?后的操作数2为常量，将返回的是值，
                           // 从语义看，要将3赋值给2，是非法的

    printf("m = %d, n = %d\n", m, n);

    // 在C语言中，可通过其返回的是值的特点，可以通过如下方式来修改m或n
    *(m < n ?&m : &n) = 4; // 返回m，n的地址，再通过地址给变量赋值

    printf("m = %d, n = %d\n", m, n);

    return 0;
}
/*
 a = 5
 b = 5
 &a = 0060FEA8
 &b = 0060FEA8
 m = 1, n = 2
 m = 3, n = 2
 m = 3, n = 4
*/
