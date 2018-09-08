// C++新式 类型转换
#include <stdio.h>

void static_cast_demo()
{
    int i = 0x12345;
    char c = 'c';
    int *pi = &i;
    char *pc = &c;

    c = static_cast<char>(i);   // 基本类型

    // 基本类型的指针间，非法
    // error: invalid static_cast from type 'int*' to type 'char*'
    // pc = static_cast<char*>(pi);
}

void const_cast_demo()
{
    // 用常量初始化引用，要分配内存。故i为变量，因加const而成只读变量
    const int &i = 1;  // i为引用--》只读变量，说明i不能做为左值而己
    // i = 2;          // error: assignment of read-only reference 'i'

    int &j = const_cast<int&>(i);  // 转为普通引用，j就是i的别名
    // i = 2;          // error: assignment of read-only reference 'i'
                       // 上面：不是去掉变量i的只读属性，而是对i的一个副本去掉只读属性，将其赋给引用j
                       // 所以const_cast<int&>后i依旧为只读变量

    j = 100;

    printf("j = %d\n", j);
    printf("i = %d\n", i);

    const int x = 2;                   // x为常量，放进常量表中
    // x = 5;                          // error: assignment of read-only variable 'x'
                                       // 说明若有对x作为左值等用时，使用的是内存中的x，并且由于是const修饰，还是只读的
    int &y = const_cast<int&>(x);      // 这样也会为x分配内存
    int *px = const_cast<int*>(&x);    // 同上

    // error: invalid const_cast from type 'const int' to type 'int*'
    // int *px = const_cast<int*>(x);

    // const_cast 目标类型只能是指针或者引用
    // error: invalid use of const_cast with type 'int', which is not a pointer, reference, nor a pointer-to-data-member type
    // int z = const_cast<int>(x);

    y = 200;

    printf("x = %d\n", x);             // 常量表中的x
    printf("y = %d\n", y);             // 内存中的x
    printf("*px = %d\n", *px);         // 内存中的x

    *px = 400;

    printf("x = %d\n", x);             // 常量表中的x
    printf("y = %d\n", y);
    printf("*px = %d\n", *px);

    printf("&x = %p\n", &x);  // 这三个内存地址都是相同的，都是内存中x的地址
    printf("&y = %p\n", &y);
    printf("px = %p\n", px);
}

void reinterpret_cast_demo()
{
    int i = 0;
    char c = 'c';
    int *pi = &i;
    char *pc = &c;

    pc = reinterpret_cast<char*>(pi);  // ok，指针间
    pi = reinterpret_cast<int*>(pc);   // ok，指针间
    pi = reinterpret_cast<int*>(i);    // ok，整数与指针间
    i = reinterpret_cast<int>(pi);     // oops，基本类型间转换，要用static_cast

    // 基本类型间转换，要用static_cast
    // error: invalid cast from type 'char' to type 'int'
    // i = reinterpret_cast<int>(c);
}

void dynamic_cast_demo()
{
    int i = 0;
    int *pi = &i;

    // 目标类型应为类的指针或引用
    // error: cannot dynamic_cast 'pi' (of type 'int*') to type 'char*' (target is not pointer or reference to class)
    // char *pc = dynamic_cast<char*>(pi);
}

int main()
{
    static_cast_demo();
    printf("------------------------------\n");
    const_cast_demo();
    printf("------------------------------\n");
    reinterpret_cast_demo();
    printf("------------------------------\n");
    dynamic_cast_demo();

    return 0;
}
/* 运行结果
------------------------------
j = 100
i = 100
x = 2
y = 200
*px = 200
x = 2
y = 400
*px = 400
&x = 0060FE78
&y = 0060FE78
px = 0060FE78
------------------------------
------------------------------
*/
