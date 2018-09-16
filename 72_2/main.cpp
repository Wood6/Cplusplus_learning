// set_unexpected()设置自定义的异常函数
#include <iostream>
#include <exception>
#include <cstdlib>

using namespace std;

void my_unexpected()
{
    cout << "void my_unexpected()" << endl;

    // exit(1);
    throw 1; // 再次抛出的异常与触发函数(func)声明的中异常规格类型
             // 一致，则程序恢复执行，所以会被catch(int)捕获
}

// 抛出规格说明之外的异常
void func() throw(int)  // 指明该函数可能抛出一个int型的异常
{
    cout << "func()" << endl;

    throw 'c';          // 抛出的却是字符型异常！
}

int main()
{
    set_unexpected(my_unexpected);

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
void my_unexpected()
catch(int)

** linux g++ 编译运行结果
func()
void my_unexpected()
catch(int)

** Windows下 VS2017 编译运行结果
** （可见VS没遵循标准C++规范，即调用unexpected而是直接在main中捕获异常了）
** 由此可见编译器不同，异常规格说明是有不同的行为的，有的编译器不一定完全遵循
** C++规范
func()
catch(char)
*/
