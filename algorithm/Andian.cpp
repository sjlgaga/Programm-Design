#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    bool flag = false;
    int map[5][5];
    int maxn[5], minn[5];
    for (int i = 0; i < 5; i++)
    {
        minn[i] = 1 << 30;
        maxn[i] = -(1 << 30);
    }

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> map[i][j];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            maxn[i] = max(maxn[i], map[i][j]);
            minn[i] = min(minn[i], map[j][i]);
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (map[i][j] == maxn[i] && map[i][j] == minn[j])
            {
                flag = true;
                cout << i + 1 << " " << j + 1 << " " << map[i][j] << endl;
            }
        }
    }
    if (flag == false)
        cout << "not found" << endl;
}