// 另类的异常写法
#include <iostream>
#include <string>

using namespace std;

// 异常声明：
// throw(int, char)表示该函数可能抛出int和char两种类型的异常
// throw() 表示该函数不抛出异常
int func(int i) throw(int, char)
{
    if((0 < i) && (i <= 10))
    {
        return (i + i);
    }
    else if((10 < i) && (i <= 20))
    {
        throw 0;      // 抛出int型，合法。因为符合异常声明
    }
    else if((20 < i) && (i <= 30))
    {
        throw 'a';    // 抛出char型，合法。因为符合异常声明
    }
    else
    {
        throw "test"; // 但除了上述声明的都不行，那会程序崩溃
    }
}

void test(int i) try
{
    cout << "func(i) = " << func(i) << endl;
}
catch(int i)
{
    cout << "Exception catch(int i) :" << i << endl;
}
catch(char i)
{
    cout << "Exception catch(char i) :" << i << endl;
}
catch(...)
{
    cout << "Exception catch(...) :" << endl;
}

int main()
{
    test(5);

    test(15);

    test(25);

    test(35);

    return 0;
}
/* 运行结果
** Windows下qtCreator直接编译报错
 main.cpp:34: error: redeclaration of 'int i' [-fpermissive] catch(int i)
 main.cpp:38: error: redeclaration of 'char i' [-fpermissive] catch(char i)

** linux g++ 编译运行结果
** test(35)抛出的异常与声明的不符，运行时崩溃
func(i) = 10
Exception catch(int i) :0
Exception catch(char i) :a
terminate called after throwing an instance of 'char const*'
Aborted (core dumped)
*/
