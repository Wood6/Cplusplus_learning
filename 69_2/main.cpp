// 优化：利用指针或指针常量来实现
// 因为mutable一般在工程中是被禁用的，这里优化
#include <iostream>

using namespace std;

class Test
{
private:
    int m_value;
    // m_pCount可以是一般的成员变量，而不一定非得是const成员变量！
    int * const m_pCount;   // 统计m_value被使用的次数

public:
    Test(int value = 0) : m_value(value), m_pCount(new int(0)) {}

    // const成员函数目的是让普通对象和const对象都可以访问
    int getValue() const  // 注意，是const成员函数
    {
        *m_pCount += 1;
        return m_value;
    }

    void setValue(int value)
    {
        *m_pCount += 1;
        m_value = value;
    }

    int getCount() const
    {
        return *m_pCount;
    }
};

int main()
{
    Test t;               // 普通对象
    t.setValue(200);      // 第1次访问t.m_value

    cout << "t.m_value = " << t.getValue() << endl; // 第2次访问t.m_value
    cout << "t.m_count = " << t.getCount() << endl; // t.m_count = 2;

    const Test ct(100);   // const对象

    cout << "ct.m_value = " << ct.getValue() << endl; // 第1次访问ct.m_value
    cout << "ct.m_count = " << ct.getCount() << endl; // ct.m_count = 1;

    return 0;
}
/* 运行结果
t.m_value = 200
t.m_count = 2
ct.m_value = 100
ct.m_count = 1
*/
