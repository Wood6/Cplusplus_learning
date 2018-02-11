// 场景：庄主打老怪
#include <iostream>

using namespace std;

// 老怪
class Boss
{
public:
    int fight()   // 无名怪招
    {
        int ret = 10;  // 威力10

        cout << "Boss::fight(): " << ret << endl;

        return ret;
    }
};

// 老庄主
class Master
{
public:
    virtual int eightSwordKill()  // 八剑齐飞
    {
        int ret = 8;

        cout << "Master::eightSwordKill(): " << ret << endl;

        return ret;
    }
};

// 少庄主
class NewMaster : public Master
{
public:
    int eightSwordKill()   // 八剑齐飞
    {
        // 少庄主对老庄主的八剑齐飞进行改造，练就了
        // 双臂的八剑齐飞威力大增，威力是老庄主的2倍
        int ret = Master::eightSwordKill() * 2;

        cout << "NewMaster::eightSwordKill(): " << ret << endl;

        return ret;
    }
};

// 战场pk
void field_pk(Boss& boss, Master& master)
{
    if( boss.fight() < master.eightSwordKill() )
    {
        cout << "Boss is killed..." << endl;
    }
    else
    {
        cout << "Master is killed..." << endl;
    }
}

int main()
{
    Master master;
    Boss boss;

    cout << "Master vs Boss" << endl;

    field_pk(boss, master);

    cout << endl;
    cout << "NewMaster vs Boss" << endl;

    NewMaster newMaster;

    field_pk(boss, newMaster);

    return 0;
}
/* 运行结果
Master vs Boss
Master::eightSwordKill(): 8
Boss::fight(): 10
Master is killed...

NewMaster vs Boss
Master::eightSwordKill(): 8
NewMaster::eightSwordKill(): 16
Boss::fight(): 10
Boss is killed...
*/
