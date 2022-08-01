#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int w[1005], n, m;
int func(int k)
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += w[i] / k;
        if (w[i] % k != 0)
            ans++;
    }
    return ans;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    memset(w, 0, sizeof(w));
    int maxw = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        maxw = max(maxw, w[i]);
    }
    int l = 1, r = maxw, d;
    while (r - l > 1)
    {
        d = l + (r - l) / 2;
        if (func(d) <= m)
            r = d;
        else
            l = d;
    }
    if (func(l) <= m)
        cout << l;
    else
        cout << r;
}