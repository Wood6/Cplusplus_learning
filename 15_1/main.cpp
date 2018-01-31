// 类成员的访问属性（对外）
#include <stdio.h>

// 生物类
struct Biology
{
    bool living;        // 生命
};

// 动物类
struct Animal : Biology
{
    bool movable;       // 可移动
    void findFoof() {}; // 找食物
};

// 植物类
struct Plate : Biology
{
    bool growable;      // 可长大
};

// 老虎类
struct Tirger : Animal
{
    void sleep() {};
};

// 人类
struct Human : Animal
{
    void sleep() {};    // 睡觉
    void work() {};     // 劳动
};

struct Girl : Human
{
private:
    int age;            // 女孩的年龄:private
    int weight;         // 女孩的体重:private

public:
    void print()
    {
        age = 22;
        weight = 48;

        printf("I'm a girl, I'm %d years old.\n", age);
        printf("My weight is %dkg.\n", weight);
    }
};

struct Boy : Human
{
private:
    int height;  // 身高:private
    int salary;  // 薪水:private

public:
    int age;
    int weight;

    void print()
    {
        height = 175;
        salary = 10000;

        printf("I'm a boy, my height is %dcm.\n", height);
        printf("My salary is %d RMB. salary.\n");
    }
};

int main()
{
    Girl g;
    Boy b;

    g.print();

    b.age = 19;
    b.weight = 60;
    // b.height = 180;  // error: 'int Boy::height' is private

    b.print();

    return 0;
}
/* 运行结果
I'm a girl, I'm 22 years old.
My weight is 48kg.
I'm a boy, my height is 175cm.
My salary is 175 RMB. salary.
*/
