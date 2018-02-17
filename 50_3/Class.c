// Class.c
#include "Class.h"
#include <malloc.h>

static int Test_Virtual_add(Test* pThis, int v);
static int Child_Virtual_add(Test* pThis, int v);

// 2. �����麯�������ݽṹ
struct VTable
{
    // 3. �麯��������洢�����ݣ�����ָ�룩
    int (*pAdd)(void*, int);
};

// ���常��ṹ��
struct ClassTest
{
    struct VTable* vptr; // 1. �����麯����ָ�� ==>�麯����ָ�������
    int m_i;
    int m_j;
};

struct ClassChild
{
    struct ClassTest parent;
    int m_k;
};

// ������麯����
struct VTable g_Test_vtbl =
{
    Test_Virtual_add
};

// ������麯����
struct VTable g_Child_vtbl =
{
    Child_Virtual_add
};

// ʵ�ָ���Ա��������thisָ�룩
Test* Test_Creat(int i, int j)
{
    struct ClassTest* ret = (struct ClassTest*)malloc(sizeof(struct ClassTest));

    if( ret )
    {
        ret->vptr = &g_Test_vtbl; // 4. ����������麯����
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

// 6. �����麯������ָ����ָ��ľ��庯��
static int Test_Virtual_add(Test* pThis, int v)
{
    return ( (struct ClassTest*)pThis )->m_i+ ( (struct ClassTest*)pThis )->m_j + v;
}

// 5. ����������麯��
int Test_add(Test* pThis, int v)  // �Ǹ��麯��
{
    // ���麯�������ҵ�������ʵ�ֺ���
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

// ���������麯������ָ����ָ��ľ��庯��
static int Child_Virtual_add(Test* pThis, int v)
{
    return ( (struct ClassChild*)pThis )->m_k + v;
}

// �����麯��
int Child_add(Child* pThis, int v)
{
    return ( (struct ClassChild*)pThis )->parent.vptr->pAdd(pThis, v);
}


