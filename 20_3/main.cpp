// 探索2
#include <stdio.h>

class Value
{
private:
    int i;

public:
    Value()
    {
        printf("Value()\n");
    }
    Value(int v)
    {
        i = v;
        printf("Value(int v),v = %d\n", v);
    }
};

class Test
{
private:
    Value v1 = 1;

public:
    Test()
    {
        v1 = Value(2);
    }
};

int main()
{
    Test t1;  // t1的构造函数体内显示构造其成员变量v1,会构造两次
              // 顺序：自动调用构造函数执行 -> 构造函数体中的构造

    return 0;
}
/* 运行结果
Value(int v),v = 1
Value(int v),v = 2
*/
