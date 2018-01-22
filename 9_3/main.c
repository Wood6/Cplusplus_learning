// main.c 是个c工程
// 编译方式： gcc main.c add.o

#include <stdio.h>
#include "add.h"

int main()
{
    int ret = add(1, 2);

    printf("ret = %d\n",ret);  // 3

    return 0;
}
/* 运行结果
ret = 3
*/
