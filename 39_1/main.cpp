// 逗号表达式示例
#include <iostream>

using namespace std;

void func(int i)
{
    cout << "func(): i = " << i << endl;
}

int main()
{
    int array[3][3] =
    {
        (1, 2 ,3),    // 注意这里是小括号，不是花括号，小
        (4, 5, 6),    // 括号中是逗号，相当于只给数组前三
        (7, 8, 9)     // 个元素赋值分别是3、6、9，其余为0
    };

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << array[i][j] << " ";
        }

        cout << endl;
    }

    int i = 0;
    int j = 0;

    (i, j) = 8;      // 合法：逗号表达式返回j，相当于j = 6

    cout << "i = " << i << endl;
    cout << "j = " << j << endl;

    while( i < 10 )
        func(i),      // 这里与下一行的i++组合一个表达式
    i++;              // 所以while不会死循环

    return 0;
}
/* 运行结果
3 6 9
0 0 0
0 0 0
i = 0
j = 8
func(): i = 0
func(): i = 1
func(): i = 2
func(): i = 3
func(): i = 4
func(): i = 5
func(): i = 6
func(): i = 7
func(): i = 8
func(): i = 9
*/
