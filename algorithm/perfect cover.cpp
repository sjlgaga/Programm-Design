#include <iostream>
#include <cstring>
using namespace std;
long long cover(int n)
{
    long long ans = 0;
    if (n <= 0)
        return 0;
    else if (n % 2 == 1)
        return 0;
    else if (n == 2)
        return 3;
    else if (n == 4)
        return 11;
    else
    {
        ans = 3 * cover(n - 2);
        for (int i = n - 4; i > 0; i -= 2)
            ans += 2 * cover(i);
        return ans + 2;
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    for (;;)
    {
        cin >> n;
        if (n == -1)
            break;
        cout << cover(n) << endl;
    }
}