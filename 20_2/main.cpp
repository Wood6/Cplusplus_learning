// 探索1
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
    Value v2;

public:
    Test() {}
};

int main()
{
    Test t1;  // t1的构造函数体内没有显示构造其成员变量v1、v2
              // 但在生成t1这个对象时，会默认调用一次对应的构造函数

    return 0;
}
/* 运行结果
Value(int v),v = 1
Value()
*/
