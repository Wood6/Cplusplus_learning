// 类型转换函数（不同类类型间的转换）
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

    // error: 't' has incomplete type
    // 因为只有t类型到这句时还只有前置声明,没有完整定义
    // 所以这里对t只能用引用或者指针，而不能用变量
    //explicit Value(Test t) {}
    explicit Value(Test& t) {}    // 转换构造
};

class Test
{
private:
    int m_i;

public:
    Test(int i = 0) : m_i(i) {}

    operator Value()   // 类型转换函数
    {
        Value ret;

        return ret;
    }
};

int main()
{
    Test t1(1);
    Value v1(5);

    v1 = t1;

    // 如果Value类中的转换构造函数不加explicit，这会造成Test类的类型
    // 转换函数与Value类的转换构造函数的冲突。因为编译器看到这行时
    // 会出现两种理解：
    // 1、Value v1(t),调用的是Value类的转换构造函数
    // 2、也可以理解成Value v1 = t1.operator Value();调用的是Test类的
    // 类型转换函数，出现了二义性。
    // 因此加上explicit后会阻止第1种可能
    // 最后，等价于第2种，所以结果会输出："operator Value()"
    // Value v1 = static_cast<Value>(t1);   //相当于value v1(t);

    return 0;
}

