// 函数操作符 () 重载
#include <iostream>

using namespace std;

class Fib
{
private:
    int a0;
    int a1;

public:
    Fib() : a0(0), a1(1) {}
    Fib(int n)   // 设置初始化
    {
        a0 = 0;  // 先将初始化a0,a1
        a1 = 1;

        for(int i=2; i<=n; i++)
        {
            int t =a1;

            a1 = a0 +a1;
            a0 = t;
        }
    }

    // operator()为函数名,后面的()为参数列表，这里为空
    int operator () ()
    {
        int ret = a1;

        a1 = a0 + a1;
        a0 = ret;

        return ret;
    }
};

int main()
{
    Fib fib;
    for(int i=0; i<10; i++)
    {
        // fib是个对象，但因重载操作符()，可以用这个对象
        // 名调用函数（重载操作符本质上是个函数），这种方
        // 式就像函数名调用函数一样直观！
        cout << fib() << " ";
    }
    cout << endl;

    for(int i=0; i<5; i++)
    {
        cout << fib() << " ";  // 从上次结果开始
    }
    cout << endl;

    Fib fib2(10);//从第10个元素开始输出

    for(int i=0; i<5;i++)
    {
        cout << fib2() <<" ";
    }
    cout << endl;


    return 0;
}
/* 运行结果
1 1 2 3 5 8 13 21 34 55
89 144 233 377 610
55 89 144 233 377
*/
