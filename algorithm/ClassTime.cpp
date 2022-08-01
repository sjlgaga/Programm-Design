#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{

    int n, a[1001], b[1001];
    int ans = 0, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    int temp[1001];
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            sum = 0;
            for (int k = a[i]; k <= b[i]; k++)
            {
                if (k >= a[j] && k <= b[j])
                    sum++;
            }
            ans = max(ans, sum);
        }
    }
    cout << ans;
}