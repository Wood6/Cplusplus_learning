// 除法操作异常处理
#include <iostream>

using namespace std;

double divide(double a, double b, bool& valid)
{
    const double delta = 0.0000000000000001;
    double ret  = 0;

    if( !((-delta < b) && (b < delta)) )
    {
        ret = a / b;
        valid = true;       // 正常
    }
    else
    {
        valid = false;       // 异常
    }

    return ret;
}

int main()
{
    bool valid = false;
    double r = divide(1, 0, valid);

    if(true == valid)
    {
        cout << "r = " << r << endl;
    }
    else
    {
        cout << "Divide by zero ..." << endl;
    }

    cout << endl;

    r = divide(1, 1, valid);

    if(true == valid)
    {
        cout << "r = " << r << endl;
    }
    else
    {
        cout << "Divide by zero ..." << endl;
    }

    return 0;
}
/* 运行结果
Divide by zero ...

r = 1
*/
