// 指针和数组的关系
#include <iostream>

using namespace std;

int main()
{
    int a[5] = {0};

    for(int i=0; i<5; i++)
    {
        a[i] = i;
    }

    for(int i=0; i<5; i++)
    {
        // 指针方式的访问数组，比较不直观！
        // 而下标访问的使用，可以隐藏对指针的操作
        cout << *(a + i) << " ";
    }
    cout << endl;

    for(int i=0; i<5; i++)
    {
        i[a] = i+5;   // a[i] <--> *(a + i) <--> *(i + a) <--> i[a]
    }

    for(int i=0; i<5; i++)
    {
        cout << i[a] << " ";
    }
    cout << endl;

    return 0;
}
/* 运行结果
0 1 2 3 4
5 6 7 8 9
*/
