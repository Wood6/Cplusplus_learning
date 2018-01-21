#include <stdio.h>

struct TRef
{
    char* before; // 4字节
    char& ref;    // 4字节,本质指针常量,分配4字节的空间 ==〉char* const ref;
    char* after;  // 4字节
};

int main()
{
    char a = 'a';
    char& b = a;
    char c ='c';

    TRef r = {&a, b, &c};  // 结构体赋值的一种方式

    printf("sizeof(r) = %d\n", sizeof(r));               // 12
    printf("sizeof(r.before) = %d\n", sizeof(r.before)); // 4
    printf("sizeof(r.after)  = %d\n", sizeof(r.after));  // 4

    // after和before相差8个字节，中间隔了个b引用所占用的空间
    printf("&r.before = %p\n", &r.before); // 0060FE9C
    printf("&r.after  = %p\n", &r.after);  // 0060FEA4

    return 0;
}
/*
sizeof(r) = 12
sizeof(r.before) = 4
sizeof(r.after)  = 4
&r.before = 0060FE9C
&r.after  = 0060FEA4
*/
