#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;
double pi = 3.141592653589, sum = 0, eps = 1e-6;
vector<double> pie;
int pienum(double s)
{
    int num = 0;
    for (auto i : pie)
    {
        num += int(i / s);
    }
    return num;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, f;
    cin >> n >> f;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        sum += pi * x * x;
        pie.push_back(pi * x * x);
    }
    double l = pi / (f + 1), r = sum / (f + 1), d;
    if (l == r)
        d = l;
    else
    {
        while ((r - l) > eps)
        {
            d = l + (r - l) / 2;
            if (pienum(d) >= f + 1)
            {
                l = d;
            }
            else
                r = d;
        }
    }

    cout << fixed << setprecision(3) << d;
}