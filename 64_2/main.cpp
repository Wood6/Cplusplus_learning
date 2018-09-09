// 异常类型是严格匹配的
#include <iostream>
#include <string>

using namespace std;

// 函数内处理异常
void Demo1()
{
    try
    {
        throw '1';
    }
    catch(char& c)
    {
        cout << "catch(char& c):" << c << endl;
    }
    catch(short& c)
    {
        cout << "catch(short& c):" << c << endl;
    }
    catch(double& c)
    {
        cout << "catch(double& c):" << c << endl;
    }
    catch(int& c)
    {
        cout << "catch(int& c):" << c << endl;
    }
    catch(...)     // 所有异常，必须放在所有的catch之后，因为是自上而下匹配的
    {
        cout << "catch(...):" << endl;
    }
}

// 抛出异常，由调用函数处理
void Demo2()
{
    throw "liyao test";  // const char* 类型
}

void Demo3()
{
    throw string("liyao test");  // string 类型
}

int main()
{
    Demo1();

    try
    {
        Demo2();
    }
    catch(char*& s)
    {
        cout << "catch(char*& s):" << s << endl;
    }
    catch(const char*& s)
    {
        cout << "catch(const char*& s):" << s << endl;
    }
    catch(string& s)
    {
        cout << "catch(string& s):" << s << endl;
    }
    catch(...)
    {
        cout << "catch(...):" << endl;
    }

    return 0;
}
/* 运行结果
catch(char& c):1
catch(const char*& s):liyao test
*/
