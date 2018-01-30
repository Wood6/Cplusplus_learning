// C++中的动态内存分配 new/new[]  delete/delete []
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 10;        // 栈空间
    int *p = new int;  // p保存堆上开辟空间的地址

    *p = i;
    *p = *p + 5;

    printf("&i = %p\n", &i);
    printf("p = %p\n", p);
    printf("*p = %d\n", *p);

    delete p;

    p = new int[10];  // p保存堆上开辟空间的地址

    for(int i=0; i<10; i++)
    {
        p[i] = i;
        printf("%d ", p[i]);
    }

    printf("\n");
    printf("p = %p\n", p);
    delete []p;

    return 0;
}
/* 运行结果
&i = 0060FEA4
p = 02F710C8
*p = 15
0 1 2 3 4 5 6 7 8 9
p = 02F710C8
*/
