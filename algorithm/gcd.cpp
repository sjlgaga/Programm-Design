#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int gcd(int i, int j)
{
    if (i % j == 0)
        return j;
    else
        return gcd(j, i % j);
}
int main()
{
    int a, b;
    cin >> a >> b;
    if (a > b)
        cout << gcd(a, b);
    else
        cout << gcd(b, a);
}