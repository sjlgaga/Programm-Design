#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
class dot
{
public:
    int xx;
    int yy;
    int keys;
    int snake;
    int cost;
    dot(int i, int j) : xx(i), yy(j), keys(0), snake(0), cost(0){};
    dot(int i, int j, int p, int k, int l) : xx(i), yy(j), snake(p), keys(k), cost(l){};
};
int dirx[4] = {-1, 0, 0, 1}, diry[4] = {0, 1, -1, 0};
vector<dot> ned, snakes;
int n, m, totaltime = 0, snakenum = 0;
char map[105][105];
bool vis[105][105][33][11]; //横坐标 纵坐标 蛇的状态 钥匙的状态
void bfs()
{
    memset(vis, 0, sizeof(vis));
    queue<dot> q;
    q.push(dot(ned[0].xx, ned[0].yy));   //起点
    vis[ned[0].xx][ned[0].yy][0][0] = 1; //起点
    while (!q.empty())
    {
        dot d = q.front();
        q.pop();
        char c = map[d.xx][d.yy];
        if (d.keys == m) //集齐钥匙并找到唐僧
        {
            if (c == 'T')
            {
                totaltime = min(totaltime, d.cost);
                continue;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            int xx = d.xx + dirx[i];
            int yy = d.yy + diry[i];
            c = map[xx][yy];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= n && vis[xx][yy][d.snake][d.keys] == 0)
            {
                if (c == '.' || c == 'T' || c == 'K') //普通可以走过的点
                {
                    vis[xx][yy][d.snake][d.keys] = 1;
                    q.push(dot(xx, yy, d.snake, d.keys, d.cost + 1));
                }
                else if (c == 'S') //有蛇的点
                {
                    int k;
                    for (int t = 0; t < snakenum; t++)
                    {
                        if (snakes[t].xx == xx && snakes[t].yy == yy)
                        {
                            k = t;
                            break;
                        }
                    }
                    if ((d.snake & (1 << k)) == 0) //这个房间的蛇没有被杀过
                    {
                        vis[xx][yy][d.snake | (1 << k)][d.keys] = 1;
                        q.push(dot(xx, yy, (d.snake | (1 << k)), d.keys, d.cost + 2));
                    }
                    else //这个房间的蛇已经被杀死了
                    {
                        vis[xx][yy][d.snake][d.keys] = 1;
                        q.push(dot(xx, yy, d.snake, d.keys, d.cost + 1));
                    }
                }
                else if (c - '0' >= 1 && c - '0' <= 9)
                {
                    if (c - '0' == d.keys + 1) //正好是下一把钥匙 取得的钥匙加一
                    {
                        vis[xx][yy][d.snake][d.keys + 1] = 1;
                        q.push(dot(xx, yy, d.snake, d.keys + 1, d.cost + 1));
                    }
                    else //不是能够拿的钥匙
                    {
                        vis[xx][yy][d.snake][d.keys] = 1;
                        q.push(dot(xx, yy, d.snake, d.keys, d.cost + 1));
                    }
                }
            }
        }
    }
    return;
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
        ned.clear();
        snakes.clear();
        totaltime = 1 << 30, snakenum = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> map[i][j];
                if (map[i][j] == 'K')
                    ned.push_back(dot(i, j));
                if (map[i][j] == 'S')
                {
                    snakes.push_back(dot(i, j));
                    snakenum++;
                }
            }
        }
        bfs();
        if (totaltime == (1 << 30))
            cout << "impossible" << endl;
        else
            cout << totaltime << endl;
    }
}