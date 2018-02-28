// 数组模板类
#include <iostream>
#include "Array.h"

using namespace std;

int main()
{
    Array<double, 5> a1;

    for( int i=0; i<5; i++ )
    {
        a1[i] = (i + 0.5) * i;
    }

    for( int i=0; i<5; i++ )
    {
        cout << a1[i] << " ";
    }

    cout << endl;

    double value = 0;

    for( int i=0; i<5; i++ )
    {
        if( a1.set(i, i) )
        {
            if( a1.get(i, value) )
            {
                cout << value << " ";
            }
        }
    }

    cout << endl;

    // a2[1] 就不能被赋值，因为对象被const修饰调用的是const版本的[]
    //const Array<double, 5> a2;
    //a2[1] = 5;

    return 0;
}
/* 运行结果
0 1.5 5 10.5 18
0 1 2 3 4
*/
