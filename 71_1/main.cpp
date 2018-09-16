// 异常的最终处理（main函数中抛出异常测试）
#include <iostream>

using namespace std;

class Test
{
public:
    Test()
    {
        cout << "Test()" << endl;
    }

    ~Test()
    {
        cout << "~Test()" << endl;
    }
};

int main()
{
    static Test t;

    throw 1;

    return 0;
}
/* 运行结果
** Windows下QtCreator5.9.6编译结果
Test()

This application has requested the Runtime to terminate it in an unusual way.
Please contact the application's support team for more information.
terminate called after throwing an instance of 'int'

** Linux g++ 运行结果
Test()
terminate called after throwing an instance of 'int'
Aborted (core dumped)

** VS2017编译
然后弹出main.exe己停止工作的对话框
*/
