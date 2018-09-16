// 函数抛出的异常不在异常声明列表中会咋样？
#include <iostream>

using namespace std;

// 抛出规格说明之外的异常
void func() throw(int)  // 指明该函数可能抛出一个int型的异常
{
    cout << "func()" << endl;

    throw 'c';          // 抛出的却是字符型异常！
}

int main()
{
    try
    {
        func();
    }
    catch(int)
    {
        cout << "catch(int)" << endl;
    }
    catch(char)
    {
        cout << "catch(char)" << endl;
    }

    return 0;
}
/* 运行结果：
** Windows 下qtCreator5.9.6编译运行结果
func()

This application has requested the Runtime to terminate it in an unusual way.
Please contact the application's support team for more information.
terminate called after throwing an instance of 'char'

** linux g++ 编译运行结果
func()
terminate called after throwing an instance of 'char'
Aborted (core dumped)
*/
