// 类模板示例
#include <iostream>

using namespace std;

template < typename T>
class Operator
{
public:
    T add(T a, T b)
    {
        return a + b;
    }

    T minus(T a, T b)
    {
        return a - b;
    }

    T multiply(T a, T b)
    {
        return a * b;
    }

    T divide(T a, T b)
    {
        return a/b;  // 示例就没有对除数为0进行异常处理
    }
};

// 利用全局函数重载string类的减法操作符
string operator - (string& l, string& r)
{
    return l + " - " + r;
}

int main()
{
    Operator<int> op1;   // 必须指定类型（如int），这里产生一个类

    cout << op1.add(3, 4) << endl;
    cout << op1.minus(3, 4) << endl;

    Operator<string> op2; // 类模板须指定类型（如string）,将产生另一个类
    // 对add函数的T进行类型替换，编译出二进制代码
    cout << op2.add("Wood", "Jim") << endl;
    // 不对string类重载 - 操作符,这里将编译报错,证明类模板也是有两次编译
    cout << op2.minus("Wood", "Jim") << endl;

    return 0;
}
/* 运行结果
7
-1
WoodJim
Wood - Jim
*/
