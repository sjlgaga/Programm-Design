#include <iostream>
#include <cstring>
using namespace std;
int casetime, r, c;
char map[501][501], ans[501][501];
int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, 1, -1, 0};
void dfs(int xx, int yy)
{
    ans[xx][yy] = 'O';
    map[xx][yy] = 'X';
    for (int i = 0; i < 4; i++)
    {
        int newx = xx + dx[i];
        int newy = yy + dy[i];
        if (newx >= 1 && newx <= r && newy >= 1 && newy <= c)
        {
            if (map[newx][newy] == 'O')
                dfs(newx, newy);
        }
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> casetime;
    while (casetime--)
    {
        cin >> r >> c;
        memset(map, 0, sizeof(map));
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                cin >> map[i][j];
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                ans[i][j] = 'X';
        for (int i = 1; i <= c; i++)
        {
            if (map[1][i] == 'O')
                dfs(1, i);
            if (map[r][i] == 'O')
                dfs(r, i);
        }
        for (int i = 1; i <= r; i++)
        {
            if (map[i][1] == 'O')
                dfs(i, 1);
            if (map[i][c] == 'O')
                dfs(i, c);
        }
        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
                cout << ans[i][j];
            cout << endl;
        }
        cout << endl;
    }
}