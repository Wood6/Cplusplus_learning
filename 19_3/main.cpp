// 深拷贝来解决浅拷贝的问题
#include <stdio.h>

class Test
{
private:
    int i;
    int *p;

public:
    // 无参构造函数
    Test()
    {
        i = 0;
        p = NULL;

        printf("Test()\n");
    }
    // 带参构造函数
    Test(int value)
    {
        i = value + 100;
        p = new int;
        *p = value;

        printf("Test(int value)\n");
    }

    // 拷贝构造函数(深拷贝)
    Test(const Test& obj)
    {
        i = obj.i;

        p = new int;
        *p = *obj.p;   // 深拷贝,物理内存地址里面值的拷贝（逻辑状态）

        printf("Test(const Test& obj)\n");
    }

    void free()
    {
        if(p)
        {
            delete p;
        }
    }

    int getI() {return i;}
    int* getP() {return p;}

};

int main()
{
    Test t1(1);

    Test t2 = t1; // 调用拷贝构造函数

    printf("t1.i = %d, t1.p = %p\n", t1.getI(), t1.getP());
    printf("t2.i = %d, t2.p = %p\n", t2.getI(), t2.getP());  // 地址与上不同

    printf("t1.i = %d, *t1.p = %d\n", t1.getI(), *t1.getP());
    printf("t2.i = %d, *t2.p = %d\n", t2.getI(), *t2.getP());  // 逻辑状态相同

    t1.free();
    t2.free();     // 这里第二次各自delete各自的地址

    return 0;
}
/* 运行结果 Windows的QtCreator执行
Test(int value)
Test(const Test& obj)
t1.i = 101, t1.p = 006819C8
t2.i = 101, t2.p = 006819D8
t1.i = 101, *t1.p = 1
t2.i = 101, *t2.p = 1

linux 执行结果 执行也没有出现错误了
Test(int value)
Test(const Test& obj)
t1.i = 101, t1.p = 0x8815008
t2.i = 101, t2.p = 0x8815018
t1.i = 101, *t1.p = 1
t2.i = 101, *t2.p = 1
*/

