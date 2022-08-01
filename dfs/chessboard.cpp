#include <iostream>
#include <cstring>
using namespace std;
int n, k, col[10], chessnum, ans;
char board[10][10];
void dfs(int x, int layer)
{
    if (x > layer)
    {
        if (chessnum == k)
            ans++;
        return;
    }
    for (int i = 1; i <= layer; i++)
    {
        if (col[i] == 0 && board[x][i] == '#')
        {
            col[i] = 1;
            chessnum++;
            dfs(x + 1, layer);
            col[i] = 0;
            chessnum--;
        }
    }
    dfs(x + 1, layer);
    return;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    for (;;)
    {
        cin >> n >> k;
        if (n == -1 && k == -1)
            break;
        memset(board, 0, sizeof(board));
        memset(col, 0, sizeof(col));
        ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> board[i][j];
        dfs(1, n);
        cout << ans << endl;
    }
}