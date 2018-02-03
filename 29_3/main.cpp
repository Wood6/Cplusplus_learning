// 扩展系统中已经存在的函数功能
#include <stdio.h>
#include <string.h>

// 重载strcpy函数，进行功能的扩展
char* strcpy(char* buf, const char* src, int nByte)
{
    return strncpy(buf, src, nByte);
}

int main()
{
    const char* srcString = "Wood is learning CplusCplus!";
    char buf[5] = {0};

    //strcpy(buf, srcString);              // 原来strcpy函数，会出现缓冲区溢出
    //strncpy(buf, srcString, sizeof(buf)-1);  // 直接调用系统库函数
    strcpy(buf, srcString, sizeof(buf)-1); // 重载的函数,不换名字又能控制不溢出

    printf("buf[] = %s\n", buf);

    return 0;
}
/* 运行结果
buf[] = Wood
*/

