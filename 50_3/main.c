// C工程，C语言模拟面向对象
#include <stdio.h>
#include "Class.h"

int main()
{
    Test* t1 = Test_Creat(1, 2);            // Test* t1 = new Test(1, 2);

    // 各函数调用中，传this指针:t1
    printf("m_i = %d\n", Test_getMi(t1));
    printf("m_j = %d\n", Test_getMj(t1));
    printf("t1.add(3) = %d\n", Test_add(t1, 3));

    //t1->m_i = 100;  //相当于私有变量，不能直接通过this指针(d)来访问

    return 0;
}
/* 运行结果
m_i = 1
m_j = 2
t1.add(3) = 5
*/
