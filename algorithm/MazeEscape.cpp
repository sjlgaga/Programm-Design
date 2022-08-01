#include <iostream>
#include <cstring>
using namespace std;
int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, 1, -1, 0};
bool flag = false;
int k, m, t, maze[11][11], vis[11][11], startx, starty, endx, endy;
void dfs(int xx, int yy, int cost)
{
    if (cost > t)
        return;
    if (xx == endx && yy == endy)
    {
        flag = true;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int newx = xx + dx[i];
        int newy = yy + dy[i];
        if (newx >= 1 && newx <= m && newy >= 1 && newy <= m && maze[newx][newy] == 0)
        {
            if (vis[newx][newy] == 0)
            {
                vis[newx][newy] = 1;
                dfs(newx, newy, cost + 1);
                vis[newx][newy] = 0;
            }
        }
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> k;
    while (k--)
    {
        cin >> m >> t;
        char c;
        flag = false;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> c;
                if (c == 'S')
                {
                    startx = i;
                    starty = j;
                    maze[i][j] = 0;
                }
                else if (c == 'E')
                {
                    endx = i;
                    endy = j;
                    maze[i][j] = 0;
                }
                else if (c == '.')
                    maze[i][j] = 0;
                else
                    maze[i][j] = 1;
            }
        }
        vis[startx][starty] = 1;
        dfs(startx, starty, 0);
        if (flag == true)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}