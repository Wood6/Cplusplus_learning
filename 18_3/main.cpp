// main.cpp 文件
#include <iostream>
#include "IntArray.h"

using namespace std;

int main()
{
    IntArray* tab = IntArray::NewInstance(10);
    IntArray* tab1 = IntArray::NewInstance(5);

    if( tab && tab1 )
    {
        IntArray& rTab = tab->self();
        IntArray& rTab1 = tab1->self();

        for(int i=0; i<tab->length(); i++)
        {
            rTab[i] = i;  // 避免非得这样使用指针 (*tab)[i] = i ;
        }

        for(int i=0; i<tab->length(); i++)
        {
            cout << rTab[i] << " ";
        }

        cout << endl;

        //IntArray tab2 = *tab;   // 拷贝构造,能直接用现有数组初始化新定义数组
        IntArray tab2 = rTab;     // 与上等价

        for(int i=0; i<tab2.length(); i++)
        {
            cout << tab2[i] << " ";
        }

        cout << endl;

        rTab1 = rTab;   // 赋值

        for(int i=0; i<rTab1.length(); i++)
        {
            cout << rTab1[i] << " ";
        }

        cout << endl;
    }

    delete tab;

    return 0;
}
/* 运行结果
0 1 2 3 4 5 6 7 8 9
IntArray(const IntArray& obj)
0 1 2 3 4 5 6 7 8 9
IntArray::operator = (const IntArray& obj)
0 1 2 3 4 5 6 7 8 9
*/
