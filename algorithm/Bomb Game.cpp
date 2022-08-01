#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int map[105][105];
    memset(map, 0, sizeof(map));
    int a, b, k;
    int r, s, p, t;
    int bomb = 0;
    cin >> a >> b >> k;
    for (int q = 1; q <= k; q++)
    {
        cin >> r >> s >> p >> t;
        if (t == 1)
        {
            for (int i = r - (p - 1) / 2; i <= r + (p - 1) / 2; i++)
            {
                if (i < 1 || i > a)
                    continue;
                for (int j = s - (p - 1) / 2; j <= s + (p - 1) / 2; j++)
                {
                    if (j < 1 || j > b)
                        continue;
                    map[i][j]++;
                }
            }
            bomb++;
        }
        else if (t == 0)
        {
            for (int i = r - (p - 1) / 2; i <= r + (p - 1) / 2; i++)
            {
                if (i < 1 || i > a)
                    continue;
                for (int j = s - (p - 1) / 2; j <= s + (p - 1) / 2; j++)
                {
                    if (j < 1 || j > b)
                        continue;
                    map[i][j] -= 150;
                }
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (map[i][j] == bomb)
                sum++;
        }
    }
    cout << sum;
}