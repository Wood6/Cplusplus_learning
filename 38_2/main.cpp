// 重载逻辑操作符 || 和 &&
#include <iostream>

using namespace std;

/*
//error: 'bool operator||(int, int)' must have an argument of class or enumerated type
bool operator || (int l, int r)
{
    return l || r;
}
bool operator && (int l, int r)
{
    return l && r;
}
*/

class Test
{
private:
    int m_i;

public:
    Test(int i = 0) : m_i(i) {}

    int getMi() const {return m_i;}
};

// 利用全局函数重载||操作符
bool operator || (const Test& l, const Test& r)
{
    return l.getMi() || r.getMi();
}

bool operator && (const Test& l, const Test& r)
{
    return l.getMi() && r.getMi();
}

const Test& func(const Test& obj)
{
    cout << "func(Test obj),obj.m_i = " << obj.getMi() << endl;

    return obj;
}

int main()
{
    Test t0(0);
    Test t1(1);

    // 输出：（分析：相当于函数调用，进入函数体，参数的值必须被计算出来）
    // 短路法则完全失效，重载||改变了其原来应短路的语义
    // 相当于函数调用operator&&(func(t0), func(t1))
    if( func(t0) || func(1) )
    {
        cout << "|| Result : true" << endl;
    }
    else
    {
        cout << "|| Result : false" << endl;
    }

    if( func(t0) && func(1) )
    {
        cout << "&& Result : true" << endl;
    }
    else
    {
        cout << "&& Result : false" << endl;
    }

    return 0;
}
/* 运行结果
func(Test obj),obj.m_i = 1
func(Test obj),obj.m_i = 0
|| Result : true
func(Test obj),obj.m_i = 1
func(Test obj),obj.m_i = 0
&& Result : false
*/
