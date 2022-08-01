#include <iostream>
#include <cstring>
#include <cstdio>
#include <iomanip>
using namespace std;
const int WARRIOR_NUM = 5;

bool EndWar[2] = {false, false};
int nTime;
int nMinute;
string WarriorName[WARRIOR_NUM] = {"dragon", "ninja", "iceman", "lion", "wolf"};
string WeaponName[3] = {"sword", "bomb", "arrow"};
int LifeValue[WARRIOR_NUM];
int ForceValue[WARRIOR_NUM];
int InitialLifeValue, Citynum, lostloyal, endtime;

class Headquarter;

class Warrior
{
public:
    string color;
    int kindno;
    int no;
    int HP;
    int Force;
    int Location;
    int weaponnum;
    int weapon[3];
    int bow[2];

public:
    virtual void Init(string co, int kindno_, int no_, int hp, int force);
    virtual void ProducePrint(int minu);
    virtual void Flee();
    void MarchPrint(int minu);
    void MarchStep();
    void report(int minu);
    void Yell();
};

class CDragon : public Warrior
{
public:
};
class CNinjia : public Warrior
{
public:
    void Init(string co, int kindno_, int no_, int hp, int force);
};
class CIceman : public Warrior
{
};
class CLion : public Warrior
{
public:
    int loyalty;

public:
    void Init(string co, int kindno_, int no_, int hp, int force, int loya);
    void ProducePrint(int minu);
    void FleePrint(int minu);
};
class CWolf : public Warrior
{
public:
    void Init(string co, int kindno_, int no_, int hp, int force);
};

class Headquarter
{
public:
    int HeadLifeValue;
    int WarriorNum;
    int colour;
    bool producestopped;
    int produceindex;
    Warrior *pWarriors[1000];

public:
    friend class Warrior;
    static int produceturn[2][WARRIOR_NUM];
    ~Headquarter();
    void Init(int colr_, int lv);
    string GetColor();
    void Produce(int minu);
    void LionRan(int minu);
    void March(int minu);
    void Report(int minu);
};
int Headquarter::produceturn[2][WARRIOR_NUM] = {{2, 3, 4, 1, 0}, {3, 0, 1, 2, 4}};

CDragon tempdragon[500];
CNinjia tempninjia[500];
CIceman tempiceman[500];
CLion templion[500];
CWolf tempwolf[500];
int dragonindex = 0, ninjiaindex = 0, icemanindex = 0, lionindex = 0, wolfindex = 0;

// class definition
//***********************************************************************************************
//************************************************************************************************

void Warrior::Init(string co, int kindno_, int no_, int hp, int force)
{
    color = co;
    kindno = kindno_;
    no = no_;
    HP = hp;
    Force = force;
    weaponnum = 0;
    memset(weapon, 0, sizeof(weapon));
    memset(bow, 0, sizeof(bow));
    if (co == "red")
    {
        Location = 0;
    }
    else if (co == "blue")
    {
        Location = Citynum + 1;
    }
    if (no_ % 3 == 2)
    {
        weapon[2] += 2;
        bow[1]++;
        weaponnum++;
    }
    else
    {
        weapon[no_ % 3]++;
        weaponnum++;
    }
}

void Warrior::ProducePrint(int minu)
{

    cout << setw(3) << setfill('0') << nTime << ":" << setw(2) << setfill('0') << minu << " " << color << " " << WarriorName[kindno] << " " << no << " born" << endl;
}

void Warrior::Flee()
{
    cout << "gaga" << endl;
}

void Warrior::MarchStep()
{
    if (color == "red")
        Location++;
    else if (color == "blue")
        Location--;
}

void Warrior::MarchPrint(int minu)
{
    printf("%03d:%02d %s %s %d marched to city %d with %d elements and force %d\n", nTime, minu, color.c_str(), WarriorName[kindno].c_str(), no, Location, HP, Force);
}

void Warrior::report(int minu)
{
    printf("%03d:%02d %s %s %d has %d sword %d bomb %d arrow and %d elements\n", nTime, minu, color.c_str(), WarriorName[kindno].c_str(), no, weapon[0], weapon[1], (bow[0] + bow[1]), HP);
}
void Warrior::Yell()
{
    printf("%03d:40 %s dragon %d yelled in city %d\n", nTime, color.c_str(), no, Location);
}

void CNinjia::Init(string co, int kindno_, int no_, int hp, int force)
{
    color = co;
    kindno = kindno_;
    no = no_;
    HP = hp;
    Force = force;
    weaponnum = 0;
    memset(weapon, 0, sizeof(weapon));
    memset(bow, 0, sizeof(bow));
    if (no_ % 3 == 2)
    {
        weapon[2] += 2;
        bow[1]++;
        weaponnum++;
    }
    else
    {
        weapon[no_ % 3]++;
        weaponnum++;
    }
    if ((no_ + 1) % 3 == 2)
    {
        weapon[2] += 2;
        bow[1]++;
        weaponnum++;
    }
    else
    {
        weapon[(no_ + 1) % 3]++;
        weaponnum++;
    }
    if (co == "red")
    {
        Location = 0;
    }
    else if (co == "blue")
    {
        Location = Citynum + 1;
    }
}
void CLion::Init(string co, int kindno_, int no_, int hp, int force, int loya)
{
    color = co;
    kindno = kindno_;
    no = no_;
    HP = hp;
    Force = force;
    weaponnum = 0;
    memset(weapon, 0, sizeof(weapon));
    memset(bow, 0, sizeof(bow));
    if (no_ % 3 == 2)
    {
        weapon[2] += 2;
        bow[1]++;
        weaponnum++;
    }
    else
    {
        weapon[no_ % 3]++;
        weaponnum++;
    }
    loyalty = loya;
    if (co == "red")
    {
        Location = 0;
    }
    else if (co == "blue")
    {
        Location = Citynum + 1;
    }
}

void CLion::ProducePrint(int minu)
{
    cout << setw(3) << setfill('0') << nTime << ":" << setw(2) << setfill('0') << minu << " " << color << " " << WarriorName[kindno] << " " << no << " born" << endl;
    cout << "Its loyalty is " << loyalty << endl;
}

void CLion::FleePrint(int minu)
{
    cout << setw(3) << setfill('0') << nTime << ":" << setw(2) << setfill('0') << minu << " " << color << " "
         << "lion"
         << " " << no << " ran away" << endl;
}

void CWolf::Init(string co, int kindno_, int no_, int hp, int force)
{
    color = co;
    kindno = kindno_;
    no = no_;
    HP = hp;
    Force = force;
    weaponnum = 0;
    memset(weapon, 0, sizeof(weapon));
    memset(bow, 0, sizeof(bow));
    if (co == "red")
    {
        Location = 0;
    }
    else if (co == "blue")
    {
        Location = Citynum + 1;
    }
}
// Headquarter function
//*******************************************************************************************************
//****************************************************************************
void Headquarter::Init(int clor_, int lv)
{
    HeadLifeValue = lv;
    colour = clor_;
    produceindex = -1;
    producestopped = false;
    WarriorNum = 0;
    for (int i = 0; i < 1000; i++)
        pWarriors[i] = new Warrior;
}

Headquarter::~Headquarter()
{
    delete pWarriors[0];
    for (int i = WarriorNum + 1; i < 1000; i++)
        delete pWarriors[i];
}

string Headquarter::GetColor()
{
    if (colour == 0)
        return "red";
    else
        return "blue";
}

void Headquarter::Produce(int nTime)
{
    if (producestopped == true)
        return;
    produceindex++;
    if (produceindex >= 5)
        produceindex -= 5;
    if (HeadLifeValue >= LifeValue[produceturn[colour][produceindex]])
    {
        int kind = produceturn[colour][produceindex];
        HeadLifeValue -= LifeValue[kind];
        WarriorNum++;
        if (kind == 0)
        {
            CDragon temp;
            temp.Init(this->GetColor(), kind, WarriorNum, LifeValue[kind], ForceValue[kind]);
            dragonindex++;
            tempdragon[dragonindex] = temp;
            pWarriors[WarriorNum] = &tempdragon[dragonindex];
            temp.ProducePrint(nTime);
        }
        else if (kind == 1)
        {
            CNinjia temp;
            temp.Init(this->GetColor(), kind, WarriorNum, LifeValue[kind], ForceValue[kind]);
            ninjiaindex++;
            tempninjia[ninjiaindex] = temp;
            pWarriors[WarriorNum] = &tempninjia[ninjiaindex];
            temp.ProducePrint(nTime);
        }
        else if (kind == 2)
        {
            CIceman temp;
            temp.Init(this->GetColor(), kind, WarriorNum, LifeValue[kind], ForceValue[kind]);
            icemanindex++;
            tempiceman[icemanindex] = temp;
            pWarriors[WarriorNum] = &tempiceman[icemanindex];
            temp.ProducePrint(nTime);
        }
        else if (kind == 3)
        {
            CLion temp;
            temp.Init(this->GetColor(), kind, WarriorNum, LifeValue[kind], ForceValue[kind], HeadLifeValue);
            lionindex++;
            templion[lionindex] = temp;
            pWarriors[WarriorNum] = &templion[lionindex];
            temp.ProducePrint(nTime);
        }
        else if (kind == 4)
        {
            CWolf temp;
            temp.Init(this->GetColor(), kind, WarriorNum, LifeValue[kind], ForceValue[kind]);
            wolfindex++;
            tempwolf[wolfindex] = temp;
            pWarriors[WarriorNum] = &tempwolf[wolfindex];
            temp.ProducePrint(nTime);
        }
    }
    else
    {
        producestopped = true;
    }
}

void LionFlee(int minu)
{

    for (int k = 0; k <= Citynum + 1; k++)
    {
        for (int i = 1; i <= lionindex; i++)
        {
            if (templion[i].HP <= 0)
                continue;
            if (templion[i].color == "blue")
                continue;
            if (templion[i].Location == k)
            {
                if (templion[i].loyalty <= 0)
                {
                    templion[i].FleePrint(minu);
                    templion[i].HP = -1;
                    templion[i].Location = -1;
                }
            }
        }
        for (int i = 1; i <= lionindex; i++)
        {
            if (templion[i].HP <= 0)
                continue;
            if (templion[i].color == "red")
                continue;
            if (templion[i].Location == k)
            {
                if (templion[i].loyalty <= 0)
                {
                    templion[i].FleePrint(minu);
                    templion[i].HP = -1;
                    templion[i].Location = -1;
                }
            }
        }
    }
}

void Headquarter::March(int nTime)
{
    for (int i = 1; i <= WarriorNum; i++)
    {
        if (pWarriors[i]->HP <= 0)
            continue;
        pWarriors[i]->MarchStep();
    }
}

void Headquarter::Report(int minu)
{
    printf("%03d:%02d %d elements in %s headquarter\n", nTime, minu, HeadLifeValue, GetColor().c_str());
}

void IcemanLost()
{
    for (int i = 1; i <= icemanindex; i++)
    {
        if (tempiceman[i].HP <= 0)
            continue;
        tempiceman[i].HP -= tempiceman[i].HP / 10;
    }
}

void LionLost()
{
    for (int i = 1; i <= lionindex; i++)
    {
        if (templion[i].HP <= 0)
            continue;
        templion[i].loyalty -= lostloyal;
    }
}
void MarchProcess(Headquarter &red, Headquarter &blue, int minu)
{
    for (int city = 1; city <= Citynum; city++)
    {
        for (int i = 1; i <= red.WarriorNum; i++)
        {
            if (red.pWarriors[i]->HP <= 0)
                continue;
            if (red.pWarriors[i]->Location == city)
            {
                red.pWarriors[i]->MarchPrint(minu);
                break;
            }
        }
        for (int i = 1; i <= blue.WarriorNum; i++)
        {
            if (blue.pWarriors[i]->HP <= 0)
                continue;
            if (blue.pWarriors[i]->Location == city)
            {
                blue.pWarriors[i]->MarchPrint(minu);
                break;
            }
        }
    }
}
void ifend(Headquarter &red, Headquarter &blue, int minu)
{
    if (minu == 0)
    {
        for (int i = 1; i <= blue.WarriorNum; i++)
        {
            if (blue.pWarriors[i]->Location == 0)
            {
                printf("%03d:10 %s %s %d reached red headquarter with %d elements and force %d\n", nTime, blue.GetColor().c_str(), WarriorName[blue.pWarriors[i]->kindno].c_str(), blue.pWarriors[i]->no, blue.pWarriors[i]->HP, blue.pWarriors[i]->Force);

                EndWar[1] = true;
            }
        }
        if (EndWar[1] == true)
            cout << setw(3) << setfill('0') << nTime << ":" << setw(2) << setfill('0') << "10"
                 << " red headquarter was taken" << endl;
    }
    else if (minu == 1)
    {
        for (int i = 1; i <= red.WarriorNum; i++)
        {
            if (red.pWarriors[i]->Location == Citynum + 1)
            {
                printf("%03d:10 %s %s %d reached blue headquarter with %d elements and force %d\n", nTime, red.GetColor().c_str(), WarriorName[red.pWarriors[i]->kindno].c_str(), red.pWarriors[i]->no, red.pWarriors[i]->HP, red.pWarriors[i]->Force);

                EndWar[0] = true;
            }
        }

        if (EndWar[0] == true)
            cout << setw(3) << setfill('0') << nTime << ":" << setw(2) << setfill('0') << "10"
                 << " blue headquarter was taken" << endl;
    }
}
void WarriorReport(Headquarter &red, Headquarter &blue, int minu)
{
    for (int city = 1; city <= Citynum; city++)
    {
        for (int i = 1; i <= red.WarriorNum; i++)
        {
            if (red.pWarriors[i]->HP <= 0)
                continue;
            if (red.pWarriors[i]->Location == city)
            {
                red.pWarriors[i]->report(minu);
                break;
            }
        }
        for (int i = 1; i <= blue.WarriorNum; i++)
        {
            if (blue.pWarriors[i]->HP <= 0)
                continue;
            if (blue.pWarriors[i]->Location == city)
            {
                blue.pWarriors[i]->report(minu);
                break;
            }
        }
    }
}
void Rob(Warrior *rob, Warrior *robbed, int minu)
{
    if (robbed->kindno == 4)
        return;
    if (rob->weaponnum >= 10)
        return;
    if (robbed->weaponnum <= 0)
        return;
    int robnum = 0;
    int weapontype = 0;
    if (robbed->weapon[0] > 0)
    {
        weapontype = 0;
        for (;;)
        {
            if (rob->weaponnum >= 10)
                break;
            if (robbed->weapon[0] <= 0)
                break;
            rob->weapon[0]++;
            rob->weaponnum++;
            robbed->weapon[0]--;
            robbed->weaponnum--;
            robnum++;
        }
    }
    else if (robbed->weapon[1] > 0)
    {
        weapontype = 1;
        for (;;)
        {
            if (rob->weaponnum >= 10)
                break;
            if (robbed->weapon[1] <= 0)
                break;
            rob->weapon[1]++;
            rob->weaponnum++;
            robbed->weapon[1]--;
            robbed->weaponnum--;
            robnum++;
        }
    }
    else if (robbed->weapon[2] > 0)
    {
        weapontype = 2;
        for (;;)
        {
            if (rob->weaponnum >= 10)
                break;
            if (robbed->weapon[2] <= 0)
                break;
            if (robbed->bow[1] > 0)
            {
                robbed->weapon[2] -= 2;
                rob->weapon[2] += 2;
                robbed->bow[1]--;
                rob->bow[1]++;
            }
            else
            {
                robbed->weapon[2] -= 1;
                rob->weapon[2] += 1;
                robbed->bow[0]--;
                rob->bow[0]++;
            }
            robbed->weaponnum--;
            rob->weaponnum++;
            robnum++;
        }
    }
    printf("%03d:%02d %s %s %d took %d %s from %s %s %d in city %d\n", nTime, minu, rob->color.c_str(), WarriorName[rob->kindno].c_str(), rob->no, robnum, WeaponName[weapontype].c_str(), robbed->color.c_str(), WarriorName[robbed->kindno].c_str(), robbed->no, robbed->Location);
}

void RobProcess(Headquarter &red, Headquarter &blue, int minu)
{
    bool end = false;
    for (int city = 1; city <= Citynum; city++)
    {
        end = false;
        for (int i = 1; i <= red.WarriorNum; i++)
        {
            if (red.pWarriors[i]->HP <= 0)
                continue;
            if (red.pWarriors[i]->Location == city && red.pWarriors[i]->kindno == 4)
            {
                for (int j = 1; j <= blue.WarriorNum; j++)
                {
                    if (blue.pWarriors[j]->HP <= 0)
                        continue;
                    if (blue.pWarriors[j]->Location == city)
                    {
                        Rob(red.pWarriors[i], blue.pWarriors[j], minu);
                        end = true;
                        break;
                    }
                }
            }
            if (end == true)
                break;
        }
        end = false;
        for (int i = 1; i <= blue.WarriorNum; i++)
        {
            if (blue.pWarriors[i]->HP <= 0)
                continue;
            if (blue.pWarriors[i]->Location == city && blue.pWarriors[i]->kindno == 4)
            {
                for (int j = 1; j <= red.WarriorNum; j++)
                {
                    if (red.pWarriors[j]->HP <= 0)
                        continue;
                    if (red.pWarriors[j]->Location == city)
                    {
                        Rob(blue.pWarriors[i], red.pWarriors[j], minu);
                        end = true;
                        break;
                    }
                }
            }
            if (end == true)
                break;
        }
    }
}

void Get(Warrior *get, Warrior *gotten)
{
    if (get->weaponnum >= 10)
        return;
    while (gotten->weapon[0] > 0)
    {
        if (get->weaponnum >= 10)
            return;
        gotten->weapon[0]--;
        get->weapon[0]++;
        get->weaponnum++;
    }
    while (gotten->weapon[1] > 0)
    {
        if (get->weaponnum >= 10)
            return;
        gotten->weapon[1]--;
        get->weapon[1]++;
        get->weaponnum++;
    }
    while (gotten->weapon[2] > 0)
    {
        if (get->weaponnum >= 10)
            return;
        if (gotten->bow[1] > 0)
        {
            gotten->weapon[2] -= 2;
            get->weapon[2] += 2;
            get->bow[1]++;
            gotten->bow[1]--;
            get->weaponnum++;
        }
        else
        {
            gotten->weapon[2] -= 1;
            get->weapon[2] += 1;
            get->bow[0]++;
            gotten->bow[0]--;
            get->weaponnum++;
        }
    }
}
void Attack(Warrior *attacker, Warrior *victim, int weapontype)
{
    if (weapontype == 0)
    {
        victim->HP -= attacker->Force * 2 / 10;
    }
    else if (weapontype == 1)
    {
        int damage = attacker->Force * 4 / 10;
        victim->HP -= damage;
        if (attacker->kindno != 1)
        {
            attacker->HP -= damage / 2;
        }
    }
    else if (weapontype == 2)
    {
        victim->HP -= attacker->Force * 3 / 10;
    }
}

void AttackProcess(Warrior *attacker, Warrior *victim)
{
    bool end = false;
    int attackerweapon[10], victimweapon[10];
    int attackeridx = 0, victimidx = 0;
    int num1[10], num2[10];
    memset(num1, 0, sizeof(num1));
    memset(num2, 0, sizeof(num2));
    for (int i = 0; i < 10; i++)
        attackerweapon[i] = -1;
    for (int i = 0; i < 10; i++)
        victimweapon[i] = -1;
    int swordnum = attacker->weapon[0], bombnum = attacker->weapon[1], usedbownum = attacker->bow[0], unusedbownum = attacker->bow[1];
    for (int i = 1; i <= swordnum; i++)
    {
        attackerweapon[attackeridx] = 0;
        attackeridx++;
    }
    for (int i = 1; i <= bombnum; i++)
    {
        attackerweapon[attackeridx] = 1;
        attackeridx++;
    }
    for (int i = 1; i <= usedbownum; i++)
    {
        attackerweapon[attackeridx] = 3;
        attackeridx++;
    }
    for (int i = 1; i <= unusedbownum; i++)
    {
        attackerweapon[attackeridx] = 4;
        num1[attackeridx] = 2;
        attackeridx++;
    }
    swordnum = victim->weapon[0], bombnum = victim->weapon[1], usedbownum = victim->bow[0], unusedbownum = victim->bow[1];
    for (int i = 1; i <= swordnum; i++)
    {
        victimweapon[victimidx] = 0;
        victimidx++;
    }
    for (int i = 1; i <= bombnum; i++)
    {
        victimweapon[victimidx] = 1;
        victimidx++;
    }
    for (int i = 1; i <= usedbownum; i++)
    {
        victimweapon[victimidx] = 3;
        victimidx++;
    }
    for (int i = 1; i <= unusedbownum; i++)
    {
        victimweapon[victimidx] = 4;
        num2[victimidx] = 2;
        victimidx++;
    }
    attackeridx = 0, victimidx = 0;
    int ausedbownum = attacker->bow[0], aunusedbownum = attacker->bow[1];
    int vusedbownum = victim->bow[0], vunusedbownum = victim->bow[1];
    for (;;)
    {
        if (end == true)
            break;
        int inihp1 = attacker->HP;
        int inihp2 = victim->HP;
        int wp1 = attacker->weaponnum;
        int wp2 = victim->weaponnum;
        for (;;)
        {
            if (attacker->weaponnum <= 0)
                break;
            if (attackeridx >= 10)
                attackeridx -= 10;
            if (attackerweapon[attackeridx] < 0)
            {
                attackeridx++;
                continue;
            }
            if ((attackerweapon[attackeridx] == 0 || attackerweapon[attackeridx] == 1) && attacker->weapon[attackerweapon[attackeridx]] <= 0)
            {
                attackeridx++;
                continue;
            }
            if (attackerweapon[attackeridx] == 3 && ausedbownum <= 0)
            {
                attackeridx++;
                continue;
            }
            if (attackerweapon[attackeridx] == 4 && aunusedbownum <= 0)
            {
                attackeridx++;
                continue;
            }
            int weapontype = attackerweapon[attackeridx];
            if (weapontype == 3 || weapontype == 4)
            {
                Attack(attacker, victim, 2);
            }
            else
                Attack(attacker, victim, weapontype);

            if (weapontype == 3)
            {
                attacker->bow[0]--;
                ausedbownum--;
                attacker->weaponnum--;
                attacker->weapon[2]--;
            }
            else if (weapontype == 4)
            {
                if (num1[attackeridx] == 2)
                {
                    attacker->weapon[2]--;
                    attacker->bow[1]--;
                    attacker->bow[0]++;
                    num1[attackeridx]--;
                }
                else if (num1[attackeridx] == 1)
                {
                    attacker->weapon[2]--;
                    attacker->bow[0]--;
                    attacker->weaponnum--;
                    num1[attackeridx]--;
                    aunusedbownum--;
                }
            }
            else if (weapontype == 1)
            {
                attacker->weaponnum--;
                attacker->weapon[weapontype]--;
            }
            attackeridx++;
            break;
        }
        if (attacker->HP <= 0 || victim->HP <= 0)
        {
            end = true;
            break;
        }

        for (;;)
        {
            if (victim->weaponnum <= 0)
                break;
            if (victimidx >= 10)
                victimidx -= 10;
            if (victimweapon[victimidx] < 0)
            {
                victimidx++;
                continue;
            }
            if ((victimweapon[victimidx] == 0 || victimweapon[victimidx] == 1) && victim->weapon[victimweapon[victimidx]] <= 0)
            {
                victimidx++;
                continue;
            }
            if (victimweapon[victimidx] == 3 && vusedbownum <= 0)
            {
                victimidx++;
                continue;
            }
            if (victimweapon[victimidx] == 4 && vunusedbownum <= 0)
            {
                victimidx++;
                continue;
            }
            int weapontype = victimweapon[victimidx];
            if (weapontype == 3 || weapontype == 4)
            {
                Attack(victim, attacker, 2);
            }
            else
                Attack(victim, attacker, weapontype);

            if (weapontype == 3)
            {
                victim->bow[0]--;
                vusedbownum--;
                victim->weaponnum--;
                victim->weapon[2]--;
            }
            else if (weapontype == 4)
            {
                if (num2[victimidx] == 2)
                {
                    victim->weapon[2]--;
                    victim->bow[1]--;
                    victim->bow[0]++;
                    num2[victimidx]--;
                }
                else if (num2[victimidx] == 1)
                {
                    victim->weapon[2]--;
                    victim->bow[0]--;
                    victim->weaponnum--;
                    num2[victimidx]--;
                    vunusedbownum--;
                }
            }
            else if (weapontype == 1)
            {
                victim->weaponnum--;
                victim->weapon[weapontype]--;
            }
            victimidx++;
            break;
        }
        if (attacker->HP <= 0 || victim->HP <= 0)
        {
            end = true;
            break;
        }
        if (attacker->weapon[1] == 0 && attacker->weapon[2] == 0 && victim->weapon[1] == 0 && victim->weapon[2] == 0)
        {
            if (attacker->HP == inihp1 && victim->HP == inihp2)
                break;
        }
    }

    if (attacker->HP > 0 && victim->HP > 0)
    {

        if (attacker->color == "red")
        {
            printf("%03d:40 both red %s %d and blue %s %d were alive in city %d\n", nTime, WarriorName[attacker->kindno].c_str(), attacker->no, WarriorName[victim->kindno].c_str(), victim->no, attacker->Location);
            if (attacker->kindno == 0)
                attacker->Yell();
            if (victim->kindno == 0)
                victim->Yell();
        }
        else
        {
            printf("%03d:40 both red %s %d and blue %s %d were alive in city %d\n", nTime, WarriorName[victim->kindno].c_str(), victim->no, WarriorName[attacker->kindno].c_str(), attacker->no, attacker->Location);
            if (victim->kindno == 0)
                victim->Yell();
            if (attacker->kindno == 0)
                attacker->Yell();
        }
    }
    else if (attacker->HP <= 0 && victim->HP <= 0)
    {
        if (attacker->color == "red")
        {
            printf("%03d:40 both red %s %d and blue %s %d died in city %d\n", nTime, WarriorName[attacker->kindno].c_str(), attacker->no, WarriorName[victim->kindno].c_str(), victim->no, attacker->Location);
        }
        else
        {
            printf("%03d:40 both red %s %d and blue %s %d died in city %d\n", nTime, WarriorName[victim->kindno].c_str(), victim->no, WarriorName[attacker->kindno].c_str(), attacker->no, attacker->Location);
        }
    }
    else if (attacker->HP > 0 && victim->HP <= 0)
    {
        Get(attacker, victim);
        printf("%03d:40 %s %s %d killed %s %s %d in city %d remaining %d elements\n", nTime, attacker->color.c_str(), WarriorName[attacker->kindno].c_str(), attacker->no, victim->color.c_str(), WarriorName[victim->kindno].c_str(), victim->no, attacker->Location, attacker->HP);
        if (attacker->kindno == 0)
            attacker->Yell();
    }
    else if (attacker->HP <= 0 && victim->HP > 0)
    {
        Get(victim, attacker);
        printf("%03d:40 %s %s %d killed %s %s %d in city %d remaining %d elements\n", nTime, victim->color.c_str(), WarriorName[victim->kindno].c_str(), victim->no, attacker->color.c_str(), WarriorName[attacker->kindno].c_str(), attacker->no, victim->Location, victim->HP);
        if (victim->kindno == 0)
            victim->Yell();
    }
}

void Fight(Headquarter &red, Headquarter &blue)
{
    bool end = false;
    for (int city = 1; city <= Citynum; city++)
    {
        end = false;
        for (int i = 1; i <= red.WarriorNum; i++)
        {
            if (red.pWarriors[i]->HP <= 0)
                continue;
            if (red.pWarriors[i]->Location == city)
            {
                for (int j = 1; j <= blue.WarriorNum; j++)
                {
                    if (blue.pWarriors[j]->HP <= 0)
                        continue;
                    if (blue.pWarriors[j]->Location == city)
                    {
                        if (city % 2 == 1)
                            AttackProcess(red.pWarriors[i], blue.pWarriors[j]);
                        else
                            AttackProcess(blue.pWarriors[j], red.pWarriors[i]);
                        end = true;
                        break;
                    }
                }
            }
            if (end == true)
                break;
        }
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int casenum;
    Headquarter RedHead, BlueHead;

    cin >> casenum;
    for (int casetime = 1; casetime <= casenum; casetime++)
    {
        cout << "Case " << casetime << ":" << endl;
        cin >> InitialLifeValue >> Citynum >> lostloyal >> endtime;

        memset(tempdragon, 0, sizeof(tempdragon));
        memset(tempninjia, 0, sizeof(tempninjia));
        memset(tempiceman, 0, sizeof(tempiceman));
        memset(templion, 0, sizeof(templion));
        memset(tempwolf, 0, sizeof(tempwolf));
        dragonindex = 0, ninjiaindex = 0, icemanindex = 0, lionindex = 0, wolfindex = 0;
        EndWar[0] = false;
        EndWar[1] = false;

        for (int i = 0; i < WARRIOR_NUM; i++)
        {
            cin >> LifeValue[i];
        }
        for (int i = 0; i < WARRIOR_NUM; i++)
            cin >> ForceValue[i];
        RedHead.Init(0, InitialLifeValue);
        BlueHead.Init(1, InitialLifeValue);
        nTime = 0;
        nMinute = 0;
        for (;;)
        {
            if (EndWar[0] == true || EndWar[1] == true)
                break;
            if (nMinute >= 60)
            {
                nMinute -= 60;
                nTime++;
            }
            if (nMinute == 0)
            {
                RedHead.Produce(nMinute);
                BlueHead.Produce(nMinute);
            }
            else if (nMinute == 5)
            {
                LionFlee(nMinute);
            }
            else if (nMinute == 10)
            {
                IcemanLost();
                LionLost();
                RedHead.March(nMinute);
                BlueHead.March(nMinute);
                ifend(RedHead, BlueHead, 0);
                MarchProcess(RedHead, BlueHead, nMinute);
                ifend(RedHead, BlueHead, 1);
            }
            else if (nMinute == 35)
            {
                RobProcess(RedHead, BlueHead, nMinute);
            }
            else if (nMinute == 40)
            {
                Fight(RedHead, BlueHead);
            }
            else if (nMinute == 50)
            {
                RedHead.Report(nMinute);
                BlueHead.Report(nMinute);
            }
            else if (nMinute == 55)
            {
                WarriorReport(RedHead, BlueHead, nMinute);
            }
            nMinute += 5;
            if (nTime * 60 + nMinute > endtime)
                EndWar[0] = true;
        }
    }
}