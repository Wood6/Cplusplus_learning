// main.cpp 类模板的工程应用注意点
#include <iostream>
#include "operator.h"

using namespace std;

int main()
{
    Operator<int> op1;

    cout << op1.add(22, 2) << endl;
    cout << op1.minus(22, 2) << endl;
    cout << op1.multiply(22, 2) << endl;
    cout << op1.divide(22, 2) << endl;

    return 0;
}
/* 运行结果
24
20
44
11
*/
