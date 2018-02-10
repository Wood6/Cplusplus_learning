// ++ 操作符重载示例
#include <stdio.h>

using namespace std;

class Test
{
private:
    int m_i;

public:
    Test(int i = 0) : m_i(i) {}

    int getMi() {return m_i;}

    // 前置++（如++i)，原生语义先自增后取值
    // 返回值为引用，无参！
    Test& operator ++()
    {
        m_i++;         // 先自增

        return *this;  // 后取值
    }

    // 后置++（如i++），原生语义先取值后自然
    // 返回值为对象，int型参数作占位符，以区别前置和后置++
    Test operator ++ (int)
    {
        Test ret(m_i);  // 先取值

        m_i++;          // 后自增

        return ret;     // 注意，这里返回自增之前的对象状态
    }

    //全局重载 ++ 操作符（在可以的情况下尽量不要使用全局重载,破坏了C++的封装性）
    //friend Test& operator ++ (Test& obj);
    //friend Test operator ++ (Test& obj, int);
};

/*
Test& operator ++ (Test& obj)
{
    obj.m_i++;

    return obj;
}

Test operator ++ (Test& obj, int)
{
    Test ret(obj.m_i);

    obj.m_i++;

    return ret;
}
*/

int main()
{
    Test t1(1);

    printf("t1++, t1.m_i = %d\n", (t1++).getMi());  // 0

    t1 = 1;

    printf("++t1, t1.m_i = %d\n", (++t1).getMi());  // 1

    return 0;
}
/* 运行结果
t1++, t1.m_i = 1
++t1, t1.m_i = 2
*/
