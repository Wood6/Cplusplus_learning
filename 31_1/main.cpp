// main.cpp
#include <stdio.h>
#include "Complex.h"

int main()
{
#if 0
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
#endif

    Complex c4(4, 4);
    Complex reset(4, 4);
    Complex c5(0, 0);

    c5 = c4++;
    printf("c4++, c5 = (%lf, %lf)\n", c5.getA(), c5.getB());

    c4 = reset;
    c5 = ++c4;
    printf("++c4, c5 = (%lf, %lf)\n", c5.getA(), c5.getB());

    c4 = reset;
    c5 = c4--;
    printf("c4--, c5 = (%lf, %lf)\n", c5.getA(), c5.getB());

    c4 = reset;
    c5 = --c4;
    printf("--c4, c5 = (%lf, %lf)\n", c5.getA(), c5.getB());

    return 0;
}
/* 运行结果
c4++, c5 = (4.000000, 4.000000)
++c4, c5 = (5.000000, 5.000000)
c4--, c5 = (4.000000, 4.000000)
--c4, c5 = (3.000000, 3.000000)
*/
