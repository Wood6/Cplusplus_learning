// 多参数函数模板示例,特别注意返回值的类型
#include <iostream>

using namespace std;

template <typename T1, typename T2, typename T3>
T1 Add(T2 a, T3 b)
{
    return static_cast<T1>(a + b);
}

int main()
{
    //错误,模板参数中有返回值,返回值不能隐式推导,所以至少得显示指定返回值类型
    //int sum0 = Add(0.22, 0.29);

    //T1 = int, T2 = char, T3 = double
    //从左向右指定类型，这里只指定返回值，其余自动推导
    int sum1 = Add<int>('a', 0.29);

    //T1 = double, T2 = float, T3 = double
    //从左向右指定类型,这只指定返回值和add函数的第1个参数,第2个参数自动推导
    double sum2 = Add<double, float>(0.22, 0.29);

    //T1 = float, T2 = float, T3 = float
    //3个类型都显式指定
    float sum3 = Add<float, float, float>(0.22, 0.29);

    cout << "sum1 = " << sum1 << endl;
    cout << "sum2 = " << sum2 << endl;
    cout << "sum3 = " << sum3 << endl;

    return 0;
}
/* 运行结果
sum1 = 0
sum2 = 0.51
sum3 = 0.51
*/
