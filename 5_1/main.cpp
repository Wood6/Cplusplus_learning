// const引用 和 const修饰变量
#include <stdio.h>

void Example()
{
    printf("Example:\n");

    int a = 4;
    const int& b = a;   // 变量a的别名，const让变量b具有只读属性
    int* p = (int*)&b;  // &b就是变量a的地址

    //b = 5;            // 非法，因为用const修饰的引用，其代表的变量是只读的

    *p = 5;             // 合法，修改变量a的值

    printf("a = %d\n", a);  // 5;
    printf("b = %d\n", b);  // 5
}

void Demo()
{
    printf("Demo:\n");

    // const引用
    const int& c = 1; // 引用本应是变量的别名,一般常量是不分配内存的。当编译器
                      // 看到该行时,会为常量1分配内存,并让c作为这段空间的别名

    int* p = (int*)&c;

    //c = 5;          // 非法，因为const修饰，c是只读的

    *p = 5;           // 合法，通过指针访问内存

    printf("c = %d\n", c); // 5

    printf("\n", c);       // 5

    // const修饰变量变量放进符号表:注意与const引用的区别
    const int a = 1;
    p = (int*)&a;     // 遇到&a才为常量分配内存

    //a = 5;          // 非法，因为const修饰，a是只读的

    *p = 5;           // 合法，通过指针访问内存

    printf("a = %d\n", a);  // 1，编译器看到a直接从符号表读其值1
    printf("*p = %d\n",*p); // 5
}

int main()
{
    Example();

    printf("\n");

    Demo();

    return 0;
}
/*
Example：
a = 5
b = 5

Demo:
c = 5

a = 1
*p = 5
*/
