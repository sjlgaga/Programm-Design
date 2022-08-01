#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    long long dp[255][255];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= 250; i++)
    {
        dp[i][i] = 1;
        for (int j = i - 1; j >= 1; j--)
        {
            dp[i][j] += dp[i][j + 1];
            if (i - 2 * j >= 1)
                dp[i][j] += dp[i - 2 * j][j];
            else if (i - 2 * j == 0)
                dp[i][j]++;
        }
    }
    int c;
    for (;;)
    {
        cin >> c;
        if (c == 0)
            break;
        cout << c << " " << dp[c][1] << endl;
    }
}