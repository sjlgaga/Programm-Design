#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int r, c;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int hei[105][105];
int dp[105][105];
bool check(int tx, int ty)
{
    if (tx > 0 && tx <= r && ty > 0 && ty <= c)
        return true;
    else
        return false;
}
int ski(int xx, int yy)
{
    if (dp[xx][yy] != 0)
        return dp[xx][yy];
    int len = 0;
    for (int i = 0; i < 4; i++)
    {
        int tx = xx + dir[i][0];
        int ty = yy + dir[i][1];
        if (check(tx, ty) == true && hei[tx][ty] < hei[xx][yy])
        {
            len = max(len, ski(tx, ty) + 1);
        }
    }
    if (len == 0)
        len = 1;
    dp[xx][yy] = len;
    return dp[xx][yy];
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    memset(hei, 0, sizeof(hei));
    memset(dp, 0, sizeof(dp));
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            cin >> hei[i][j];
    int ans = 0;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            ans = max(ans, ski(i, j));
    cout << ans;
}