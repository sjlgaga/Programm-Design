#include <iostream>
#include <cstring>
using namespace std;
int find(int n, int d)
{
    int ans = 1;
    for (int i = d; i * i <= n; i++)
    {
        if (n % i == 0)
            ans += find(n / i, i);
    }
    return ans;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int casetime, n;
    cin >> casetime;
    while (casetime--)
    {
        cin >> n;
        cout << find(n, 2) << endl;
    }
}