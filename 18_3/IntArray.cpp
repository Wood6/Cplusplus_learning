// IntArray.cpp 数组类cpp文件
#include "IntArray.h"
#include <stdio.h>

// 第一阶构造：资源无关的初始化
IntArray::IntArray(int len)
{
    m_length = len;
}

// 第二阶构造：系统资源的申请操作
bool IntArray::construct()
{
    bool bRet = true;

    m_pointer = new int[m_length];

    if( m_pointer )
    {
        for(int i=0; i<m_length; i++)
        {
            m_pointer[i] = 0;
        }
    }
    else
    {
        bRet = false;
    }

    return bRet;
}

IntArray* IntArray::NewInstance(int len)
{
    IntArray* obj = new IntArray(len);

    if( !(obj && obj->construct()) )
    {
        delete obj;
        obj = NULL;
    }

    return obj;
}

// 拷贝构造（成员m_pointer指向了动态内存空间,所以应该是深拷贝）
IntArray::IntArray(const IntArray& obj)
{
    m_length = obj.m_length;
    m_pointer = new int[obj.m_length];

    for(int i=0; i<obj.m_length; i++)
    {
        m_pointer[i] = obj.m_pointer[i];
    }

    printf("IntArray(const IntArray& obj)\n");
}

IntArray::~IntArray()
{
    if(m_pointer)
    {
        delete []m_pointer;
    }
}

int IntArray::length()
{
    return m_length;
}

bool IntArray::setValue(int index, int value)
{
    bool bRet = ( 0 <= index ) && ( index < m_length);

    if(bRet)
    {
        m_pointer[index] = value;
    }

    return bRet;
}

bool IntArray::getValue(int index, int &value)
{
    bool bRet = (0 <= index ) && (index < m_length);

    if(bRet)
    {
        value = m_pointer[index];
    }

    return bRet;
}

int& IntArray::operator [] (int index)
{
    if( (0 <= index ) && (index < m_length) )
    {
        return m_pointer[index];
    }
}

IntArray& IntArray::self()
{
    return *this;
}
