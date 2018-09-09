// main.cpp 文件
#include <iostream>
#include <string>
#include <memory>  //for auto_ptr
#include "HeapArray.h"

using namespace std;

void TestHeapArray()
{
    // 使用智能指针，目的是自动释放堆空间
    // 局部变量pa，数据类型：auto_ptr< HeapArray<double> > 是个智能指针类型
    // 初始化 HeapArray<double>::NewInstance(5)
    auto_ptr< HeapArray<double> > pa(HeapArray<double>::NewInstance(5));

    if(pa.get() != NULL)
    {
        HeapArray<double>& array = pa->self();

        for(int i=0; i<array.length(); i++)
        {
            array[i] = i;
        }

        for (int i=0; i<10; i++)    // 越界访问触发异常
        {
            cout << array[i] << endl;
        }
    }
}

int main()
{
    TestHeapArray();

    return 0;
}
/* 运行结果
0
1
2
3
4

This application has requested the Runtime to terminate it in an unusual way.
Please contact the application's support team for more information.
terminate called after throwing an instance of 'std::out_of_range'
  what():  T& HeapArray<T>::operator[](int index)
*/
