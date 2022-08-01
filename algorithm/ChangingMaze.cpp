#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
class dot
{
public:
    int xx, yy, ctime;
    dot(int i, int j, int p) : xx(i), yy(j), ctime(p){};
};
bool flag = false;
char maze[105][105];
int r, c, k, dx[4] = {-1, 0, 0, 1}, dy[4] = {0, 1, -1, 0}, vis[105][105][11];
int startx, starty;
void bfs()
{
    queue<dot> q;
    memset(vis, 0, sizeof(vis));
    vis[startx][starty][0] = 1;
    q.push(dot(startx, starty, 0));
    while (!q.empty())
    {
        dot d = q.front();
        q.pop();
        if (maze[d.xx][d.yy] == 'E')
        {
            flag = true;
            cout << d.ctime << endl;
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int newx = d.xx + dx[i];
            int newy = d.yy + dy[i];
            int newyu = (d.ctime + 1) % k;
            if (newx >= 1 && newx <= r && newy >= 1 && newy <= c && vis[newx][newy][newyu] == 0)
            {
                if (maze[newx][newy] == '#')
                {
                    if (newyu == 0)
                    {
                        q.push(dot(newx, newy, d.ctime + 1));
                        vis[newx][newy][newyu] = 1;
                    }
                }
                else
                {
                    q.push(dot(newx, newy, d.ctime + 1));
                    vis[newx][newy][newyu] = 1;
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
        flag = false;
        cin >> r >> c >> k;
        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                cin >> maze[i][j];
                if (maze[i][j] == 'S')
                {
                    startx = i;
                    starty = j;
                }
            }
        }
        bfs();
        if (flag == false)
            cout << "Oop!" << endl;
    }
}