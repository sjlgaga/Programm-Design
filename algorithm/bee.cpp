#include <iostream>
#include <cstring>
using namespace std;
int a, b;
long long dp[55];
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= 50; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    int t;
    cin >> t;
    while (t--)
    {

        cin >> a >> b;
        cout << dp[b - a + 1] << endl;
    }
}