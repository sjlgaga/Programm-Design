#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, 1, -1, 0};
class dot
{
public:
    int xx;
    int yy;
    dot(int i, int j) : xx(i), yy(j){};
};
vector<vector<dot>> box(101);
int map[21][21], vis[21][21], maxbox = 0, boxnum = 1, m, n, k;
void dfs(int xx, int yy)
{
    bool flag = false;
    for (int i = 0; i < 4; i++)
    {
        int newx = xx + dx[i];
        int newy = yy + dy[i];
        if (newx >= 1 && newx <= m && newy >= 1 && newy <= n)
        {
            if (vis[newx][newy] == 0)
            {
                flag = true;
                for (auto j : box[map[newx][newy]])
                    vis[j.xx][j.yy] = 1;
                boxnum++;
                dfs(newx, newy);
                for (auto j : box[map[newx][newy]])
                    vis[j.xx][j.yy] = 0;
                boxnum--;
            }
        }
    }
    if (flag == false)
    {
        maxbox = max(maxbox, boxnum);
        return;
    }
    return;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    memset(map, 0, sizeof(map));
    memset(vis, 0, sizeof(vis));
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
            box[map[i][j]].push_back(dot(i, j));
        }
    }
    for (auto i : box[map[1][1]])
        vis[i.xx][i.yy] = 1;
    dfs(1, 1);
    cout << maxbox;
}