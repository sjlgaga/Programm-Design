#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int ch[100005];
long long ans;
long long dp[100005][2]; // dp[i][0]前i个且第i个没拿，dp[i][1]前i个第i个拿
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        memset(ch, 0, sizeof(ch));
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
            cin >> ch[i];
        dp[1][0] = 0;
        dp[1][1] = ch[1];
        for (int i = 2; i <= n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + ch[i];
        }
        cout << max(dp[n][0], dp[n][1]) << endl;
    }
}