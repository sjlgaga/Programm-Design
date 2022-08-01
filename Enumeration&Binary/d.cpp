#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int dis[50002], c;
int len, rocknum, movenum;
bool can(int n)
{
    int poi = 0;
    int ans = 0;
    for (int i = 0; i <= rocknum + 1; i++)
    {
        if (dis[i] - dis[poi] >= n)
        {
            poi = i;
            ans++;
        }
    }
    if (dis[rocknum + 1] - dis[poi] < n)
        ans--;
    if (ans < c)
        return false;
    else
        return true;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> len >> rocknum >> movenum;
    for (int i = 1; i <= rocknum; i++)
        cin >> dis[i];
    dis[0] = 0;
    dis[rocknum + 1] = len;
    c = rocknum - movenum;
    int l = 1, r = (len / (c + 1)), d;
    int res = 1;
    while (l <= r)
    {
        d = l + (r - l) / 2;
        cout << l << r << d << endl;
        if (can(d))
        {
            res = d;
            l = d + 1;
        }
        else
            r = d - 1;
    }
    cout << res;
}