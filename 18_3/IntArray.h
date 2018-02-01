// IntArray.h 数组类头文件
#ifndef _INTARRAY_H_
#define _INTARRAY_H_

class IntArray
{
private:
    int m_length;
    int *m_pointer;

public:
    IntArray(int len);
    IntArray(const IntArray& obj);
    free();

    int length();
    bool setValue(int index, int value);
    bool getValue(int index, int &value);
};

#endif
