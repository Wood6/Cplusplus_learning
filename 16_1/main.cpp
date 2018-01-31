// struct/class 的默认访问级别
#include <stdio.h>

struct A
{
    // 默认访问级别为public
    int i;
    int getI()
    {
        return i;
    }
};

class B
{
    // 默认访问级别为private
    int i;
    int getI()
    {
        return i;
    }
};

int main()
{
    A a;
    B b;

    a.i = 4;
    printf("a.getI() = %d\n", a.getI());

    // b.i = 4;    // error: 'int B::i' is private
    // printf("b.getI() = %d\n", b.getI());  // error: 'int B::getI()' is private

    return 0;
}
/* 运算结果
a.getI() = 4
*/
