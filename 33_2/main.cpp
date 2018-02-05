// 字符串和数字的互相转换
#include <iostream>
#include <sstream>
#include <string>

using namespace std;


// STRING_TO_NUMBER 定义为宏主要目的是为了能将任意类型（如double,int)的数字型字符串转为数字
// 返回值：转换成功1 否则返回0
#define STRING_TO_NUMBER(str, num) (istringstream(str) >> d)
// 返回值：转换过后的字符串
#define NUMBER_TO_STRING(num) (((ostringstream&)(ostringstream() << num)).str())

int main()
{
    double d = 0;

    // 字符串位数过大时出现精度丢失的情况
    if( STRING_TO_NUMBER("3.1415978", d) )
        cout << d << endl;

    // 数字位数过大时也出现异常情况
    cout << NUMBER_TO_STRING(123456789.123456) << endl;

    return 0;
}
/* 运行结果
3.1416
1.23457e+008
*/
