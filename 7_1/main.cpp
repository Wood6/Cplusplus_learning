// 默认值在函数声明时提供不能在函数定义中提供
#include <stdio.h>

// 默认值只能在函数声明时提供
int mul(int x = 0);           // 参数x的默认值为0

int main()
{
    printf("%d\n", mul());    // 0，传入默认值0
    printf("%d\n", mul(-1));  // 1，传入-1
    printf("%d\n", mul(2));   // 4，传入2

    return 0;
}

int mul(int x)    //定义中，不能提供默认值，编译器会报错
{
    return x * x;
}
