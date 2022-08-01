#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n, w, ans = 1 << 30, c[20];
int remain[20], bags = 0;
void dfs(int k)
{
    if (bags >= ans)
        return;
    if (k == n + 1)
        ans = min(ans, bags);
    for (int i = 1; i <= bags; i++)
    {
        if (remain[i] - c[k] >= 0)
        {
            remain[i] -= c[k];
            dfs(k + 1);
            remain[i] += c[k];
        }
    }
    bags++;
    remain[bags] = w - c[k];
    dfs(k + 1);
    bags--;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    dfs(1);
    cout << ans;
}