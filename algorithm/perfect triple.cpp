#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int a = 2; a <= n; a++)
    {
        for (int b = 2; b <= a - 1; b++)
        {
            for (int c = b; c <= a - 1; c++)
            {
                for (int d = c; d <= a - 1; d++)
                {
                    if (a * a * a == b * b * b + c * c * c + d * d * d)
                    {
                        cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")" << endl;
                    }
                }
            }
        }
    }
}