#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define inf 1 << 30
#define maxn 16
int map[maxn][maxn];
int n;
int mindist = inf;
unsigned int dp[14][1 << 14];

inline bool visit(int city, int state)
{
    if (state & (1 << (city - 1)))
    {
        return true;
    }
    return false;
}

int dfs(int dist, int num, int crt, int state)
{
    if (dist >= mindist)
        return 0;
    if (num == n - 1)
    {
        dist += map[crt][n - 1];
        mindist = min(dist, mindist);
        return 0;
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (visit(i, state) == false)
        {
            int newState = state | (1 << (i - 1));
            if (crt == 0)
            {
                dp[i - 1][newState] = map[0][i];
                dfs(dist + map[crt][i], num + 1, i, newState);
            }
            else if (dp[i - 1][newState] > dp[crt - 1][state] + map[crt][i])
            {
                dp[i - 1][newState] = dp[crt - 1][state] + map[crt][i];
                dfs(dist + map[crt][i], num + 1, i, newState);
            }
        }
    }
    return 0;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    memset(dp, -1, sizeof(dp));
    dfs(0, 1, 0, 0);
    cout << mindist;
    return 0;
}