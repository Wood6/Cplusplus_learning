// 布尔类型的使用
#include <stdio.h>

int main()
{
    bool b = false;
    int a = b;

    printf("sizeof(b) = %d\n", sizeof(b));   // 1
    printf("b = %d, a = %d\n", b, a);        // 0, 0

    b = 3;  // 编译器发现会bool型赋值非0，就会转化为1
    a = b;  // a为1

    printf("b = %d, a = %d\n",b, a);

    b = -5; // 非0，被转为1
    a = b;  // a为1

    printf("b = %d, a = %d\n",b, a);  // 1, 1

    a = 10;
    b = a;  // 非0，被转为1

    printf("a = %d, b = %d\n",a, b);  // 10, 1

    a = 0;
    b = a;  // 0

    printf("a = %d, b = %d\n",a, b);  // 0, 0

    return 0;
}
/*
sizeof(b) = 1
b = 0, a = 0
b = 1, a = 1
b = 1, a = 1
a = 10, b = 1
a = 0, b = 0
*/
