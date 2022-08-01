#include <iostream>
#include <cstring>
using namespace std;
int n, x, counter[10], my[10], vis[10], win = 0;
void dfs(int layer)
{
    if (layer > n)
    {
        if (win > n / 2)
        {
            for (int i = 1; i <= n; i++)
                cout << my[i] << " ";
            cout << endl;
        }
        return;
    }
    if (win + n - layer + 1 <= n / 2)
        return;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            if (i - x >= counter[layer])
            {
                win++;
                vis[i] = 1;
                my[layer] = i;
                dfs(layer + 1);
                win--;
                vis[i] = 0;
            }
            else
            {
                vis[i] = 1;
                my[layer] = i;
                dfs(layer + 1);
                vis[i] = 0;
            }
        }
    }
    return;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    memset(counter, 0, sizeof(counter));
    memset(my, 0, sizeof(my));
    memset(vis, 0, sizeof(vis));
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> counter[i];
    dfs(1);
}