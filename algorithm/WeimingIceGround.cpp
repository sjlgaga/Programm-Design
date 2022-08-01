#include <iostream>
#include <cstring>
using namespace std;
char map[105][105];
int n, m, ans, vis[105][105];
int dx[8] = {-1, 0, 0, 1, -1, -1, 1, 1}, dy[8] = {0, -1, 1, 0, -1, 1, -1, 1};
void dfs(int xx, int yy)
{
    vis[xx][yy] = 1;
    for (int i = 0; i < 8; i++)
    {
        int newx = xx + dx[i];
        int newy = yy + dy[i];
        if (newx >= 1 && newx <= n && newy >= 1 && newy <= m && vis[newx][newy] == 0 && map[newx][newy] == '@')
            dfs(newx, newy);
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    for (;;)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        memset(map, 0, sizeof(map));
        memset(vis, 0, sizeof(vis));
        ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> map[i][j];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (map[i][j] == '@' && vis[i][j] == 0)
                {
                    ans++;
                    dfs(i, j);
                }
            }
        }
        cout << ans << endl;
    }
}