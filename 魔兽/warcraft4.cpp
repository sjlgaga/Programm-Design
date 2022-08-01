#include <iostream>
#include <cstring>
#include <cstdio>
#include <iomanip>
using namespace std;
const int WARRIOR_NUM = 5;
bool EndWar = false;
int nTime;
int nMinute;
string WarriorName[WARRIOR_NUM] = {"dragon", "ninja", "iceman", "lion", "wolf"};
string WeaponName[3] = {"sword", "bomb", "arrow"};
int LifeValue[WARRIOR_NUM];
int ForceValue[WARRIOR_NUM];
int InitialLifeValue, Citynum, lostloyal, endtime, arrowforce;
bool redheadprint, blueheadprint;
int redval = 0, blueval = 0;
int rednum = 0, bluenum = 0;
int dragonindex = 0, ninjiaindex = 0, icemanindex = 0, lionindex = 0, wolfindex = 0;
// const value named processes

// class definition*************************************************
class Headquarter;
class Warrior;
class CCity
{
public:
    int cityvalue;
    Warrior *redone;
    Warrior *blueone;
    int rednum;
    int bluenum;
    bool headprint;
    int flag; // 1 is red,-1 is blue,0 is none
    int redwin;
    int bluewin;

    CCity()
    {
        cityvalue = 0;
        redone = NULL;
        blueone = NULL;
        rednum = 0;
        bluenum = 0;
        headprint = false;
        flag = 0;
        redwin = 0;
        bluewin = 0;
    }
};

class Warrior
{
public:
    string color;
    int kindno;
    int no;
    int HP;
    int Force;
    int Location;
    int weapon[3]; // 0 is sword 1 is bomb 2 is arrow
    double morale;
    int loyalty;
    int leftval;

public:
    virtual void Init(string co, int kindno_, int no_, int hp, int force);
    virtual void ProducePrint(int minu);
    void LionLost();
    void MarchPrint(int minu);
    void MarchStep();
    void report(int minu);
    void Yell();
};

class CDragon : public Warrior
{
public:
    void Init(string co, int kindno_, int no_, int hp, int force, int val);
    void ProducePrint(int minu);
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
public:
    void Init(string co, int kindno_, int no_, int hp, int force, int loya);
    void LionLost();
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
    int produceindex;
    Warrior *pWarriors[1000];

public:
    ~Headquarter();
    friend class Warrior;
    static int produceturn[2][WARRIOR_NUM];
    void Init(int colr_, int lv);
    string GetColor();
    void Produce(int minu);
    void LionRan(int minu);
    void March(int minu);
    void Report(int minu);
};
int Headquarter::produceturn[2][WARRIOR_NUM] = {{2, 3, 4, 1, 0}, {3, 0, 1, 2, 4}};
// soldier storage
CDragon tempdragon[500];
CNinjia tempninjia[500];
CIceman tempiceman[500];
CLion templion[500];
CWolf tempwolf[500];
CCity ccity[25];

// class definition
//***********************************************************************************************
//***********************************************************************************************

//************************************************************************************************
// Warrior Function
//*********************************************************************************
void Warrior::Init(string co, int kindno_, int no_, int hp, int force)
{
    color = co;
    kindno = kindno_;
    no = no_;
    HP = hp;
    Force = force;
    memset(weapon, 0, sizeof(weapon));
    if (co == "red")
        Location = 0;
    else if (co == "blue")
        Location = Citynum + 1;
    if (no_ % 3 == 0)
        weapon[0] += force / 5;
    else if (no_ % 3 == 2)
        weapon[2] += 3;
    else
        weapon[1]++;
}
void Warrior::ProducePrint(int minu)
{
    cout << setw(3) << setfill('0') << nTime << ":" << setw(2) << setfill('0') << minu << " " << color << " " << WarriorName[kindno] << " " << no << " born" << endl;
}
void Warrior::MarchStep()
{
    if (color == "red" && Location != Citynum + 1)
        Location++;
    else if (color == "blue" && Location != 0)
        Location--;
}
void Warrior::MarchPrint(int minu)
{
    printf("%03d:%02d %s %s %d marched to city %d with %d elements and force %d\n", nTime, minu, color.c_str(), WarriorName[kindno].c_str(), no, Location, HP, Force);
}
void Warrior::report(int minu)
{
    printf("%03d:%02d %s %s %d has ", nTime, minu, color.c_str(), WarriorName[kindno].c_str(), no);
    if (weapon[2] > 0)
    {
        cout << "arrow"
             << "(" << weapon[2] << ")";
        if (weapon[0] != 0 || weapon[1] != 0)
            cout << ",";
        else
            cout << endl;
    }
    if (weapon[1] > 0)
    {
        cout << "bomb";
        if (weapon[0] != 0)
            cout << ",";
        else
            cout << endl;
    }
    if (weapon[0] > 0)
    {
        cout << "sword"
             << "(" << weapon[0] << ") " << endl;
    }
    if (weapon[0] == 0 && weapon[1] == 0 && weapon[2] == 0)
        cout << "no weapon" << endl;
}
void Warrior::Yell()
{
    printf("%03d:40 %s dragon %d yelled in city %d\n", nTime, color.c_str(), no, Location);
}
//***********************************************************************************
// Warrior functions
//*****************************************************

//***************************************************************************
// special warrior function
//***************************************************************************
void CDragon::Init(string co, int kindno_, int no_, int hp, int force, int val)
{

    color = co;
    kindno = kindno_;
    no = no_;
    HP = hp;
    Force = force;
    morale = (double)val / HP;
    memset(weapon, 0, sizeof(weapon));
    if (co == "red")
        Location = 0;
    else if (co == "blue")
        Location = Citynum + 1;
    if (no_ % 3 == 0)
        weapon[0] += force / 5;
    else if (no_ % 3 == 2)
        weapon[2] += 3;
    else
        weapon[1]++;
}
void CDragon::ProducePrint(int minu)
{
    cout << setw(3) << setfill('0') << nTime << ":" << setw(2) << setfill('0') << minu << " " << color << " " << WarriorName[kindno] << " " << no << " born" << endl;
    printf("Its morale is %.2f\n", morale);
}
void CNinjia::Init(string co, int kindno_, int no_, int hp, int force)
{
    color = co;
    kindno = kindno_;
    no = no_;
    HP = hp;
    Force = force;
    memset(weapon, 0, sizeof(weapon));
    if (no_ % 3 == 0)
        weapon[0] += force / 5;
    else if (no_ % 3 == 2)
        weapon[2] += 3;
    else
        weapon[1]++;
    if ((no_ + 1) % 3 == 0)
        weapon[0] += force / 5;
    else if ((no_ + 1) % 3 == 2)
        weapon[2] += 3;
    else
        weapon[1]++;
    if (co == "red")
        Location = 0;
    else if (co == "blue")
        Location = Citynum + 1;
}
void CLion::Init(string co, int kindno_, int no_, int hp, int force, int loya)
{
    color = co;
    kindno = kindno_;
    no = no_;
    HP = hp;
    leftval = HP;
    Force = force;
    memset(weapon, 0, sizeof(weapon));
    loyalty = loya;
    if (co == "red")
        Location = 0;
    else if (co == "blue")
        Location = Citynum + 1;
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
    memset(weapon, 0, sizeof(weapon));
    if (co == "red")
        Location = 0;
    else if (co == "blue")
        Location = Citynum + 1;
}
void IcemanLost()
{
    for (int i = 1; i <= icemanindex; i++)
    {
        if (tempiceman[i].HP <= 0)
            continue;
        if (tempiceman[i].color == "red" && (tempiceman[i].Location + 1) % 2 == 0)
        {
            if (tempiceman[i].HP > 9)
                tempiceman[i].HP -= 9;
            else
                tempiceman[i].HP = 1;
            tempiceman[i].Force += 20;
        }
        else if (tempiceman[i].color == "blue" && (Citynum + 1 - tempiceman[i].Location + 1) % 2 == 0)
        {
            if (tempiceman[i].HP > 9)
                tempiceman[i].HP -= 9;
            else
                tempiceman[i].HP = 1;
            tempiceman[i].Force += 20;
        }
    }
}
void Warrior::LionLost()
{
    loyalty -= lostloyal;
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
            if (templion[i].Location == k && k != Citynum + 1)
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
            if (templion[i].Location == k && k != 0)
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
//***************************************************************************
// special warrior function
//***************************************************************************

// Headquarter function
//*******************************************************************************************************
//****************************************************************************
void Headquarter::Init(int clor_, int lv)
{
    HeadLifeValue = lv;
    colour = clor_;
    produceindex = -1;
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
            temp.Init(this->GetColor(), kind, WarriorNum, LifeValue[kind], ForceValue[kind], HeadLifeValue);
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
        produceindex--;
        if (produceindex < 0)
            produceindex = 4;
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
// Headquarter function
//*******************************************************************************************************
//****************************************************************************
// Incident Functions
//******************************************************
void CitySet(Headquarter &a, Headquarter &b)
{
    for (int i = 0; i <= Citynum + 1; i++)
    {
        ccity[i].redone = NULL;
        ccity[i].blueone = NULL;
    }
    for (int i = 0; i <= Citynum + 1; i++)
    {
        for (int j = 1; j <= a.WarriorNum; j++)
        {
            if (a.pWarriors[j]->HP <= 0)
                continue;
            if (a.pWarriors[j]->Location == i)
            {
                ccity[i].redone = a.pWarriors[j];
                break;
            }
        }
        for (int j = 1; j <= b.WarriorNum; j++)
        {
            if (b.pWarriors[j]->HP <= 0)
                continue;
            if (b.pWarriors[j]->Location == i)
            {
                ccity[i].blueone = b.pWarriors[j];
                break;
            }
        }
    }
}
void Arrow(Warrior *shoot, Warrior *shot)
{
    if (shoot->weapon[2] <= 0)
        return;
    shoot->weapon[2] -= 1;
    shot->HP -= arrowforce;
    if (shot->HP <= 0)
    {
        shot->HP = 0;
        printf("%03d:35 %s %s %d shot and killed %s %s %d\n", nTime, shoot->color.c_str(), WarriorName[shoot->kindno].c_str(), shoot->no, shot->color.c_str(), WarriorName[shot->kindno].c_str(), shot->no);
    }

    else
        printf("%03d:35 %s %s %d shot\n", nTime, shoot->color.c_str(), WarriorName[shoot->kindno].c_str(), shoot->no);
}
void ArrowProcess()
{
    for (int i = 1; i <= Citynum; i++)
    {
        if (ccity[i].redone != NULL && ccity[i + 1].blueone != NULL && i != Citynum)
            Arrow(ccity[i].redone, ccity[i + 1].blueone);
        if (ccity[i].blueone != NULL && ccity[i - 1].redone != NULL && i != 1)
            Arrow(ccity[i].blueone, ccity[i - 1].redone);
    }
}
void Bomb(Warrior *bomber, Warrior *bombed, bool fla)
{
    if (bomber->weapon[1] <= 0)
        return;
    int dam, harm, bomberHP = bomber->HP, bombedHP = bombed->HP;
    if (bomberHP <= 0 && bombedHP <= 0)
        return;
    if (fla == 1)
    {
        dam = bomber->Force + bomber->weapon[0];
        harm = bombed->Force / 2 + bombed->weapon[0];
        if (bombedHP - dam > 0 && bombed->kindno != 1)
        {
            bomberHP -= harm;
            if (bomberHP <= 0)
            {
                bomber->weapon[1]--;
                bomber->HP = -1;
                bombed->HP = -1;
                printf("%03d:38 %s %s %d used a bomb and killed %s %s %d\n", nTime, bomber->color.c_str(), WarriorName[bomber->kindno].c_str(), bomber->no, bombed->color.c_str(), WarriorName[bombed->kindno].c_str(), bombed->no);
            }
        }
    }
    else if (fla == 0)
    {
        harm = bombed->Force + bombed->weapon[0];
        if (bomberHP - harm <= 0)
        {
            bomber->weapon[1]--;
            bomber->HP = -1;
            bombed->HP = -1;
            printf("%03d:38 %s %s %d used a bomb and killed %s %s %d\n", nTime, bomber->color.c_str(), WarriorName[bomber->kindno].c_str(), bomber->no, bombed->color.c_str(), WarriorName[bombed->kindno].c_str(), bombed->no);
        }
    }
}
void BombProcess()
{
    for (int i = 1; i <= Citynum; i++)
    {
        if (ccity[i].redone == NULL || ccity[i].blueone == NULL)
            continue;
        if (ccity[i].redone->HP <= 0 || ccity[i].blueone->HP <= 0)
            continue;
        if (ccity[i].flag == 1 || (ccity[i].flag == 0 && i % 2 == 1))
        {
            Bomb(ccity[i].redone, ccity[i].blueone, 1);
            Bomb(ccity[i].blueone, ccity[i].redone, 0);
        }
        else if (ccity[i].flag == -1 || (ccity[i].flag == 0 && i % 2 == 0))
        {
            Bomb(ccity[i].redone, ccity[i].blueone, 0);
            Bomb(ccity[i].blueone, ccity[i].redone, 1);
        }
    }
}
void GetValue(Headquarter &a, Headquarter &b)
{
    for (int i = 1; i <= Citynum; i++)
    {
        if (ccity[i].redone != NULL && ccity[i].blueone == NULL)
        {
            a.HeadLifeValue += ccity[i].cityvalue;
            printf("%03d:30 %s %s %d earned %d elements for his headquarter\n", nTime,
                   ccity[i].redone->color.c_str(), WarriorName[ccity[i].redone->kindno].c_str(), ccity[i].redone->no, ccity[i].cityvalue);
            ccity[i].cityvalue = 0;
        }
        else if (ccity[i].blueone != NULL && ccity[i].redone == NULL)
        {
            b.HeadLifeValue += ccity[i].cityvalue;
            printf("%03d:30 %s %s %d earned %d elements for his headquarter\n", nTime,
                   ccity[i].blueone->color.c_str(), WarriorName[ccity[i].blueone->kindno].c_str(), ccity[i].blueone->no, ccity[i].cityvalue);
            ccity[i].cityvalue = 0;
        }
    }
}
void MarchProcess(int min)
{
    if (ccity[0].blueone != NULL)
    {
        rednum++;
        ccity[0].blueone->Location = -1;
        printf("%03d:10 %s %s %d reached red headquarter with %d elements and force %d\n", nTime, "blue", WarriorName[ccity[0].blueone->kindno].c_str(), ccity[0].blueone->no, ccity[0].blueone->HP, ccity[0].blueone->Force);
    }
    if (rednum == 2)
    {
        EndWar = true;
        cout << setw(3) << setfill('0') << nTime << ":" << setw(2) << setfill('0') << "10"
             << " red headquarter was taken" << endl;
    }
    for (int i = 1; i <= Citynum; i++)
    {
        if (ccity[i].redone != NULL)
        {
            ccity[i].redone->MarchPrint(min);
        }
        if (ccity[i].blueone != NULL)
        {
            ccity[i].blueone->MarchPrint(min);
        }
    }
    if (ccity[Citynum + 1].redone != NULL)
    {
        printf("%03d:10 %s %s %d reached blue headquarter with %d elements and force %d\n", nTime, "red", WarriorName[ccity[Citynum + 1].redone->kindno].c_str(), ccity[Citynum + 1].redone->no, ccity[Citynum + 1].redone->HP, ccity[Citynum + 1].redone->Force);
        bluenum++;
        ccity[Citynum + 1].redone->Location = 30;
    }
    if (bluenum == 2)
    {
        EndWar = true;
        cout << setw(3) << setfill('0') << nTime << ":" << setw(2) << setfill('0') << "10"
             << " blue headquarter was taken" << endl;
    }
}
void WarriorReport(Headquarter &red, Headquarter &blue, int minu)
{
    for (int i = red.WarriorNum; i >= 1; i--)
    {
        if (red.pWarriors[i]->HP <= 0)
            continue;
        red.pWarriors[i]->report(minu);
    }
    for (int i = 1; i <= blue.WarriorNum; i++)
    {
        if (blue.pWarriors[i]->HP <= 0)
            continue;
        blue.pWarriors[i]->report(minu);
    }
}
void Rob(Warrior *rob, Warrior *robbed)
{
    for (int i = 0; i <= 2; i++)
    {
        if (rob->weapon[i] == 0 && robbed->weapon[i] != 0)
        {
            rob->weapon[i] += robbed->weapon[i];
            robbed->weapon[i] = 0;
        }
    }
}
void Attack(Warrior *attacker, Warrior *victim, int cityno)
{
    int dam = attacker->Force + attacker->weapon[0];
    int harm = victim->Force / 2 + victim->weapon[0];
    victim->HP -= dam;
    attacker->weapon[0] = attacker->weapon[0] * 8 / 10;
    printf("%03d:40 %s %s %d attacked %s %s %d in city %d with %d elements and force %d\n", nTime, attacker->color.c_str(), WarriorName[attacker->kindno].c_str(), attacker->no,
           victim->color.c_str(), WarriorName[victim->kindno].c_str(), victim->no,
           cityno, attacker->HP, attacker->Force);
    if (victim->HP > 0 && victim->kindno != 1)
    {
        attacker->HP -= harm;
        victim->weapon[0] = victim->weapon[0] * 8 / 10;
        printf("%03d:40 %s %s %d fought back against %s %s %d in city %d\n", nTime, victim->color.c_str(), WarriorName[victim->kindno].c_str(), victim->no,
               attacker->color.c_str(), WarriorName[attacker->kindno].c_str(), attacker->no, cityno);
    }
}
void Fight(Headquarter &red, Headquarter &blue)
{
    for (int i = 1; i <= Citynum; i++)
    {
        if (ccity[i].redone == NULL || ccity[i].blueone == NULL)
            continue;
        if (ccity[i].redone->HP <= 0 && ccity[i].blueone->HP <= 0)
            continue;
        int win = 0; // 1 redwin -1 bluewin 0 draw
        ccity[i].redone->leftval = ccity[i].redone->HP;
        ccity[i].blueone->leftval = ccity[i].blueone->HP;
        if (ccity[i].redone->HP > 0 && ccity[i].blueone->HP <= 0)
            win = 1;
        else if (ccity[i].redone->HP <= 0 && ccity[i].blueone->HP > 0)
            win = -1;
        else
        {
            if (ccity[i].flag == 1 || (ccity[i].flag == 0 && (i % 2 == 1)))
                Attack(ccity[i].redone, ccity[i].blueone, i);
            else if (ccity[i].flag == -1 || (ccity[i].flag == 0 && (i % 2 == 0)))
                Attack(ccity[i].blueone, ccity[i].redone, i);
            if (ccity[i].redone->HP <= 0 && ccity[i].blueone->HP <= 0)
                win = 0;
            else if (ccity[i].redone->HP > 0 && ccity[i].blueone->HP > 0)
            {
                win = 0;
                if (ccity[i].redone->kindno == 0)
                    ccity[i].redone->morale -= 0.2;
                if (ccity[i].blueone->kindno == 0)
                    ccity[i].blueone->morale -= 0.2;
                ccity[i].redwin = 0;
                ccity[i].bluewin = 0;
                if (ccity[i].redone->kindno == 0)
                {
                    if ((ccity[i].flag == 1 || (ccity[i].flag == 0 && i % 2 == 1)))
                    {
                        if (ccity[i].redone->morale > 0.8)
                            ccity[i].redone->Yell();
                    }
                }
                if (ccity[i].blueone->kindno == 0)
                {
                    if ((ccity[i].flag == -1 || (ccity[i].flag == 0 && i % 2 == 0)))
                    {
                        if (ccity[i].blueone->morale > 0.8)
                            ccity[i].blueone->Yell();
                    }
                }
                if (ccity[i].blueone->kindno == 3)
                    ccity[i].blueone->LionLost();
                if (ccity[i].redone->kindno == 3)
                    ccity[i].redone->LionLost();
            }
            else if (ccity[i].redone->HP > 0 && ccity[i].blueone->HP <= 0)
            {
                win = 1;
                printf("%03d:40 %s %s %d was killed in city %d\n",
                       nTime, ccity[i].blueone->color.c_str(), WarriorName[ccity[i].blueone->kindno].c_str(), ccity[i].blueone->no, i);
            }
            else if (ccity[i].redone->HP <= 0 && ccity[i].blueone->HP > 0)
            {
                win = -1;
                printf("%03d:40 %s %s %d was killed in city %d\n",
                       nTime, ccity[i].redone->color.c_str(), WarriorName[ccity[i].redone->kindno].c_str(), ccity[i].redone->no, i);
            }
        }

        if (win == 1)
        {
            if (red.HeadLifeValue >= 8)
            {
                ccity[i].redone->HP += 8;
                red.HeadLifeValue -= 8;
            }
            if (ccity[i].redone->kindno == 0)
            {
                ccity[i].redone->morale += 0.2;
                if ((ccity[i].flag == 1 || (ccity[i].flag == 0 && i % 2 == 1)))
                {
                    if (ccity[i].redone->morale > 0.8)
                        ccity[i].redone->Yell();
                }
            }
            if (ccity[i].redone->kindno == 4)
                Rob(ccity[i].redone, ccity[i].blueone);
            if (ccity[i].blueone->kindno == 3)
                ccity[i].redone->HP += ccity[i].blueone->leftval;

            redval += ccity[i].cityvalue;
            printf("%03d:40 %s %s %d earned %d elements for his headquarter\n", nTime,
                   ccity[i].redone->color.c_str(), WarriorName[ccity[i].redone->kindno].c_str(), ccity[i].redone->no, ccity[i].cityvalue);
            ccity[i].cityvalue = 0;

            ccity[i].redwin++;
            ccity[i].bluewin = 0;
            if (ccity[i].redwin >= 2 && ccity[i].flag != 1)
            {
                ccity[i].flag = 1;
                printf("%03d:40 red flag raised in city %d\n", nTime, i);
            }
        }
        else if (win == -1)
        {
            if (blue.HeadLifeValue >= 8)
            {
                ccity[i].blueone->HP += 8;
                blue.HeadLifeValue -= 8;
            }
            if (ccity[i].blueone->kindno == 0)
            {
                ccity[i].blueone->morale += 0.2;
                if ((ccity[i].flag == -1 || (ccity[i].flag == 0 && i % 2 == 0)))
                {
                    if (ccity[i].blueone->morale > 0.8)
                        ccity[i].blueone->Yell();
                }
            }
            if (ccity[i].blueone->kindno == 4)
                Rob(ccity[i].blueone, ccity[i].redone);
            if (ccity[i].redone->kindno == 3)
                ccity[i].blueone->HP += ccity[i].redone->leftval;

            blueval += ccity[i].cityvalue;
            printf("%03d:40 %s %s %d earned %d elements for his headquarter\n", nTime,
                   ccity[i].blueone->color.c_str(), WarriorName[ccity[i].blueone->kindno].c_str(), ccity[i].blueone->no, ccity[i].cityvalue);
            ccity[i].cityvalue = 0;

            ccity[i].bluewin++;
            ccity[i].redwin = 0;
            if (ccity[i].bluewin >= 2 && ccity[i].flag != -1)
            {
                ccity[i].flag = -1;
                printf("%03d:40 blue flag raised in city %d\n", nTime, i);
            }
        }
    }
}
// Incident Functions
//******************************************************

int main()
{
    int casenum;
    Headquarter RedHead, BlueHead;

    cin >> casenum;
    for (int casetime = 1; casetime <= casenum; casetime++)
    {
        cout << "Case " << casetime << ":" << endl;
        cin >> InitialLifeValue >> Citynum >> arrowforce >> lostloyal >> endtime;

        memset(tempdragon, 0, sizeof(tempdragon));
        memset(tempninjia, 0, sizeof(tempninjia));
        memset(tempiceman, 0, sizeof(tempiceman));
        memset(templion, 0, sizeof(templion));
        memset(tempwolf, 0, sizeof(tempwolf));
        memset(ccity, 0, sizeof(ccity));
        dragonindex = 0, ninjiaindex = 0, icemanindex = 0, lionindex = 0, wolfindex = 0;
        rednum = 0, bluenum = 0;
        EndWar = false;

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
            if (EndWar == true)
                break;
            redval = 0;
            blueval = 0;
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
                BlueHead.March(nMinute);
                RedHead.March(nMinute);
                CitySet(RedHead, BlueHead);
                MarchProcess(nMinute);
            }
            else if (nMinute == 20)
            {
                for (int i = 1; i <= Citynum; i++)
                    ccity[i].cityvalue += 10;
            }
            else if (nMinute == 30)
            {
                GetValue(RedHead, BlueHead);
            }
            else if (nMinute == 35)
            {
                ArrowProcess();
            }
            else if (nMinute == 38)
            {
                BombProcess();
            }
            else if (nMinute == 40)
            {
                Fight(RedHead, BlueHead);
                RedHead.HeadLifeValue += redval;
                BlueHead.HeadLifeValue += blueval;
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
            if (nMinute == 35)
                nMinute += 3;
            else if (nMinute == 38)
                nMinute += 2;
            else
                nMinute += 5;
            if (nTime * 60 + nMinute > endtime)
                EndWar = true;
        }
    }
}