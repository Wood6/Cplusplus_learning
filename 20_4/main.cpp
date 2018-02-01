// 探索3
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
    Test():v1(3)
    {
        v1 = Value(2);
    }
};

int main()
{
    Test t1;  // t1的构造函数显示构造其成员变量v1、初始化列表也显示初始化
              // 构造两次，其中自动调用的构造函数没有执行
              // 顺序：初始化列表调用的构造函数 -> 构造函数体中的构造

    // 结论：
    // 初始化列表和自动调用的构造只会执行一个,有初始化列表时会覆盖默认自动调用
    // 的构造；构造函数体中的构造在最后执行

    // 所以，最标准的做法就是成员变量时类时用初始化列表初始化,同时不要在构造函
    // 数体中手工调用构造函数来初始化，这样保证既能成功初始化又能不多次初始化


    return 0;
}
/* 运行结果
Value(int v),v = 3
Value(int v),v = 2
*/
