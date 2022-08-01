#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int w[3405], d[3405], dp[12885];
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> d[i];
    for (int i = 0; i <= m; i++)
    {
        if (i < w[1])
            dp[i] = 0;
        else
            dp[i] = d[1];
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = m; j >= w[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - w[i]] + d[i]);
        }
    }
    cout << dp[m];
}