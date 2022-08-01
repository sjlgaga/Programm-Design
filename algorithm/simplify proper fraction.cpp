#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
bool ifprime(int a, int b)
{
    for (int i = 2; i <= (a / 2) + 1; i++)
    {
        if (a % i == 0 && b % i == 0)
            return false;
    }
    if (b % a == 0)
        return false;
    return true;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int num[605];
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    sort(num, num + n);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ifprime(num[i], num[j]))
                ans++;
        }
    }
    cout << ans;
}