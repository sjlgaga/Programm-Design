#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int vis[256][256][6], n, m, h;
int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
char map[256][256];
class node
{
public:
    int xx, yy, cost, hp;
    node(int i, int j, int k, int l) : xx(i), yy(j), cost(k), hp(l){};
};
queue<node> q;
void bfs()
{
    memset(vis, 0, sizeof(vis));
    q.push(node(1, 1, 0, h));
    vis[1][1][h] = 1;
    while (!q.empty())
    {
        node d = q.front();
        q.pop();
        if (d.xx == m && d.yy == n && d.hp > 0)
        {
            cout << d.cost << endl;
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int newx = d.xx + dx[i];
            int newy = d.yy + dy[i];
            if (newx >= 1 && newx <= m && newy >= 1 && newy <= n)
            {
                if (map[newx][newy] == '.' && vis[newx][newy][d.hp] == 0)
                {
                    q.push(node(newx, newy, d.cost + 1, d.hp));
                    vis[newx][newy][d.hp] = 1;
                }
                else if (map[newx][newy] == '*' && vis[newx][newy][d.hp - 1] == 0)
                {
                    if (d.hp > 1)
                    {
                        q.push(node(newx, newy, d.cost + 1, d.hp - 1));
                        vis[newx][newy][d.hp - 1] = 1;
                    }
                }
            }
        }
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        while (!q.empty())
            q.pop();
        memset(map, 0, sizeof(map));
        cin >> m >> n >> h;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                cin >> map[i][j];
        bfs();
    }
}