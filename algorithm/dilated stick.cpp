#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double pi = 3.141592653589, eps = 1e-14;
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    double len, degree, c;
    cin >> len >> degree >> c;
    if (len < eps)
    {
        cout << "0.000";
        return 0;
    }
    double newlen = (1 + degree * c) * len;
    double l = 0.0, r = asin(1.0), d;
    while (r - l > eps)
    {
        d = (l + r) / 2;
        if (newlen * sin(d) / d <= len)
            r = d;
        else
            l = d;
    }
    double ans = (len / 2) * (1 / sin(l) - 1 / tan(l));
    cout << fixed << setprecision(3) << ans;
}