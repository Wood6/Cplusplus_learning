// 引用变量占多少内存空间？
#include <stdio.h>

struct TRef
{
    char& r;// 引用的本质是指针常量,因此会分配4字节的空间,相当于char* const r
};

int main()
{
    char c = 'c';
    char& rc = c;
    TRef ref = {c};

    printf("sizeof(char&) = %d\n",sizeof(char&));// 1，char型变量别名,大小为1
    printf("sizeof(rc) = %d\n",sizeof(rc));      // 1，变量c的别名,大小为1

    printf("sizeof(TRef) = %d\n",sizeof(TRef));  // 4，结构体内有个引用
                                                 // 本质为指针,占4字节
    printf("sizeof(ref.r)= %d\n",sizeof(ref.r)); // 1,char型变量的别名,大小为1

    return 0;
}
/*
sizeof(char&) = 1
sizeof(rc) = 1
sizeof(TRef) = 4
sizeof(ref.r)= 1
*/
