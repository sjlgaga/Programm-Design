#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, a[10005], b[10005], c[10005], dp[10005][3];
    memset(dp, 0, sizeof(dp));
    // dp[i][0]前i个位置第i个做的时候是0个人，依次类推
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    dp[1][0] = a[1];
    dp[1][1] = b[1];
    for (int i = 2; i <= n - 1; i++)
    {
        dp[i][0] = max(dp[i - 1][1] + a[i], dp[i - 1][2] + a[i]);
        dp[i][1] = max(dp[i - 1][1] + b[i], dp[i - 1][2] + b[i]);
        dp[i][1] = max(dp[i][1], dp[i - 1][0] + b[i]);
        dp[i][2] = max(dp[i - 1][0] + c[i], dp[i - 1][1] + c[i]);
    }
    dp[n][0] = max(dp[n - 1][1] + a[n], dp[n - 1][2] + a[n]);
    dp[n][1] = max(dp[n - 1][1] + b[n], dp[n - 1][0] + b[n]);
    cout << max(dp[n][0], dp[n][1]);
}