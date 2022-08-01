#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int Max((1 << 16) + 10);
int D[16];
int C[16];
int sumtime[Max];
string name[16];
string ans[Max];
int dp[Max];
int cal(int i, int j)
{
    return max(0, i - j);
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> name[i];
            cin >> D[i];
            cin >> C[i];
            sumtime[1 << i] = C[i];
        }
        for (int i = 1; i < 1 << N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i & (1 << j))
                {
                    sumtime[i] = sumtime[i ^ (1 << j)] + C[j];
                }
            }
        }
        for (int i = 0; i < 1 << N; i++)
        {
            ans[i] = "";
        }
        dp[0] = 0;
        for (int i = 1; i < 1 << N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i & (1 << j) && (dp[i ^ (1 << j)] + cal(sumtime[i], D[j]) <= dp[i] || ans[i] == ""))
                {
                    if (dp[i ^ (1 << j)] + cal(sumtime[i], D[j]) < dp[i] || ans[i ^ (1 << j)] + name[j] + "\n" < ans[i] || ans[i] == "")
                    {
                        ans[i] = ans[i ^ (1 << j)] + name[j] + "\n";
                    }
                    dp[i] = dp[i ^ (1 << j)] + cal(sumtime[i], D[j]);
                }
            }
        }
        cout << dp[(1 << N) - 1] << endl;
        cout << ans[(1 << N) - 1];
    }
    return 0;
}
