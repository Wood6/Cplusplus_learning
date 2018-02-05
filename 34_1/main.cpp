// 数组方式使用string类
#include <iostream>

using namespace std;

int main()
{
    string s = "abcde123456f7";

    int nCnt = 0;

    for(int i=0; i<s.length(); i++)
    {
        if( isdigit(s[i]) )
        {
            ++nCnt;
        }
    }

    cout << nCnt << endl;

    return 0;
}
/* 运行结果
7
*/
