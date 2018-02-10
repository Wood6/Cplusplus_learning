// 为什么要避免隐式类型转换的原因！
#include <iostream>

using namespace std;

int main()
{
    char c = 'a';
    short int si = 1;
    int i = -2000;
    unsigned int ui = 1000;
    double d = i;

    cout << "d = " << d << endl;
    cout << "i + ui = " << i+ui << endl;   // ui + i = 4294966296

    // 因为i会被编译器隐式转为unsigned int类型，变成一个很大的正数
    if( (i + ui) > 0 )
    {
        cout << "Positive" << endl;
    }
    else
    {
        cout << "Negative" << endl;
    }

    // 为什么不是2？
    // 因为编译器认为int型数据是最高效的，所以会将char 和 short int
    // 都转换为int型数据，这样自然也就是占 4 字节内存了
    cout << "sizeof(c+si) = " << sizeof(c+si) << endl;  // 4

    // 上面两个 运行结果 表面看与我们写代码的初始意图都不一样，造成这个的
    // 原因就是编译器自动给我们进行了隐式类型转换，也正是因为这个原因，故
    // 在工程中应该尽量避免这种编译器隐式类型转换的行为

    return 0;
}
/*
d = -2000
i + ui = 4294966296
Positive
sizeof(c+si) = 4
*/
