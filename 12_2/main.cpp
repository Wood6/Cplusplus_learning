// C++为什么不支持引用数组？
#include <stdio.h>

int a = 1;

struct st
{
    int& x;
    int& y;
    int& z;
};

int main()
{
    int b = 2;
    int* p = new int(3);

    // 将st各成员初始化为变量a,b,*p等内存的引用
    st s = {a, b, *p};

    printf("s.x = %d\n", s.x);  // 变量a的地址，全局区
    printf("s.y = %d\n", s.y);  // 变量b的地址，栈
    printf("s.z = %d\n", s.z);  // new出来的地址，堆

    printf("&s.x = %p\n", &s.x);
    printf("&s.y = %p\n", &s.y);
    printf("&s.z = %p\n", &s.z);

    // error: declaration of 'array' as array of references
    // int& array[] = {a, b, *p};

    // 在C++中没有“引用数组”的概念，请看如下分析
    // 对于数组而言，其内存是连续分布的。当进行&array[1] - &array[0]
    // 表示前后两个元素的地址相差的值，应等于sizeof(元素的类型)。但如
    // 果允许定义“引用数组”的话，如下面语句，&array[1]表示第1个元素的地址，
    // 即元素b的地址(&b)，而&array[0]表示&a，显然这两个地址是不连续的。所以
    // int& array[]={a, b, *pc};//这样的定义是错误的，C++里不支持“引用数组”

    return 0;
}
/*
s.x = 1
s.y = 2
s.z = 3
&s.x = 00403008
&s.y = 0028FEB8
&s.z = 005E19C8
*/
