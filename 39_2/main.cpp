// 重载逗号操作符
#include <iostream>

using namespace std;

class Test
{
private:
    int m_i;

public:
    Test(int i = 0) : m_i(i) {}

    int getMi() {return m_i;}
};

// 利用全局变量来重载逗号操作符
// 1、参数必须有一个为类类型（基本类型不需要重载操作符）
// 2、返回值必须为引用（可以赋值）
Test& operator , (const Test& l, const Test& r)
{
    return const_cast<Test&>(r);  // 强制转换，去掉const属性
}

// 特意用这个函数来显示出逗号操作符执行的顺序
Test& func(Test& obj)
{
    cout << "func(): obj.m_i = " << obj.getMi() << endl;

    return obj;
}

int main()
{
    Test t1(1);
    Test t2(2);

    // 因重载操作符的本质相当于函数调用，所以
    // 相当于Test t3 = operator,(func(t1), func(t2));  //函数调用！
    // 当进入函数体，参数的值必须被计算，而两个参数func(t1)和func(t2)
    // 的计算次序是不确定的，这就不符合从左至右的原生语义了
    Test t3 = (func(t1), func(t2));

    // 虽然结果是正确的，但中间的计算过程与
    // 逗号表达式原义从左向右计算要求有可能不一致
    cout << "t3.m_i = " << t3.getMi() << endl;

    return 0;
}
/* 运行结果
func(): obj.m_i = 2
func(): obj.m_i = 1
t3.m_i = 2
*/
