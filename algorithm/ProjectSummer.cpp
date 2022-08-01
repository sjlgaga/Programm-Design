#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int m, n, sx, sy, vis[105][105], ans;
int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, 1, -1, 0};
char map[105][105];
class node
{
public:
    int xx, yy, cost;
    node(int i, int j, int k) : xx(i), yy(j), cost(k){};
    node(int i, int j) : xx(i), yy(j), cost(0){};
};                              //节点 横坐标 纵坐标 时间花费
vector<vector<node>> trans(26); //传送门
void bfs()
{
    memset(vis, 0, sizeof(vis));
    queue<node> q;
    q.push(node(sx, sy, 0));
    vis[sx][sy] = 1;
    while (!q.empty())
    {
        node d = q.front();
        q.pop();
        if (map[d.xx][d.yy] == 'I')
        {
            ans = d.cost;
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int newx = d.xx + dx[i];
            int newy = d.yy + dy[i];
            if (newx >= 1 && newx <= n && newy >= 1 && newy <= m && vis[newx][newy] == 0 && map[newx][newy] != '#')
            {
                q.push(node(newx, newy, d.cost + 1));
                vis[newx][newy] = 1;
            } //普通点
        }
        if (map[d.xx][d.yy] >= 'a' && map[d.xx][d.yy] <= 'z')
        {
            int k = map[d.xx][d.yy] - 'a';
            for (auto i : trans[k])
            {
                if (vis[i.xx][i.yy] == 0)
                {
                    q.push(node(i.xx, i.yy, d.cost + 1));
                    vis[i.xx][i.yy] = 1;
                }
            }
        } //可传送
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int casetime;
    cin >> casetime;
    for (int t = 1; t <= casetime; t++)
    {
        memset(map, 0, sizeof(map));
        ans = -1;
        trans.clear();
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> map[i][j];
                if (map[i][j] == 'B')
                {
                    sx = i;
                    sy = j;
                }
                if (map[i][j] >= 'a' && map[i][j] <= 'z')
                {
                    trans[map[i][j] - 'a'].push_back(node(i, j));
                }
            }
        }
        bfs();
        cout << "Case #" << t << ": " << ans << endl;
    }
}