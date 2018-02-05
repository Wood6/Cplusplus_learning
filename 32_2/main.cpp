// C兼容库 和 C++标准库中的c兼容库
/*
// C++编译商提供的C兼容库
//（既不是C++标准库提供的,也不是C语言库文件，而是一种兼容库）
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
*/

// C++标准库提供的C兼容库
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

int main()
{
    char* p = (char*)malloc(100);

    strcpy(p, "Wood is learning CplusCplus!");

    printf("%s\n",p);

    printf("%lf\n", sqrt(9));   // sqrt() 返回值是double类型

    free(p);

    return 0;
}
/* 运行结果
Wood is learning CplusCplus!
3.000000
*/
