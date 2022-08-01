#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
int ti, sumblood, rblood, bblood, rpi, bpi;
string job[5] = {"dragon", "ninja", "iceman", "lion", "wolf"};
string weapon[3] = {"sword", "bomb", "arrow"};
int redturn[5] = {2, 3, 4, 1, 0};
int rednum[5];
int blueturn[5] = {3, 0, 1, 2, 4};
int bluenum[5];
int bloodlist[5];
class csoldier
{
public:
    string name;
    string color;
    int blood;
    int num;

public:
    csoldier(string s1, string s2, int n1, int n2)
    {
        name = s1;
        color = s2;
        blood = n1;
        num = n2;
    }
    void print()
    {
        cout << setfill('0') << setw(3) << ti << " " << color << " " << name << " " << ti + 1 << " born with strength " << blood << "," << num << " " << name << " in " << color << " headquarter" << endl;
    }
};
class cdragon : public csoldier
{
    int weap;
    double loyal;

public:
    cdragon(string s1, string s2, int n1, int n2) : csoldier(s1, s2, n1, n2)
    {
        weap = (ti + 1) % 3;
        if (color == "red")
            loyal = double(rblood) / double(bloodlist[0]);
        else
            loyal = double(bblood) / double(bloodlist[0]);
    }
    void addprint()
    {
        cout << "It has a " << weapon[weap] << ",and it's morale is " << fixed << setprecision(2) << loyal << endl;
    }
};
class cninjia : public csoldier
{
    int weap1, weap2;

public:
    cninjia(string s1, string s2, int n1, int n2) : csoldier(s1, s2, n1, n2)
    {
        weap1 = (ti + 1) % 3;
        weap2 = (ti + 2) % 3;
    }
    void addprint()
    {
        cout << "It has a " << weapon[weap1] << " and a " << weapon[weap2] << endl;
    }
};
class ciceman : public csoldier
{
    int weap;

public:
    ciceman(string s1, string s2, int n1, int n2) : csoldier(s1, s2, n1, n2)
    {
        weap = (ti + 1) % 3;
    }
    void addprint()
    {
        cout << "It has a " << weapon[weap] << endl;
    }
};
class clion : public csoldier
{
    int loyal;

public:
    void addprint()
    {
        cout << "It's loyalty is " << loyal << endl;
    }

public:
    clion(string s1, string s2, int n1, int n2) : csoldier(s1, s2, n1, n2)
    {

        if (color == "red")
            loyal = rblood;
        else
            loyal = bblood;
    }
};
class cwolf : public csoldier
{
public:
    cwolf(string s1, string s2, int n1, int n2) : csoldier(s1, s2, n1, n2){};
};

void ga(int d, string name, string color, int blood, int num)
{
    if (d == 0)
    {
        cdragon dragon(name, color, blood, num);
        dragon.print();
        dragon.addprint();
    }
    else if (d == 1)
    {
        cninjia ninjia(name, color, blood, num);
        ninjia.print();
        ninjia.addprint();
    }
    else if (d == 2)
    {
        ciceman iceman(name, color, blood, num);
        iceman.print();
        iceman.addprint();
    }
    else if (d == 3)
    {
        clion lion(name, color, blood, num);
        lion.print();
        lion.addprint();
    }
    else if (d == 4)
    {
        cwolf wolf(name, color, blood, num);
        wolf.print();
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int roll;
    cin >> roll;
    for (int t = 1; t <= roll; t++)
    {

        ti = 0, rpi = 0, bpi = 0;
        cin >> sumblood;
        rblood = sumblood;
        bblood = sumblood;
        bool rstop = false;
        bool bstop = false;
        memset(rednum, 0, sizeof(rednum));
        memset(bluenum, 0, sizeof(bluenum));
        // initializing

        for (int i = 0; i < 5; i++)
        {
            cin >> bloodlist[i];
        }
        cout << "Case:" << t << endl;

        int minblood = 10001;
        for (int i = 0; i < 5; i++)
        {
            if (bloodlist[i] < minblood)
            {

                minblood = bloodlist[i];
            }
        } // get blood

        for (;; ti++)
        {
            if (rstop == false)
            {
                if (rblood < minblood)
                {
                    cout << setfill('0') << setw(3) << ti << " "
                         << "red headquarter stops making warriors" << endl;
                    rstop = true;
                }
                else
                {
                    for (;;)
                    {
                        if (rblood >= bloodlist[redturn[rpi % 5]])
                        {
                            int digt = redturn[rpi % 5];
                            rednum[digt]++;
                            rblood -= bloodlist[digt];
                            ga(digt, job[digt], "red", bloodlist[digt], rednum[digt]);
                            rpi++;
                            break;
                        }
                        rpi++;
                    }
                }
            }

            if (bstop == false)
            {
                if (bblood < minblood)
                {
                    cout << setfill('0') << setw(3) << ti << " "
                         << "blue headquarter stops making warriors" << endl;
                    bstop = true;
                }
                else
                {
                    for (;;)
                    {
                        if (bblood >= bloodlist[blueturn[bpi % 5]])
                        {
                            int digt = blueturn[bpi % 5];
                            bluenum[digt]++;
                            bblood -= bloodlist[digt];
                            ga(digt, job[digt], "blue", bloodlist[digt], bluenum[digt]);
                            bpi++;
                            break;
                        }
                        bpi++;
                    }
                }
            }

            if (rstop == true && bstop == true)
            {
                break;
            }
        }
    }
}