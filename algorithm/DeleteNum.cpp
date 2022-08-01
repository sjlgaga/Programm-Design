#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int num[1005], dp[1005][1005]; // dp[i][j]代表前i个数被删除j个数后的最大值
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, n;
    cin >> t;
    while (t--)
    {
        memset(num, 0, sizeof(num));
        memset(dp, 0, sizeof(dp));
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> num[i];
        if (num[1] == 1)
            dp[1][0] = 1;
        else
            dp[1][0] = 0;
        dp[1][1] = 0;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0)
                {
                    if (num[i] == i)
                        dp[i][0] = dp[i - 1][0] + 1;
                    else
                        dp[i][0] = dp[i - 1][0];
                }
                else
                {
                    if (num[i] == i - j)
                        dp[i][j] = max(dp[i - 1][j] + 1, dp[i - 1][j - 1]);
                    else
                        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans = max(ans, dp[n][i]);
        cout << ans << endl;
    }
}