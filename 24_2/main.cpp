// 类中const的应用
#include <stdio.h>

class Test
{
private:
    int m_i;

public:
    Test()
    {
        m_i = 0;
        printf("Test::Test()\n");
    }

    Test(int v) : m_i(v)
    {
        printf("Test::Test(int v)\n");
    }


    Test(const Test& obj)
    {
        //obj是const对象（的引用），函数内只能调用const成员函数
        //obj.print();
        m_i = obj.m_i;
        printf("Test::Test(const Test& obj)\n");
    }

    void print()
    {
        printf("Test::print(),m_i = %d\n", m_i);
    }

    void show() const
    {
        printf("Test::show() const,m_i = %d\n", m_i);
    }

    int getMi() const
    {
        return m_i;
        printf("Test::getMi() const\n");
    }

    void setMi(int v) const
    {
        // const成员函数不能改变成员变量的值！
        // error: assignment of member 'Test::m_i' in read-only object
        // m_i = v;

        int* p = const_cast<int*>(&m_i);
        *p = v;
        printf("Test::setMi(int v) const,v = %d\n", v);
    }

    void setMi(int v)
    {
        m_i = v;
        printf("Test::setMi(int v),v = %d\n", v);
    }
};

int main()
{
    const Test t1(1);   // const对象

    //t1.print();  // 错误，const对象不能调用非const成员函数
    t1.show();     // 正确，const对象只能调用const成员函数
    t1.setMi(10);  // 正确，const对象只能调用const成员函数
    t1.show();

    printf("--------------------------------\n");

    Test t2(2);
    t2.show();     // 非const对象可以调用const成员函数
    t2.setMi(10);
    t2.print();

    return 0;
}
/* 运行结果
Test::Test(int v)
Test::show() const,m_i = 1
Test::setMi(int v) const,v = 10
Test::show() const,m_i = 1
--------------------------------
Test::Test(int v)
Test::show() const,m_i = 2
Test::setMi(int v),v = 10
Test::print(),m_i = 10

 ** setMi(int v) cosnt 中间接改成员变量的结果 **
Test::Test(int v)
Test::show() const,m_i = 1
Test::setMi(int v) const,v = 10
Test::show() const,m_i = 10      // 成功更改
--------------------------------
Test::Test(int v)
Test::show() const,m_i = 2
Test::setMi(int v),v = 10
Test::print(),m_i = 10
*/
