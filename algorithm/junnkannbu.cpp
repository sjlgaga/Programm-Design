#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, ta, tb;
    cin >> n >> ta >> tb;
    int funca[105], funcb[105], sea[105], seb[105];
    for (int i = 1; i <= ta; i++)
        cin >> funca[i];
    for (int i = 1; i <= tb; i++)
        cin >> funcb[i];
    for (int i = 1; i <= ta; i++)
    {
        for (int j = i; j <= n; j += ta)
        {
            sea[j] = funca[i];
        }
    }
    for (int i = 1; i <= tb; i++)
    {
        for (int j = i; j <= n; j += tb)
            seb[j] = funcb[i];
    }
    int wina = 0, winb = 0;
    for (int i = 1; i <= n; i++)
    {
        if (sea[i] == seb[i])
            continue;
        if (sea[i] == 0)
        {
            if (seb[i] == 2)
                wina++;
            else
                winb++;
        }
        else if (sea[i] == 2)
        {
            if (seb[i] == 0)
                winb++;
            else
                wina++;
        }
        else if (sea[i] == 5)
        {
            if (seb[i] == 0)
                wina++;
            else
                winb++;
        }
    }
    if (wina > winb)
        cout << "A";
    else if (wina < winb)
        cout << "B";
    else
        cout << "draw";
}