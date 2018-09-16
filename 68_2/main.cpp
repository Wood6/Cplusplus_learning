// 用 typename/class 声明是类型而不是变量以消除人为解读的二义性
#include <iostream>

int a = 1;

class Test_1
{
public:
    // 静态成员变量TS（实质已经是一个常量了）
    static const int TS = 2;
};

class Test_2
{
public:
    // 内部类TS
    struct TS
    {
       int value;
    };
};

// class 常用来声明类类型，若T只是普通类型，这样就觉得能见名思意
template < class T >
void test_class()
{
    // typename 说明其紧跟的标识符T::TS是类型名而不是变量
    typename T::TS * a;

    // 也可以用class来修饰。但这样会让人疑惑，因为class一般用于声明
    // 类的，但这里用法是用来定义指针类型而不是类类型,做不到顾名思议
    // class T::TS * a;    // 这样也是合法，与上句同样效果
}

int main()
{
    //test_class<Test_1>();   // 编译不过，error: no type named 'TS' in 'class Test_1'
    test_class<Test_2>();     // 编译通过，说明编译声明类型为T::Ts的指针变量a

    return 0;
}
