// typename 诞生
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

// 索性直接在泛型参数T时就用关键字typename，这样就
// 直接消除解读的二义性了，typename就是这样正式诞生了
template < typename T >
void test_class()
{
    typename T::TS * a;   // 这里的tyname还是不能少,上面是声明 T 为类型名
                          // 这里是声明 T::TS 为类型名，两者不一样
                          // ps: 本以为上面用typename下面就直接可以不用的...
}

int main()
{
    //test_class<Test_1>();   // 编译不过，error: no type named 'TS' in 'class Test_1'
    test_class<Test_2>();     // 编译通过，说明编译声明类型为T::Ts的指针变量a

    return 0;
}
