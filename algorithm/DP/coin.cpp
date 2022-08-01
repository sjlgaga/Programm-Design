#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int dp1[10005], dp2[10005];
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, price;
    int coin[205];
    memset(coin, 0, sizeof(coin));
    int p[205];
    vector<int> ans;
    cin >> n >> price;
    for (int i = 1; i <= n; i++)
        cin >> coin[i];
    dp1[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = price; j >= coin[i]; j--)
            dp1[j] += dp1[j - coin[i]];
    for (int i = 1; i <= n; i++)
    {
        memset(dp2, 0, sizeof(dp2));
        for (int j = 0; j <= price; j++)
        {
            if (j < coin[i])
                dp2[j] = dp1[j];
            else
                dp2[j] = dp1[j] - dp2[j - coin[i]];
        }
        if (dp2[price] == 0)
            ans.push_back(coin[i]);
    }
    if (!ans.empty())
    {
        cout << ans.size() << endl;
        for (auto i : ans)
            cout << i << " ";
        cout << endl;
    }
    else
        cout << 0 << endl
             << endl;
}