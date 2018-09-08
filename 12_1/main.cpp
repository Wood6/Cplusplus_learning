// const相关3个典型问题分析
#include <stdio.h>

int main()
{
    // 实验1：初始化变量的类型与const引用类型相同时
    const int i = 1;
    const int& ri = i; // x与rx的类型相同，所以rx为只读变量,不能作为左值
                       // 但本质上还是变量,引用x的内存值（而不是符号表中的值）

    int& j = const_cast<int&>(ri);   // 转换为普通引用
    int* p = const_cast<int*>(&ri);  // 转换为指针变量

    // error: assignment of read-only variable 'i'
    // i是一个只读常量进入符号表,但也会在内存中分配一个空间,里面值为1
    // 要访问这个内存空间,只能通过i的引用或者指针
    // i = 2;

    // error: assignment of read-only reference 'ri'
    // ri = 3;

    j = 6;       // *p = 6;结果也一样
                 // j与ri都引用了i的内存值

    printf("i = %d\n", i);   //1，从符号表中读取
    printf("ri = %d\n", ri); //6，从内存表中读取
    printf("j = %d\n", j);   //6，从符号表中读取

    printf("&i = %p\n", &i);
    printf("&ri = %p\n", &ri);
    printf("&j = %p\n", &j);  //i、ri、j地址相同
    printf("----------------------\n");

    // 实验2：初始化变量的类型与引用类型不同时
    char c = 'c';
    char& rc = c;
    const int& x = c;  // c与x类型不一致,则会生成一个新的变量,
                       // 然后x引用这个新的变量

    rc = 'a';

    printf("c = %c\n", c);     // a
    printf("rc = %c\n", rc);   // a
    printf("x = %c\n", x);     // c

    printf("&c = %p\n", &c);
    printf("&rc = %p\n", &rc); // rc与c的地址相同
    printf("&x = %p\n", &x);   // x是一个新的地址
    printf("----------------------\n");

    // 实验3：volatlie
    volatile const int k = 2;   // volatile修饰，会为k分配内存
    int *pk = const_cast<int*>(&k); // 因k被const修饰，不能作为左值

    *pk = 6;  // 因k不能作为左值，用来代替k = 6;这样的写法

    printf("k = %d\n", k);   // 6，volatile指示k得从内存中读取
    printf("&k = %p\n", &k);

    const int z = k;  // 用变量初始化const常量，z不会进入符号表，z分配内存
    int& rz = const_cast<int&>(z);

    rz = 10;

    printf("z = %d\n", z);      // 10，说明z没进入符号表
    printf("&rz = %p\n", &rz);  // z的地址

    return 0;
}
/* 运行结果
i = 1
ri = 6
j = 6
&i = 0028FE9C
&ri = 0028FE9C
&j = 0028FE9C
----------------------
c = a
rc = a
x = c
&c = 0028FE9B
&rc = 0028FE9B
&x = 0028FEA0
----------------------
k = 6
&k = 0028FE94
z = 10
&rz = 0028FE90
*/
