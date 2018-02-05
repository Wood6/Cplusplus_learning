// 字符串类的使用
#include <iostream>

using namespace std;

// 选择排序，从小到大排序  时间复杂度O(n*n)
void StringSort(string sa[], int size)
{
    for(int i=0; i<size; i++)       // ==>n
    {
        for(int j=i+1; j<size; j++) // ==>n
        {
            if( sa[i] > sa[j] )
            {
                sa[i].swap(sa[j]);  // 等价于 swap(sa[i], sa[j]);
            }
        }
    }
}

// 相加
string StringCat(string sa[], int size)
{
    string s = "";

    for(int i=0; i<size; i++)
    {
        s += sa[i] + ";";
    }

    return s;
}

int main()
{
    string sa[7] = {
        "Hello World!",
        "Wood lenrning CplusCplus!",
        "C#",
        "Jave",
        "C++",
        "Python",
        "TypeScrip"
    };

    StringSort(sa, 7);

    for(int i=0; i<7; i++)
    {
        cout << sa[i] << endl;
    }

    printf("\n");

    cout << StringCat(sa, 7) << endl;

    return 0;
}
/* 运行结果
C#
C++
Hello World!
Jave
Python
TypeScrip
Wood lenrning CplusCplus!

C#;C++;Hello World!;Jave;Python;TypeScrip;Wood lenrning CplusCplus!;
*/
