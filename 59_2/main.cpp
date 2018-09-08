// 函数模板只能完全特化
#include <iostream>

using namespace std;

template < typename T>
bool Equal(T a, T b)
{
    cout << "bool Equal(T a, T b)" << endl;

    return a == b;
}

// 当比较相等的两个参数是浮点类类型时直接用 == 判断就不合适了，所以就得
// 将这种情况独立出来特殊处理，这就正好可以使用函数模板的特化了
// 函数模板的特化(必须完全特化)
template <>  // 因完全特化，这里没有泛型，参数列表为空
bool Equal<double>(double a, double b) // 函数名后面必须指定参数的具体类型（如double)
{
    cout << "bool Equal<double>(double a, double b)" << endl;

    const double delta = 0.000000000000000000001;
    double r = a - b;

    return (-delta < r) && ( r < delta );
}

// 函数重载
bool Equal(double a, double b)
{
    cout << "bool Equal(double a, double b)" << endl;

    const double delta = 0.000000000000000000001;
    double r = a - b;

    return ( -delta < r ) && ( r < delta );
}

int main()
{
    cout << Equal(1, 1) << endl << endl;      // 调用函数模板
    // 优先选择普通函数，然后特化模板，最后一般模板
    cout << Equal(0.000001, 0.000001) << endl << endl;
    // 调用特化的函数模板，因为<>表示只匹配函数模板，
    // 又因优先选择特化模板，故调用Equal<double>(double a, double b)
    cout << Equal<>(0.000001, 0.000001) << endl << endl;
    // 显式指定调用特化模板
    cout << Equal<double>(0.000001, 0.000001) << endl;

    return 0;
}
/* 运行结果
bool Equal(T a, T b)
1

bool Equal(double a, double b)
1

bool Equal<double>(double a, double b)
1

bool Equal<double>(double a, double b)
1
*/
