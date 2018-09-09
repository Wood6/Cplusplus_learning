// 自定义类类型重新解释异常示例
#include <iostream>
#include <string>

using namespace std;

class Base
{
};

class Exception : public Base
{
private:
    int m_id;
    string m_desc;

public:
    Exception(int id, string desc) : m_id(id), m_desc(desc)
    {
    }

    int id() const   // 考虑const Exception对象时，函数加const
    {
        return m_id;
    }

    string desc() const
    {
        return m_desc;
    }
};


/*
    假设：当前的函数是第三方库中的函数。因此，我们无法修改源代码

    函数名： void func(int i)
    抛出异常的类型：int
                        -1 ==> 参数异常
                        -2 ==> 运行异常
                        -3 ==> 超时异常
*/
void func(int i)
{
    if(i < 0)
    {
        throw -1;
    }
    if(i > 100)
    {
        throw -2;
    }
    if(i = 11)
    {
        throw -3;
    }

    // 正常运行时
    cout << "Call func(int i)" << endl;
}

// 以下是我们的私有库，当中使用到了第3方的库，这里
// 需要将第3方库的异常类型统一成我们的异常信息格式
void MyFunc(int i)
{
    try
    {
        func(i);
    }
    catch(int i)
    {
        switch(i)
        {
        case -1:
            throw Exception(-1, "Invalid Parameter");
            break;
        case -2:
            throw Exception(-2, "Runtime Exception");
            break;
        case -3:
            throw Exception(-3, "Timeout Exception");
            break;
        }
    }
}

int main()
{
    try
    {
        MyFunc(11);
    }
    catch(const Exception& e)    // 注意使用引用以防止拷贝
    {
        cout << "Exception info: " << endl;
        cout << "  ID          : " << e.id() << endl;
        cout << "  Description : " << e.desc() << endl;
    }
    catch(const Base& e)         // 父类异常放下部
    {
        cout << "catch(...)" << endl;
    }

    return 0;
}
/* 运行结果
Exception info:
  ID          : -3
  Description : Timeout Exception
*/
