// 函数模板示例
#include <iostream>

using namespace std;

// 函数模板实现变量交换
template < typename T >
void Swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

// 函数模板实现降序排列
template < typename T >
void Sort(T tab[], int len)
{
    for(int i=0; i<len; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if( tab[i] > tab[j] )   // 降序排列
            {
                Swap(tab[i], tab[j]);
            }
        }
    }
}

// 函数模板实现数组输出
template <typename T>
void Print(T tab[], int len)
{
    for(int i=0; i<len; i++)
    {
        cout << tab[i] << " ";
    }

    cout << endl;
}

int main()
{
    int array_i[] = {5, 3, 2, 1, 4};

    Print(array_i, sizeof(array_i)/sizeof(array_i[0]));
    Sort(array_i, sizeof(array_i)/sizeof(array_i[0]));
    Print(array_i, sizeof(array_i)/sizeof(array_i[0]));
    cout << endl;

    float array_f[] = {8.88, 0.598, 2.22, 3.1415, 12.14};

    Print(array_f, sizeof(array_f)/sizeof(array_f[0]));
    Sort(array_f, sizeof(array_f)/sizeof(array_f[0]));
    Print(array_f, sizeof(array_f)/sizeof(array_f[0]));
    cout << endl;

    string array_s[] = {"C++", "C#", "PHP", "python", "Java"};

    Print(array_s, sizeof(array_s)/sizeof(array_s[0]));
    Sort(array_s, sizeof(array_s)/sizeof(array_s[0]));
    Print(array_s, sizeof(array_s)/sizeof(array_s[0]));

    return 0;
}
/* 运行结果
5 3 2 1 4
1 2 3 4 5

8.88 0.598 2.22 3.1415 12.14
0.598 2.22 3.1415 8.88 12.14

C++ C# PHP python Java
C# C++ Java PHP python
*/
