// IntArray.h 数组类头文件
#ifndef _INTARRAY_H_
#define _INTARRAY_H_

class IntArray
{
private:
    int m_length;
    int *m_pointer;

    IntArray(int len);  // 第一阶构造函数
    bool construct();   // 第二阶构造函数
public:  
    static IntArray* NewInstance(int len);

    IntArray(const IntArray& obj);  // 继续保留拷贝构造函数是公有的
    ~IntArray();
    int length();
    bool setValue(int index, int value);
    bool getValue(int index, int &value);

    int& operator [] (int n);
    IntArray& self();   // 因为该类只能在堆在创建对象，为了操作方便
                        // 通过这里返回对象的引用，可以避开指针操作的麻烦
};

#endif
