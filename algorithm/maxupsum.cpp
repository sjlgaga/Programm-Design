#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int num[1005], dp[1005];
    memset(num, 0, sizeof(num));
    memset(dp, 0, sizeof(dp));
    int n, ans = -1;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    for (int i = 1; i <= n; i++)
    {
        dp[i] = num[i];
        for (int j = 1; j <= i - 1; j++)
        {
            if (num[i] > num[j])
                dp[i] = max(dp[i], dp[j] + num[i]);
        }
    }
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
    cout << ans;
}