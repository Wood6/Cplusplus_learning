// 改进25_1 不创建对象也能获得当前类对象的数目
#include <stdio.h>

class Test
{
private:
    static int c_count;

public:
    Test() { ++c_count; }
    ~Test() { --c_count; }

    static int getCount() { return c_count; }
};

int Test::c_count = 0;


int main()
{
    // 没有创建类也能获得对象的数目
    printf("c_count = %d\n", Test::getCount());

    Test t1;
    Test* pt2 = new Test;

    printf("c_count = %d\n", pt2->getCount());

    delete pt2;

    printf("c_count = %d\n", t1.getCount());

    return 0;
}
/* 运行结果
c_count = 0
c_count = 2
c_count = 1
*/
