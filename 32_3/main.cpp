#include <iostream>

using namespace std;

int main()
{
    // C++标准库中就直接实现了 << >>
    cout << 1 << ' ' << 'c' << ' ' << 3.14 << endl;

    double d1 = 0;

    cout << "Please enter data of double!" << endl;

    cin >> d1;

    cout << d1 << endl;
    cout << d1 + 5 << endl;

    return 0;
}
/* 运行结果
1 c 3.14
Please enter data of double!
2.12      // 输入的数据
2.12
7.12
*/
