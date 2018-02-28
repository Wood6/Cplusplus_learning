// main.cpp 文件
#include <iostream>
#include "HeapArray.h"

using namespace std;

int main()
{
    HeapArray<char>* tab = HeapArray<char>::NewInstance(10);
    HeapArray<char>* tab1 = HeapArray<char>::NewInstance(5);

    if( tab && tab1 )
    {
        HeapArray<char>& rTab = tab->self();
        HeapArray<char>& rTab1 = tab1->self();

        for(int i=0; i<tab->length(); i++)
        {
            rTab[i] = i + 'a';  // 避免非得这样使用指针 (*tab)[i] = i + 'a';
        }

        for(int i=0; i<tab->length(); i++)
        {
            cout << rTab[i] << " ";
        }

        cout << endl;

        //HeapArray<char> tab2 = *tab;   // 拷贝构造,能直接用现有数组初始化新定义数组
        HeapArray<char> tab2 = rTab;     // 与上等价

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
a b c d e f g h i j
a b c d e f g h i j
a b c d e f g h i j
*/
