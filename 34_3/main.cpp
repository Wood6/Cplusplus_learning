// 重载数组 [] 操作符
#include <iostream>

using namespace std;

class Test
{
private:
    int a[5];

public:
    // 重载数组操作符，能且只能一个参数
    // 返回值为引用，可以作为左值使用
    // 即Test t; t[1] = 2;
    int& operator [] (int i)
    {
        return a[i];
    }

    int& operator [] (const string& s)
    {
        if (s == "lst")
        {
            return a[0];
        }
        else if( s == "2nd")
        {
            return a[1];
        }
        else if( s == "3rd")
        {
            return a[2];
        }
        else if( s == "4th")
        {
            return a[3];
        }
        else if( s == "5th")
        {
            return a[4];
        }
        else
        {
            return a[0];
        }
    }

    int length()
    {
        return sizeof(a) / sizeof(*a);
    }
};

int main()
{
    Test t;

    for(int i=0; i<t.length(); i++)
    {
        // 通过下标方式访问对象，但本质上重载操作符
        // 是个函数，即t[i]是通过函数调用（而不是数组）来访问的
        t[i] = i;  // 操作符[]返回的是引用，可以作为左值
    }

    for(int i=0; i<t.length(); i++)
    {
        cout << t[i] << " ";
    }
    cout << endl;

    cout << t["5th"] << endl;  // 4，t["5th"],本质上是个函数调用
    cout << t["1st"] << endl;

    return 0;
}
/* 运行结果
0 1 2 3 4
4
0
*/
