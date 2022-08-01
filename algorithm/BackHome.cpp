#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int cost[11][11], vis[11], n;
bool flag;
void dfs(int layer)
{
    if (flag == true)
        return;
    if (layer == n)
    {
        flag = true;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0 && cost[layer][i] > 0)
        {
            vis[i] = 1;
            dfs(i);
            vis[i] = 0;
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
        cin >> n;
        memset(cost, 0, sizeof(cost));
        memset(vis, 0, sizeof(vis));
        flag = false;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> cost[i][j];
        vis[1] = 1;
        dfs(1);
        if (flag == true)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}