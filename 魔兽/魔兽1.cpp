#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
int ti, sumblood, rblood, bblood, rpi, bpi;
string job[5] = {"dragon", "ninja", "iceman", "lion", "wolf"};
class redwar
{
public:
    string name;
    int blood;
    int num;

    redwar(string s, int n)
    {
        name = s;
        blood = n;
        num = 0;
    }
    void process()
    {
        num++;
        rblood -= blood;
    }
    void print()
    {
        cout << setfill('0') << setw(3) << ti << " red " << name << " " << ti + 1 << " born with strength " << blood << "," << num << " " << name << " in red headquarter" << endl;
    }
};
class bluewar
{
public:
    string name;
    int blood;
    int num;

public:
    bluewar(string s, int n)
    {
        name = s;
        blood = n;
        num = 0;
    }
    void process()
    {
        num++;
        bblood -= blood;
    }
    void print()
    {
        cout << setfill('0') << setw(3) << ti << " blue " << name << " " << ti + 1 << " born with strength " << blood << "," << num << " " << name << " in blue headquarter" << endl;
    }
};
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

        int bloodlist[5];
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
        }

        redwar red[5] = {redwar(job[2], bloodlist[2]), redwar(job[3], bloodlist[3]), redwar(job[4], bloodlist[4]), redwar(job[1], bloodlist[1]), redwar(job[0], bloodlist[0])};
        bluewar blue[5] = {bluewar(job[3], bloodlist[3]), bluewar(job[0], bloodlist[0]), bluewar(job[1], bloodlist[1]), bluewar(job[2], bloodlist[2]), bluewar(job[4], bloodlist[4])};
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
                        if (rblood >= red[rpi % 5].blood)
                        {
                            red[rpi % 5].process();
                            red[rpi % 5].print();
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
                        if (bblood >= blue[bpi % 5].blood)
                        {
                            blue[bpi % 5].process();
                            blue[bpi % 5].print();
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