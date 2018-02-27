// 函数重载遇上函数模板
#include <iostream>

using namespace std;

// 函数模板：找出两个数中最大数
template <typename T>
T Max(T a, T b)
{
    cout << "T Max(T a, T b)" << endl;
    return a > b ? a : b;
}

// 普通函数：两个数中的最大数
int Max(int a, int b)
{
    cout << "int Max(int a, int b)" << endl;
    return a > b ? a : b;
}

// 函数模板：找出三个数中最大数
template <typename T>
T Max(T a, T b, T c)
{
    cout << "T Max(T a, T b, T c)" << endl;
    return Max(Max(a, b), c);
}

int main()
{
    cout << Max(3, 4) << endl << endl;    // 优先调用普通函数
    cout << Max<>(3, 4) << endl << endl;  // 限制只能调用函数模板
    cout << Max(3, 4, 5) << endl << endl;
    cout << Max('a', 4) << endl << endl;  //普通成员函数int Max(int a, int b)
                                      //由于函数模板（只有一个参数类型T）,
                                      //本身不允许隐式转换,所以不会匹配函数模板

    return 0;
}
/* 运行结果
int Max(int a, int b)
4

T Max(T a, T b)
4

T Max(T a, T b, T c)
int Max(int a, int b)
int Max(int a, int b)
5

int Max(int a, int b)
97

*/
