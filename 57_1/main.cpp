// 函数模板隐式类型转换问题！
#include <iostream>

using namespace std;

// 模版函数，求两个数的最大值
template <typename T>
T Max(T a, T b)
{
    return a > b ? a : b;
}

int main()
{
    int i = 3;
    int j = 4;

    // 自动类型推导:T==>int
    cout << Max(i, j) << endl;

    //错误，两个参数类型不同，函数模板不允许隐式转换.
    //cout << Max('c', 100)<< endl;

    //正确，显式指定T为int类型，可将'c'隐式转为指定的int型
    cout << Max<int>('c', 100) << endl;

    return 0;
}
/* 运行结果
4
100
*/
