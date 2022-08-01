#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int sum = 999999999;
    for (int i = 1; i <= sqrt(n); i++)
    {
        for (int j = i; j <= n; j++)
        {
            for (int k = j; k <= n; k++)
            {
                if (i * j * k == n)
                    sum = min(sum, 2 * (i * j + i * k + k * j));
            }
        }
    }
    cout << sum;
}