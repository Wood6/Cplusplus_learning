// Class.c
#include "Class.h"
#include <malloc.h>

static int Test_Virtual_add(Test* pThis, int v);
static int Child_Virtual_add(Test* pThis, int v);

// 2. 定义虚函数表数据结构
struct VTable
{
    // 3. 虚函数表里面存储的内容（函数指针）
    int (*pAdd)(void*, int);
};

// 定义父类结构体
struct ClassTest
{
    struct VTable* vptr; // 1. 定义虚函数表指针 ==>虚函数表指针的类型
    int m_i;
    int m_j;
};

struct ClassChild
{
    struct ClassTest parent;
    int m_k;
};

// 父类的虚函数表
struct VTable g_Test_vtbl =
{
    Test_Virtual_add
};

// 子类的虚函数表
struct VTable g_Child_vtbl =
{
    Child_Virtual_add
};

// 实现各成员函数（带this指针）
Test* Test_Creat(int i, int j)
{
    struct ClassTest* ret = (struct ClassTest*)malloc(sizeof(struct ClassTest));

    if( ret )
    {
        ret->vptr = &g_Test_vtbl; // 4. 关联对象和虚函数表
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

// 6. 定义虚函数表中指针所指向的具体函数
static int Test_Virtual_add(Test* pThis, int v)
{
    return ( (struct ClassTest*)pThis )->m_i+ ( (struct ClassTest*)pThis )->m_j + v;
}

// 5. 分析具体的虚函数
int Test_add(Test* pThis, int v)  // 是个虚函数
{
    // 从虚函数表中找到真正的实现函数
    return ( (struct ClassTest*)pThis )->vptr->pAdd(pThis, v);
}

void Test_free(Test* pThis)
{
    free(pThis);
}

Child* Child_Creat(int i, int j, int k)
{
    struct ClassChild* ret = (struct ClassChild*)malloc(sizeof(struct ClassChild));

    if( ret )
    {
        ret->parent.vptr = &g_Child_vtbl;
        ret->parent.m_i = i;
        ret->parent.m_j = j;
        ret->m_k = k;
    }

    return ret;
}

int Child_getMk(Child* pThis)
{
    return ( (struct ClassChild*)pThis )->m_k;
}

// 定义子类虚函数表中指针所指向的具体函数
static int Child_Virtual_add(Test* pThis, int v)
{
    return ( (struct ClassChild*)pThis )->m_k + v;
}

// 分析虚函数
int Child_add(Child* pThis, int v)
{
    return ( (struct ClassChild*)pThis )->parent.vptr->pAdd(pThis, v);
}


