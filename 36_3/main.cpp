// 警惕类中成员没有变化的情况
#include <iostream>

using namespace std;

int main()
{
    const string s1 = "12345";
    string s2 = "";

    s2.reserve(10);     // 保留一定量内存以容纳一定数量的字符

    for(int i=0; i<5; i++)
    {
        s2[i] = s1[i];   // 注意，虽然此时s2对象中的字符串内存
                         // 确实被赋新的值了。但用这种方式赋值
                         // 相等于只是通过指针赋值，s2.length不
                         // 会自动更新，即仍为0

                         // []重载只是直接返回数组第n个元素的地址值
                         // 没法更新维护string类中长度信息的length值
    }

    cout << "s2 = " << s2 << endl;
    cout << "s2.length = " << s2.length() << endl;
    cout << "s2 is empty ==> " << s2.empty() << endl;

    return 0;
}
/* 运行结果
s2 =
s2.length = 0
s2 is empty ==> 1
*/
