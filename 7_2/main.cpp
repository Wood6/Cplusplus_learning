#include <stdio.h>

// 默认参数必须从右向左提供，诸如
// int add(int x = 0,int y = 1,int z)是错误的
int add(int x, int y = 1, int z = 2);

int main()
{
    // 第2参数y使用了默认值，则后续的z也必须使用默认值
    // 诸如add(1, ,3);的调用是错的。
    printf("%d\n", add(0));        // 3， x = 0, y = 1, z = 2

    printf("%d\n", add(2, 3));     // 7， x = 2, y = 3, z = 2
    printf("%d\n", add(3, 2, 1));  // 6， x = 3, y = 2, z = 1

    return 0;
}

int add(int x, int y, int z)
{
    return x + y + z;
}
