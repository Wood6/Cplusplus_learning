// 优化：普通变量用const_cast<>去掉const属性再改变
// 因为mutable一般在工程中是被禁用的，这里优化
#include <iostream>

using namespace std;

class Test
{
private:
    int m_value;
    int m_count;   // 统计m_value被使用的次数，就用普通变量

public:
    Test(int value = 0) : m_value(value), m_count(0) {}

    // const成员函数目的是让普通对象和const对象都可以访问
    int getValue() const  // 注意，是const成员函数
    {
        // const_cast<>去掉cosnt类对象的成员变量的const属性
        const_cast<int&>(m_count) += 1;
        return m_value;
    }

    void setValue(int value)
    {
        m_count += 1;
        m_value = value;
    }

    int getCount() const
    {
        return m_count;
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
