// 始化动态内存
#include <stdio.h>

int main()
{
    int* pi = new int(1);    // 开辟1个int型空间，并初始化为1
    int* pArray = new int[1];     // 申请一个数组，与前一行含义不同,无初始化
    int* pArray2 = new int[1]();  // 申请数组并且初始化为0

    // error: parenthesized initializer in array new [-fpermissive]
    // int* pArray3 = new int[1](1);

    float* pf = new float(2.0f);
    char* pc = new char('c');

    printf("*pi = %d\n", *pi); //1
    printf("*pf = %f\n", *pf); //2.000000
    printf("*pc = %c\n", *pc); //c

    printf("pArray[0] = %d\n", pArray[0]);    // 随机值
    printf("pArray2[0] = %d\n", pArray2[0]);  // 0


    delete pi;
    delete pf;
    delete pc;

    delete []pArray;
    delete []pArray2;

    return 0;
}
/* 运行结果
*pi = 1
*pf = 2.000000
*pc = c
pArray[0] = 50294688
pArray2[0] = 0
*/
