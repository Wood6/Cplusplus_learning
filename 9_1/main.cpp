// 函数重载 VS 函数指针 <== 严格匹配
#include <stdio.h>
#include <string.h>

int func(int x)
{
    return x;
}

int func(int a, int b)
{
    return a + b;
}

int func(char *s)
{
    return strlen(s);
}

typedef int (*PFUNC)(int);  // 声明函数指针
//typedef float (*PFUNC)(int);  // error,返回值不匹配

int main()
{
    int ret = 0;

    // 编译器将根据函数指针的类型去严格匹配对应的函数
    // 所以会找到int func(int);其他函数则匹配不成功
    PFUNC pFunc = func;
    ret = pFunc(1);

    printf("ret = %d\n",ret);

    return 0;
}
/*
ret = 1
*/
