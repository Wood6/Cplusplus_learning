// 逻辑表达式体验
#include <iostream>

using namespace std;

int func(int i)
{
    cout << "func(), i = " << i << endl;

    return i;
}

int main()
{
    if( func(0) || func(1))
    {
        cout << "Test 1" << endl;
    }

    if( func(0) && func(1) )
    {
        cout << "Test 2" << endl;
    }

    return 0;
}
/* 运行结果
func(), i = 0
func(), i = 1
Test 1
func(), i = 0
*/
