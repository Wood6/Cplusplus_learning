// main.cpp 是个C++工程
// 该文件的编译  g++ main.cpp add.o
#include <stdio.h>
#include "add.h"

int main()
{
    int ret = add(1, 2);

    printf("ret = %d\n",ret);  // 3

    return 0;
}
/*
ret = 3
*/
