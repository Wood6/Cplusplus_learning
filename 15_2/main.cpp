// 类成员的作用域（对内）
#include <stdio.h>

int i = 1;

struct Test
{
private:
    int i;

public:
    int j;

    int getI()
    {
        i = 2;

        return i;
    }
};

int main()
{
    int i = 3;

    Test test;

    test.j = 4;

    printf("main : i = %d\n", i);
    printf("::i = %d\n", ::i);
    printf("test.j = %d\n", test.j);
    printf("test.getI() = %d\n", test.getI());
    // printf("test.i = %d\n", test.i);  // error: 'int Test::i' is private

    return 0;
}
/* 运行结果
main : i = 3
::i = 1
test.j = 4
test.getI() = 2
*/
