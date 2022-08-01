#include <iostream>
#include <cstring>
using namespace std;
int ini[32], goal[32], press[32], len;
bool end()
{
    if (press[1] == 2 && press[2] == 1)
        return false;
    return true;
}
bool satisfy()
{
    if ((press[1] + press[2] + ini[1] + goal[1]) % 2 != 0)
        return false;
    if ((press[len - 1] + press[len] + ini[len] + goal[len]) % 2 != 0)
        return false;
    return true;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    memset(ini, 0, sizeof(ini));
    memset(goal, 0, sizeof(goal));
    memset(press, 0, sizeof(press));
    char s[32];
    cin.getline(s, 32);
    len = strlen(s);
    for (int i = 1; i <= len; i++)
        ini[i] = s[i - 1] - '0';
    memset(s, 0, sizeof(s));
    cin.getline(s, 32);
    for (int i = 1; i <= len; i++)
        goal[i] = s[i - 1] - '0';
    int ans = 32;
    while (end())
    {

        if (press[1] > 1)
        {
            press[1] = 0;
            press[2]++;
        }
        for (int i = 3; i <= len; i++)
        {
            press[i] = (press[i - 2] + press[i - 1] + ini[i - 1] + goal[i - 1]) % 2;
        }
        if (satisfy())
        {
            int sum = 0;
            for (int i = 1; i <= len; i++)
            {
                if (press[i] > 0)
                    sum++;
            }
            if (sum < ans)
                ans = sum;
        }
        press[1]++;
    }
    if (ans != 32)
        cout << ans << endl;
    else
        cout << "impossible";
}