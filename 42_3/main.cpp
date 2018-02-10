// toType()替代类型转换函数以抑制隐式转换
#include <iostream>

using namespace std;

// 前置声明
class Test;

class Value
{
private:
    int m_i;

public:
    Value(int i = 0) : m_i(i) {}  // 转换构造
    explicit Value(Test& t) {}    // 转换构造
};

class Test
{
private:
    int m_i;

public:
    Test(int i = 0) : m_i(i) {}
/*
    operator Value()   // 类型转换函数
    {
        Value ret;

        return ret;
    }
*/
    // 工程中常用普通成员函数替代类型转换函数,目的抑制
    // 编译器的隐式转换，这样就必须得手工显示调用才行
    Value toValue()
    {
        Value ret;

        return ret;
    }
};

int main()
{
    Test t1(1);
    Value v1(5);

    v1 = t1.toValue(); // Qt中就是用的这种方式

    return 0;
}
