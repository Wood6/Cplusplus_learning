// 重载 << 和 >> 实现字符串的循环左移和循环右移
#include <iostream>

using namespace std;

// 循环左移
string operator << (string str, unsigned int n)
{
    // 处理 移位的位数数值超过了字符长度的情况
    unsigned int pos = n % str.length();

    return str.substr(pos) + str.substr(0, pos);
}

// 循环右移
string operator >> (string str, unsigned int n)
{
    unsigned int pos = n % str.length();
    unsigned int index = str.length() - pos;

    return str.substr(index) + str.substr(0, index);
}

int main()
{
    string s = "abcde";

    string l = (s << 8);   // 等价于 s<<3

    string r = (s >> 10);  // 等价于 s>>5

    cout << l << endl;
    cout << r << endl;

    return 0;
}
/* 运行结果
deabc
abcde
*/
