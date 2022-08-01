#include <iostream>
#include <cstring>
#include <algorithm>
#include <stdlib.h>
#define maxn 55
#define infinite 999999999
using namespace std;
string anminvalue[maxn][maxn];
string add(string a, string b)
{
    int numa[maxn], numb[maxn];
    memset(numa, 0, sizeof(numa));
    memset(numb, 0, sizeof(numb));
    string ans;
    int lena = a.size(), lenb = b.size();
    for (int i = 0; i < lena; i++)
        numa[i] = a[lena - 1 - i] - '0';
    for (int i = 0; i < lenb; i++)
        numb[i] = b[lenb - 1 - i] - '0';
    int maxlen = lena;
    if (lenb > maxlen)
        maxlen = lenb;
    for (int i = 0; i < maxlen; i++)
    {
        numa[i] += numb[i];
        if (numa[i] >= 10)
        {
            numa[i] -= 10;
            numa[i + 1]++;
        }
    }
    if (numa[maxlen])
        maxlen++;
    for (int i = 0; i < maxlen; i++)
        ans += numa[maxlen - 1 - i] + '0';
    return ans;
}
string mis(string a, string b)
{
    if (a.length() < b.length())
        return a;
    else if (a.length() > b.length())
        return b;
    else
    {
        if (a < b)
            return a;
        else
            return b;
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int m;
    string s;
    while (cin >> m)
    {
        cin >> s;
        int len = s.length();
        for (int i = 0; i < len; i++)
            anminvalue[0][i] = s.substr(0, i + 1);
        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j < len; j++)
            {
                if (j < i)
                {
                    string temp;
                    for (int u = 0; u < maxn; u++)
                        temp += "9";
                    anminvalue[i][j] = temp;
                }
                else
                {
                    string temp;
                    for (int u = 0; u < maxn; u++)
                        temp += "9";
                    for (int k = 0; k < j; k++)
                    {
                        temp = mis(temp, add(anminvalue[i - 1][k], s.substr(k + 1, j - k)));
                    }
                    anminvalue[i][j] = temp;
                }
            }
        }
        cout << anminvalue[m][len - 1] << endl;
        }
}