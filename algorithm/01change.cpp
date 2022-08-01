#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
string s;
int num[1005], dp[1005][2]; // dp[i][0]前i个数以0结尾变换最小值 dp[i][1]以1结尾
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> s;
        memset(num, 0, sizeof(num));
        memset(dp, 0, sizeof(dp));
        n = s.size();
        for (int i = 1; i <= n; i++)
        {
            num[i] = s[i - 1] - '0';
        }
        if (num[1] == 0)
        {
            dp[1][0] = 0;
            dp[1][1] = 1;
        }
        else
        {
            dp[1][0] = 1;
            dp[1][1] = 0;
        }
        for (int i = 2; i <= n; i++)
        {
            if (num[i] == 0)
            {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = min(dp[i - 1][0] + 1, dp[i - 1][1] + 1);
            }
            else
            {
                dp[i][0] = dp[i - 1][0] + 1;
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
            }
        }
        cout << min(dp[n][0], dp[n][1]) << endl;
    }
}