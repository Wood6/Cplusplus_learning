// 获取斐波那契数列每项的值
#include <iostream>

using namespace std;

int fib()
{
    static int a0 = 0;
    static int a1 = 1;
    int ret = a1;

    a1 = a0 + a1;
    a0 = ret;

    return ret;
}

int main()
{
    for(int i=0; i<10; i++)
    {
        // 注意每次调用fib()，形式完全相同，但函数返回的结果不同！
        // 这叫有状态函数，因为函数内部会通过static变量记录上次的状态
        cout << fib() << " ";
    }
    cout << endl;

    // 缺点：函数不能回到初始状态，会从新的状态开始，继续计算。
    for(int i=0; i<5; i++)
    {
        cout << fib() << " ";  // 从上次结果开始
    }
    cout << endl;

    return 0;
}
/* 运行结果
1 1 2 3 5 8 13 21 34 55
89 144 233 377 610
*/
