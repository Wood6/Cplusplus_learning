// C分格if-else异常处理存在的通病
#include <iostream>

using namespace std;

#define SUCCESS            0    // 成功
#define INVALID_POINTER   -1    // 指针异常
#define INVALID_LENGTH    -2    // 长度异常
#define INVALID_PARAMETER -3    // 参数异常

int MemSet(void* dest, unsigned int length, unsigned char v)
{
    if(dest == NULL)
    {
        return INVALID_POINTER;
    }

    if (length < 4)
    {
        return INVALID_LENGTH;
    }

    if( (v < 0) || (v > 9) )       // v字符的ASCII码在0~9以外视为参数非法
    {
        return INVALID_PARAMETER;
    }

    unsigned char* p = (unsigned char*)dest;

    for(unsigned int i = 0; i< length; i++)
    {
        // 将char赋值给int。
        // 1.如果是char，则最高位为符号位，char赋值给int时会扩展最高位
        // 2.如果是unsigned char，则不会扩展，即低8位为char的值,其余24位为0
        p[i] = v;
    }

    return SUCCESS;
}

int main()
{
    int ai[15];

    int ret = MemSet(ai, sizeof(ai), 0);

    // 正常处理与异常处理的代码混杂，不容易看出哪些是正常处理时的代码
    // 哪些是异常发生时应处理的代码
    //（特别是当返回值用数字表示，而不是这里有意义的常量名时）
    if(ret == SUCCESS)
    {
        cout << "SUCCESS" << endl;
    }
    else if(ret == INVALID_POINTER)
    {
        cout << "INVALID_POINTER" << endl;
    }
    else if(ret == INVALID_LENGTH)
    {
        cout << "INVALID_LENGTH" << endl;
    }
    else if(ret == INVALID_PARAMETER)
    {
        cout << "INVALID_PARAMETER" << endl;
    }

    for(int i=0; i<sizeof(ai)/sizeof(ai[0]); i++)
    {
        cout << ai[i] << " ";
    }

    cout << endl;

    return 0;
}
/* 运行结果
SUCCESS
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
*/
