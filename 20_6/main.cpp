// const成员变量是只读变量
#include <stdio.h>

class Test
{
private:
    const int i = 1;       // 声明时初始化

public:
    Test()
    {
        printf("Test::Test()\n");
    }

    Test(int v):i(v)
    {
        printf("Test(int v):i(v)\n");
    }

    int getI() {return i;}

    void setI(int v)
    {
        // i = v;  // error: assignment of read-only member 'Test::i'
        // 说明ci是个只读变量，可以通过指针修改内存值
        int *p = const_cast<int*>(&i);
        *p = v;
    }
};

int main()
{
    Test t;

    printf("t.i = %d\n",t.getI());           // 初始化的 1

    Test t1(5);

    printf("t.i = %d\n",t1.getI());

    t1.setI(100);
    printf("t.i = %d\n",t1.getI());

    return 0;
}
/* 运行结果
Test::Test()
t.i = 1
Test(int v):i(v)
t.i = 5
t.i = 100
*/
