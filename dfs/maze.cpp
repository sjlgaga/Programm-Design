#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct point
{
    int xx;
    int yy;
    point(int i, int j) : xx(i), yy(j){};
    point() : xx(0), yy(0){};
};
point route[30];
vector<point> ans;
int maze[5][5], walked[5][5], step = 1, minstep = 1 << 30;
int dirx[4] = {1, 0, 0, -1}, diry[4] = {0, -1, 1, 0};
void dfs(int x, int y)
{
    if (step >= minstep)
        return;
    if (x == 4 && y == 4)
    {
        route[step] = point(4, 4);
        if (step < minstep)
        {
            minstep = min(step, minstep);
            ans.clear();
            for (int i = 1; i <= step; i++)
            {
                ans.push_back(route[i]);
            }
        }
    }
    route[step] = point(x, y);
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dirx[i], yy = y + diry[i];
        if (xx >= 0 && xx < 5 && yy >= 0 && yy < 5 && maze[xx][yy] == 0 && walked[xx][yy] == 0)
        {
            step++;
            walked[xx][yy] = 1;
            dfs(xx, yy);
            step--;
            walked[xx][yy] = 0;
        }
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    memset(walked, 0, sizeof(walked));
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> maze[i][j];
    walked[0][0] = 1;
    dfs(0, 0);
    for (auto i : ans)
    {
        cout << "(" << i.xx << ", " << i.yy << ")" << endl;
    }
}