// IntArray.cpp 数组类cpp文件
#include "IntArray.h"
#include <stdio.h>

IntArray::IntArray(int len)
{
    m_pointer = new int[len];

    for(int i=0; i<len; i++)
    {
        m_pointer[i] = 0;
    }

    m_length = len;
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

IntArray::free()
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
