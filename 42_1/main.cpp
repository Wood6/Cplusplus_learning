// 类型转换函数（类类型转换为普通类型）
#include <iostream>

using namespace std;

class Test
{
private:
    int m_i;

public:
    Test(int i = 0) : m_i(i) {}  // 转换构造函数

    operator int ()              // 类型转换函数
    {
        return m_i;
    }

    int getMi() {return m_i;}
};

int main()
{
    Test t1(100);

    cout << "t1.m_i = " << t1.getMi() << endl;

    // t1对象是Test类型，会调用转为int的类型转换函数
    // 即隐式调用类型转换函数，等价于int i = t.operator int();
    int i = t1;

    cout << "i = " << i << endl;

    return 0;
}
/* 运行结果
t1.m_i = 100
i = 100
*/
