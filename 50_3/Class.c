// Class.c
#include "Class.h"
#include <malloc.h>

// 定义结构体
struct ClassTest
{
    int m_i;
    int m_j;
};

// 实现各成员函数（带this指针）
Test* Test_Creat(int i, int j)
{
    struct ClassTest* ret = (struct ClassTest*)malloc(sizeof(struct ClassTest));

    if( ret )
    {
        ret->m_i = i;
        ret->m_j = j;
    }

    return ret;
}

int Test_getMi(Test* pThis)
{
    return ( (struct ClassTest*)pThis )->m_i;
}

int Test_getMj(Test* pThis)
{
    return ( (struct ClassTest*)pThis )->m_j;
}

int Test_add(Test* pThis, int v)
{
    return ( (struct ClassTest*)pThis )->m_i+ ( (struct ClassTest*)pThis )->m_i + v;
}

void Test_free(Test* pThis)
{
    free(pThis);
}

