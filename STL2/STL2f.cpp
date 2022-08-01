#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <iterator>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    typedef map<int, int> mint;
    mint mem;
    mem[1000000000] = 1;
    mint::iterator i;
    int id, power;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> id >> power;
        i = mem.lower_bound(power);
        if (i == mem.begin())
            cout << id << " " << i->second << endl;
        else if (i == mem.end())
        {
            i--;
            cout << id << " " << (i)->second << endl;
        }

        else
        {
            int right = i->first;
            int rightno = i->second;
            i--;
            int left = i->first;
            int leftno = i->second;
            if (abs(left - power) > abs(right - power))
            {
                i++;
                cout << id << " " << i->second << endl;
            }
            else if (abs(left - power) < abs(right - power))
                cout << id << " " << i->second << endl;
            else if (abs(left - power) == abs(right - power))
            {
                if (rightno < leftno)
                    i++;
                cout << id << " " << i->second << endl;
            }
        }
        i = mem.find(power);
        if (i == mem.end() || i->second > id)
            mem[power] = id;
    }
}