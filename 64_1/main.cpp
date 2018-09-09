// C++异常处理初探
#include <iostream>

using namespace std;

double divide(double a, double b)
{
    const double delta = 0.0000000000000001;
    double ret  = 0;

    if( !((-delta < b) && (b < delta)) )
    {
        ret = a / b;
    }
    else
    {
        throw 0;  // 除0异常时，抛出整数0
                  // 因异常不在该函数处理，会向外层调用函数传递
    }

    return ret;
}

int main()
{
    try
    {
        // 除0时由于divide函数抛出异常，而在函数内部那里又没有处理该异常
        // 因此异常被继续抛出，到了main函数中调用函数的代码之处，而在这里
        // 异常被try-catch捕获转向catch语句中，catch处理完后，会直接转向
        // catch语句的后面"return 0;"去执行。而不是转到调用函数的下一行
        // 语句（即cout << "r = " << r << endl;）
        double r = divide(1, 0);
        cout << "r = " << r << endl;
    }
    catch(...)
    {
        cout << "Divide by zero ..." << endl;
    }

    cout << endl;

    try
    {
        double r = divide(1, 1);
        cout << "r = " << r << endl;
    }
    catch(...)
    {
        cout << "Divide by zero ..." << endl;
    }

    return 0;
}
/* 运行结果
Divide by zero ...

r = 1
*/
