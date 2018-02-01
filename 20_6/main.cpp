// const成员变量是只读变量
#include <stdio.h>

class Test
{
private:
    const int i = 1;

public:
    Test(int v):i(v)
    {
        printf("Test::Test()\n");
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
    Test t(5);

    printf("t.i = %d\n",t.getI());

    t.setI(100);
    printf("t.i = %d\n",t.getI());

    return 0;
}
/* 运行结果
Test::Test()
t.i = 5
t.i = 100
*/
