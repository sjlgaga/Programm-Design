#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    vector<int> num;
    cin >> n;
    int c;
    for (int i = 1; i <= n; i++)
    {
        cin >> c;
        num.push_back(c);
    }
    sort(num.begin(), num.end());
    int m;
    cin >> m;
    int t, l, r, d, ans;
    while (m--)
    {
        cin >> t;
        l = 0, r = num.size() - 1;
        ans = -1;
        while (r - l > 1)
        {
            d = l + (r - l) / 2;
            if (num[d] == t)
            {
                ans = t;
                break;
            }
            else if (num[d] < t)
            {
                l = d;
            }
            else if (num[d] > t)
            {
                r = d;
            }
        }
        if (ans == -1)
        {
            if (abs(num[l] - t) <= abs(num[r] - t))
                ans = num[l];
            else
                ans = num[r];
        }
        cout << ans << endl;
    }
}