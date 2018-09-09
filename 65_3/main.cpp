// try-catch中构造函数中抛出异常导致内存泄漏的场景
#include <iostream>

using namespace std;

class Test
{
private:
    int* p;

public:
    Test()
    {
        cout<< "Test()" << endl;
        p= new int[5];

        throw 10; // 抛出异常，构造函数非正常结束
    }

    ~Test()
    {
        cout <<"~Test()" << endl;
        delete[] p;
    }
};

int main()
{
    try
    {
        Test t; // t未完成构造就出异常，就跳到catch语句去，
                // 注意t的作用域为try的{}，因没被执行完，所以
                // 还没调用析构函数就跳到catch作用域中—内存泄漏
    }
    catch (int e)
    {
        cout <<"Catch:"<<e << endl;
    }

    return 0;
}
/* 运行结果
Test()
Catch:10
*/
