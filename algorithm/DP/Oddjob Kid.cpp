#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int hei[105];
    int dp[105];
    int t, n;
    cin >> t;
    while (t--)
    {
        memset(hei, 0, sizeof(hei));
        memset(dp, 0, sizeof(dp));
        cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; i++)
            cin >> hei[i];
        for (int i = 1; i <= n; i++)
        {
            int len = 0;
            for (int j = 1; j < i; j++)
            {
                if (hei[j] < hei[i])
                {
                    len = max(len, dp[j] + 1);
                }
            }
            if (len == 0)
                len = 1;
            dp[i] = len;
            ans = max(ans, dp[i]);
        }
        memset(dp, 0, sizeof(dp));
        for (int i = n; i >= 1; i--)
        {
            int len = 0;
            for (int j = n; j > i; j--)
            {
                if (hei[j] < hei[i])
                {
                    len = max(len, dp[j] + 1);
                }
            }
            if (len == 0)
                len = 1;
            dp[i] = len;
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
}