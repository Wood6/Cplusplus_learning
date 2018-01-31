#include <stdio.h>

struct Biology
{
    bool living;        // 生命
};

struct Animal : Biology
{
    bool movable;       // 可移动
    void findFood(){};  // 找食物
};

struct Plant : Biology
{
    bool growable;      // 可长大
};

struct Beast : Animal
{
    void sleep(){};     // 睡觉
};

struct Human : Animal
{
    void sleep(){};     // 睡觉
    void work(){};      // 劳动
};

int main()
{
    return 0;
}
