// IntArray.cpp 数组类cpp文件
#include "IntArray.h"

IntArray::IntArray(int len)
{
    m_pointer = new int[len];

    for(int i=0; i<len; i++)
    {
        m_pointer[i] = 0;
    }

    m_length = len;
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
