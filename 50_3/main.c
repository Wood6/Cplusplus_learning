// C工程，C语言模拟面向对象
#include <stdio.h>
#include "Class.h"

void run(Test* p)
{
    printf("%d\n", Test_add(p, 3));  // 多态
}

int main()
{
    Test* t1 = Test_Creat(1, 2);
    Child* c1 = Child_Creat(10, 11, 12);

    run(t1);
    run(c1);

    Test_free(t1);
    Test_free(c1);

    return 0;
}
/* 运行结果
6
15
*/
