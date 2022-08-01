#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
int h, w, m, map[55][55], ans, vis[55][55];
void dfs(int xx, int yy)
{
    vis[xx][yy] = 1;
    for (int i = 0; i < 4; i++)
    {
        int newx = xx + dx[i];
        int newy = yy + dy[i];
        if (newx >= 1 && newx <= h && newy >= 1 && newy <= w && vis[newx][newy] == 0)
        {
            if (abs(map[xx][yy] - map[newx][newy]) <= m)
                dfs(newx, newy);
        }
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    for (;;)
    {
        cin >> h >> w >> m;
        if (h == 0 && w == 0 && m == 0)
            break;
        ans = 0;
        memset(map, 0, sizeof(map));
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= h; i++)
            for (int j = 1; j <= w; j++)
                cin >> map[i][j];
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                if (vis[i][j] == 0)
                {
                    ans++;
                    dfs(i, j);
                }
            }
        }
        cout << ans << endl;
    }
}