// 函数实现变量交换
#include <iostream>

using namespace std;

void Swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void Swap(float& a, float& b)
{
    float tmp = a;
    a = b;
    b = tmp;
}

void Swap(string& a, string& b)
{
    string tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int i1 = 3;
    int i2 = 4;

    Swap(i1, i2);
    cout << "i1 = " << i1 << endl
         << "i2 = " << i2 << endl;

    float f1 = 3.14;
    float f2 = 8.88;

    Swap(f1, f2);
    cout << "f1 = " << f1 << endl
         << "f2 = " << f2 << endl;

    string s1 = "Wood";
    string s2 = "Jim";

    Swap(s1, s2);
    cout << "s1 = " << s1 << endl
         << "s2 = " << s2 << endl;

    return 0;
}
/* 运行结果
i1 = 4
i2 = 3
f1 = 8.88
f2 = 3.14
s1 = Jim
s2 = Wood
*/
