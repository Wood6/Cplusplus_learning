// main.cpp文件
// 面向对象的编程体现
#include <stdio.h>
#include "Operator.h"

int main()
{
    Operator op;
    double r = 0;

    op.setOperator('/');
    op.setParameter(81, 9);

    if( op.result(r) )
    {
        printf("r = %lf\n", r);
    }
    else
    {
        printf("Calculate error!\n");
    }

    return 0;
}
/* 运行结果
r = 9.000000
*/
