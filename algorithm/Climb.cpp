#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int a[1005];
    int dp1[1005], dp2[1005];
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        dp1[i] = 1;
        for (int j = 1; j <= i - 1; j++)
        {
            if (j == i - 1)
            {
                if (a[j] == a[i])
                    continue;
            }
            if (a[i] > a[j])
                dp1[i] = max(dp1[i], dp1[j] + 1);
        }
    }
    for (int i = n; i >= 1; i--)
    {
        dp2[i] = 1;
        for (int j = n; j >= i + 1; j--)
        {
            if (j == i + 1)
            {
                if (a[j] == a[i])
                    continue;
            }
            if (a[i] > a[j])
                dp2[i] = max(dp2[i], dp2[j] + 1);
        }
    }
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp1[i] + dp2[i] - 1);
    cout << ans;
}