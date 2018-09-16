// 析构函数中抛异常导致terminate的重复调用的场景
#include <iostream>
#include <exception>
#include <cstdlib>     // linux g++ for exit(1)

using namespace std;

void my_terminate()
{
    cout << "void my_terminate()" << endl;
    exit(1);   // exit会进行一些清理工作(全局对象或静态局部变量的析构函数来进行清理)

    //abort(); // abort直接退出程序，而不会进行清理操作
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
        throw 2;  // 在析构函数中抛异常
    }
};

int main()
{
    set_terminate(my_terminate);

    static Test st;

    throw 1;
    // 1、由于main没有处理这异常，会被传递到my_terminate去处理。
    // 所以第1次调用my_terminate函数。
    // 2、又因为my_terminate中调用了exit函数，而exit会进行一些清理工作。
    // 如调用t对象的析构函数，但析构中也抛出一个异常
    // 这将导致my_terminate被再次调用。这种重复调用terminate可能造成资源的
    // 重复释放，从而造成系统的不稳定。

    // 所以C++默认的terminate里面是调用abort()而不是exit(1)，
    // 就是避免上面场景的发生
    // 因为abort直接退出程序，而不会进行清理操作，自然就不会调用析构函数

    return 0;
}
/* 运行结果
** Windows下QtCreator5.9.6编译结果
Test()
void my_terminate()
~Test()
void my_terminate()   // 析构函数中抛异常，将导致my_terminate被重复调用

** Linux g++ 运行结果
Test()
void my_terminate()
~Test()
Aborted (core dumped)
*/
