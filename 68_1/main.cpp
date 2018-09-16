// 泛型编程使用class的二义性
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

template < class T >  // 旧式写法，用class而不是typename定义模板
void test_class()
{
    // 以下语句人为的看可以有两种解读方法，出现了二义性
    T::TS * a;

    // 1. 通过泛型T内部的类类型定义指针变量a.
    //    (大部分人的解读方式，因为没有赋值运算，所以不会第一想到是乘法运算)
    // 2. 使用泛型T内部的静态成员变量TS与全局变量a进行乘法操作
    //    (编译器的实质解读方式，与上面人为认定的相反，这就是说的二义性问题)

    // 默认下，编译器会按2的方式解读，而不是我们期望的1的方式
    // 如何解决以上的二义性问题呢？引入新的关键字typename，将它放在类型前面
    // 以说明其紧跟的标识符是类型名而不是变量，形式如下
    // typename T::TS* a;
    // T::TS前用typename修饰，明确地表示其为一个类类型
    // 也可以用class来修饰。但这样会让人疑惑，因为class
    // 一般用于声明类的，但这里用法给人感觉好象是用来
    // 定义指针类型而不是类类型，所以建议用新的typename关键字。
    // 索性，把template <class T>也改为template <typename T>
    // 这样更彻底。即，在定义模板时完全抛弃class关键字

}

int main()
{
    test_class<Test_1>();   // 编译通过，说明编译器是按2的方式去解读。
    //test_class<Test_2>(); // 编译不过,说明编译器是仍是按1的方式去解读，报如下错误
                            // error: dependent-name 'T:: TS' is parsed as a non-type,
                            // but instantiation yields a type T::TS * a;

    return 0;
}
