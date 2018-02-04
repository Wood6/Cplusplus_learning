// main.cpp
#include <stdio.h>
#include "Complex.h"

int main()
{
    Complex c1(1, 2);
    Complex c2(3, 6);

    Complex c3 = c1 + c2;
    Complex c4 = c2 - c1;
    Complex c5 = c1 * c2;
    Complex c6 = c2 / c1;

    printf("c3 = (%lf, %lf)\n", c3.getA(), c3.getB());
    printf("c4 = (%lf, %lf)\n", c4.getA(), c4.getB());
    printf("c5 = (%lf, %lf)\n", c5.getA(), c5.getB());
    printf("c6 = (%lf, %lf)\n", c6.getA(), c6.getB());
    printf("\n");

    Complex c7(1, 2);
    printf("c7 == c1 ==> %d\n", c7 == c1);
    printf("c7 != c2 ==> %d\n", c7 == c2);
    printf("\n");

    c3 = c2 = c1;  // 赋值操作赋返回值是引用，可以连续赋值
    printf("c1 = (%lf, %lf)\n", c1.getA(), c1.getB());
    printf("c2 = (%lf, %lf)\n", c2.getA(), c2.getB());
    printf("c3 = (%lf, %lf)\n", c3.getA(), c3.getB());
    printf("\n");

    (c3 = c2) = c1;
    printf("c1 = (%lf, %lf)\n", c1.getA(), c1.getB());
    printf("c2 = (%lf, %lf)\n", c2.getA(), c2.getB());
    printf("c3 = (%lf, %lf)\n", c3.getA(), c3.getB());

    return 0;
}
/* 运行结果
c3 = (4.000000, 8.000000)
c4 = (2.000000, 4.000000)
c5 = (-9.000000, 0.000000)
c6 = (3.000000, -1.800000)

c7 == c1 ==> 1
c7 != c2 ==> 0

c1 = (1.000000, 2.000000)
c2 = (1.000000, 2.000000)
c3 = (1.000000, 2.000000)

c1 = (1.000000, 2.000000)
c2 = (1.000000, 2.000000)
c3 = (1.000000, 2.000000)
*/
