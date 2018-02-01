// 浅拷贝易引发的问题
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

    // 拷贝构造函数(浅拷贝)
    Test(const Test& obj)
    {
        i = obj.i;
        p = obj.p;   // 浅拷贝,物理内存地址的拷贝

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
    printf("t2.i = %d, t2.p = %p\n", t2.getI(), t2.getP());  // 地址与上同

    t1.free();
    t2.free();     // 浅拷贝这里第二次delete同一个内存地址

    return 0;
}
/* 运行结果 Windows的QtCreator执行没出错
Test(int value)
Test(const Test& obj)
t1.i = 101, t1.p = 007C19C8
t2.i = 101, t2.p = 007C19C8

linux 执行结果 执行出现双重释放的error
Test(int value)
Test(const Test& obj)
t1.i = 101, t1.p = 0x9026008
t2.i = 101, t2.p = 0x9026008
*** glibc detected *** double free or corruption (fasttop): 0x09026008 ***
*/

