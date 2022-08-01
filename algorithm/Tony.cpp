#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int seishin, w[16], s[16], ans = 0;
int frontten = 0, lastfive = 0, sum = 0;
void dfs(int n)
{
    if (frontten > 5)
        return;
    if (n == 16 && lastfive >= frontten)
    {
        ans = max(ans, sum);
    }
    else if (n <= 10)
    {
        if (seishin >= s[n])
        {
            sum += w[n];
            seishin -= s[n];
            frontten++;
            dfs(n + 1);
            sum -= w[n];
            seishin += s[n];
            frontten--;
        }
        dfs(n + 1);
    }
    else if (n >= 11 && n <= 15)
    {
        if (seishin >= s[n])
        {
            sum += w[n];
            seishin -= s[n];
            lastfive++;
            dfs(n + 1);
            sum -= w[n];
            seishin += s[n];
            lastfive--;
        }
        dfs(n + 1);
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    memset(w, 0, sizeof(w));
    memset(s, 0, sizeof(s));
    cin >> seishin;
    for (int i = 1; i <= 15; i++)
        cin >> w[i] >> s[i];
    dfs(1);
    cout << ans;
}