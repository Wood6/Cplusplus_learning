// set_terminate() 设置 自定义结束函数
#include <iostream>
#include <exception>
#include <cstdlib>     // linux g++ for exit(1)

using namespace std;

void my_terminate()
{
    cout << "void my_terminate()" << endl;
    // 调用exit会进行一些清理工作(如调用全局对象或静态局部变量的析构函数来进行清理)
    exit(1);
}

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
    set_terminate(my_terminate);

    // 如果是局部变量，异常发生时析构函数不会被调用，因为，当异常发生后，会先执行
    // my_terminate()结束函数，而该函数内调用的exit函数只会清理全局变量不清理局部变量
    static Test st;

    throw 1;

    return 0;
}
/* 运行结果
** Windows下QtCreator5.9.6编译结果
Test()
void my_terminate()
~Test()

** Linux g++ 运行结果
Test()
void my_terminate()
~Test()
*/
