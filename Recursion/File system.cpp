#include <iostream>
#include <cstring>
#include <set>
using namespace std;
bool flag = true;
void system(string dirname, int layer)
{
    for (int i = 1; i <= layer; i++)
    {
        cout << "|";
        for (int j = 1; j <= 5; j++)
            cout << " ";
    }
    cout << dirname << endl;
    string s;
    multiset<string> filename;
    while (flag)
    {
        cin >> s;
        if (s[0] == 'f')
            filename.insert(s);
        else if (s[0] == 'd')
            system(s, layer + 1);
        else if (s[0] == ']')
            break;
        else if (s[0] == '*')
            flag = false;
    }
    for (auto k : filename)
    {
        for (int i = 1; i <= layer; i++)
        {
            cout << "|";
            for (int j = 1; j <= 5; j++)
                cout << " ";
        }
        cout << k << endl;
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int casenum = 0;
    char c = cin.peek();
    while (c != '#')
    {
        casenum++;
        cout << "DATA SET " << casenum << ":" << endl;
        flag = true;
        system("ROOT", 0);
        cout << endl;
        cin.get();
        c = cin.peek();
    }
}