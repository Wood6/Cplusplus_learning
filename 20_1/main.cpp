// 成员初始化顺序问题？
#include <stdio.h>

class Value
{
private:
    int i;

public:
    Value(int v)
    {
        i = v;
        printf("v = %d\n", v);
    }

    int getI() {return i;}
};

class Test
{
private:
    Value v3;
    Value v1;
    Value v2;

public:
    // 初始化顺序只与声明顺序有关，与初始化列表次序无关
    // 即初始化顺序为：m2,m3,m1。最后才是调用构造函数
    Test():v1(1), v2(2), v3(3)   // 成员变量的初始化
    {
        printf("Test::Test()\n");
    }
};

int main()
{
    Test t1;

    return 0;
}
/* 运行结果
v = 3
v = 1
v = 2
Test::Test()
*/
