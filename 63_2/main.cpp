// 除法操作异常处理优化 setjmp() longjmp()的应用
#include <iostream>
#include <csetjmp>      // for setjmp()、longjmp()

using namespace std;

static jmp_buf env;     // 须定义全局的上下文环境

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
        longjmp(env, 1);  // 当错误发生时会跳转到setjmp那么的代码
                          // 处，重新执行setjmp并把其的返回值设为1
    }

    return ret;
}

int main()
{
    if(setjmp(env) == 0)       // 先保存上下文环境，刚直接调用时返回值为0
    {
        double r = divide(1, 0);         // 会产生异常
        cout << "r = " << r << endl;
    }
    else
    {
        cout << "Divide by zero ..." << endl;
    }

    cout << endl;

    if(setjmp(env) == 0)        // 先保存上下文环境，刚直接调用时返回值为0
    {
        double r = divide(1, 1);         // 正常
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
