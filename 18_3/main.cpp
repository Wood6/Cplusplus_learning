// main.cpp 文件
#include <stdio.h>
#include "IntArray.h"

int main()
{
    IntArray tab(5);  // 利用IntArray创建5个元素的对象数组
    int value = 0;

    for(int i=0; i<tab.length(); i++)
    {
        tab.setValue(i, i);
    }

    for(int i=0; i<tab.length(); i++)
    {
        if( tab.getValue(i, value) )
        {
            printf("tab[%d] = %d\n", i, value);
        }
    }

    tab.free();

    return 0;
}
/* 运行结果
tab[0] = 0
tab[1] = 1
tab[2] = 2
tab[3] = 3
tab[4] = 4
*/
