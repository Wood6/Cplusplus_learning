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

    printf("-----------------------\n");

    IntArray tab2 = tab;   // 拷贝构造,能直接用现有数组初始化新定义数组

    for(int i=0; i<tab2.length(); i++)
    {
        if( tab.getValue(i, value) )
        {
            printf("tab2[%d] = %d\n", i, value);
        }
    }

    return 0;
}
/* 运行结果
tab[0] = 0
tab[1] = 1
tab[2] = 2
tab[3] = 3
tab[4] = 4
-----------------------
IntArray(const IntArray& obj)
tab2[0] = 0
tab2[1] = 1
tab2[2] = 2
tab2[3] = 3
tab2[4] = 4
*/
