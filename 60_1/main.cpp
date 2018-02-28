// 最高效方法求 1+2+3+...+N的值
#include <iostream>

using namespace std;

template < int N >
class Sum
{
public:
    static const int value = Sum<N-1>::value + N;
    // 注意以上语句采用递归定义，即当调用Sum<N>::VALUE时，编译器认为其值等于
    // Sum<N-1>::VALUE + N;于是就出现了递归，直至Sum<1>时会找到后面特化的
    // 类模定义，因那里Sum<1>::VALUE=1，于是递归结束。注意，在这过程中，会依次
    // 产生Sum<100>、Sum<99>、...、Sum<1>等100个类，而每个类里面都有一个静态
    // 成员变量VALUE值，因其位于不同的类中,本质上在静态数据中会开辟100多个
    // int型空间来存储这些变量。编译器会进行优化,把中间这些不用的类给丢弃,最后
    // 保存最终的结果Sum<N>::value，即内存中只有一个静态VALUE变量的值。
};

template <>
class Sum <1>
{
public:
    static const int value = 1;
    // 以上语句声明和定义在一起，并对VALUE进行了初始化。这是合法的
    // 1. 如果只有单独的static int VALUE为什么不能直接初始化？
    //    因为C++里声明和定义是分开的，当编译器看到那样的语句时会认为这是声
    //    明，并没有定义，也就是空间还没分配好。所以也就不能初始化。
    // 2. 如果只有const int VALUE为什么也不能直接初始化？
    //    这也是同样的道理，这里的VALUE属于对象，而对象要使用时才分配空间，而
    //    在这里是无法分配空间的。
    // 3. static const int VALUE = 1;为什么这样的语句合法？
    //    当这两种的结合，其意义就跟一般的全局常量差不多，这种情况的const变量
    //    会被放入符号表，并给初始化为1
};

int main()
{
    cout << "1+2+3+...+10 = " << Sum<10>::value << endl;

    cout << "1+2+3+...+100 = " << Sum<100>::value << endl;
    // 实际上1+2+3+...+100就是类Sum<100>的成员value的值
    // 而这个value被static const修饰，是个常量，所以必须在编译期就确定
    // 都不需要运行就确定了结果，自然效率是最高的

    return 0;
}
/* 运行结果
1+2+3+...+10 = 55
1+2+3+...+100 = 5050
*/
