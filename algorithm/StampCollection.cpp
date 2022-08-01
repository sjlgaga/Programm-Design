#include <iostream>
#include <cstring>
using namespace std;
int dp[1005], n, k, coin[105];
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    for (;;)
    {
        cin >> n >> k;
        if (n == 0 && k == 0)
            break;
        memset(coin, 0, sizeof(coin));
        for (int i = 1; i <= n; i++)
            cin >> coin[i];
        for (int i = 1; i <= k; i++)
            dp[i] = 1 << 30;
        for (int i = 1; i <= n; i++)
            dp[coin[i]] = 1;
        for (int i = 1; i <= k; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i - coin[j] > 0)
                {
                    if (dp[i - coin[j]] + 1 < dp[i])
                        dp[i] = dp[i - coin[j]] + 1;
                }
            }
        }
        if (dp[k] == 1 << 30)
            cout << -1 << endl;
        else
            cout << dp[k] << endl;
    }
}