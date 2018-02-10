// 转换构造函数(将其他类型转换为当前类类型)
#include <iostream>

using namespace std;

class Test
{
private:
    int m_i;

public:
    Test() : m_i(0) {}
    explicit Test(int i): m_i(i) {} // 转换构造函数,将int类型转换为Test类类型

    Test& operator + (const Test& obj)
    {
        m_i += obj.m_i;

        return *this;
    }

    int getMi() {return m_i;}
};

int main()
{
    Test t1;

#if 0
    // 转换构造函数不加 explicit 修饰时的使用
    cout << "t1.m_i = " << t1.getMi() << endl;

    t1 = 5;   // 可以直接这样赋值，是不是很容易让人误解及产生隐患

    cout << "t1.m_i = " << t1.getMi() << endl;

    t1 = t1 + 10;  // 本意是t1 = t1 + Test(10)，但这样直接加个整数竟然也合法
                   // 原因就都是因为编译器会隐式调用 转换构造函数,将整形数转换
                   // 为一个Test类对象

    cout << "t1.m_i = " << t1.getMi() << endl;
#endif

    // 加上 explicit 修饰后就必须手工显示进行转换，上面的写法就都会报错了
    cout << "t1.m_i = " << t1.getMi() << endl;

    t1 = static_cast<Test>(5);

    // 相当于 t1 = Test(5); 原因：Test(int i)被explicit修饰，就是告诉编译
    // 器要阻止那种通过隐式调用该函数的行为发生。只有显式调用Test(int i)，
    // （或通过强制类型方式转换的）才允许调用这个函数来进行类型的转换。

    cout << "t1.m_i = " << t1.getMi() << endl;

    t1 = t1 + Test(10);

    cout << "t1.m_i = " << t1.getMi() << endl;

    return 0;
}
/* 运行结果
t1.m_i = 0
t1.m_i = 5
t1.m_i = 15
*/
