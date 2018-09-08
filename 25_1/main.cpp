// 统计某个类在程序中创建了多少个对象
#include <stdio.h>

class Test
{
private:
    static int c_count;

public:
    Test() { ++c_count; }
    ~Test() { --c_count; }

    void print()
    {
        printf("c_count = %d\n", c_count);
    }
};

// 使用前必须在类外给静态成员变量分配空间
// 表明要在全局区，而且只能在全局区分配空间
int Test::c_count = 0;

Test t1;   // c_count增加1

int main()
{
    //int Test::c_count = 0;  // 错误，试图在这里为静态成员分配空间

    Test t2;                 // c_count增加1
    Test* pt3 = new Test;    // c_count增加1

    // 等于1，表示c_count是在全局区分配空间，该变量不属于某个对象本身的。
    // 占1Byte的原因是用来占位的，以来区分对象实例化的
    printf("sizeof(Test) = %d, sizeof(t1) = %d\n", sizeof(Test), sizeof(t1));
    printf("sizeof(Test::c_count) = %d\n", sizeof(Test::c_count));

    // 错误，通过类名只能访问公有的static成员变量
    // error: 'int Test::c_count' is private
    //printf("c_count = %d\n", Test::c_count);

    pt3->print();  // 通过对象名访问static成员变量
    delete pt3;    // c_count减1
    t2.print();

    return 0;
}
/* 运行结果
sizeof(Test) = 1, sizeof(t1) = 1
sizeof(Test::c_count) = 4
c_count = 3
c_count = 2
*/
