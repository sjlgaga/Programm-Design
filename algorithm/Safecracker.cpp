#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int ans;
bool satisfy(int a, int b, int c, int d, int e)
{
    if (a - pow(b, 2) + pow(c, 3) - pow(d, 4) + pow(e, 5) == ans)
        return true;
    else
        return false;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    vector<int> num;
    vector<char> code;
    char s[15];
    for (;;)
    {
        cin >> ans;
        memset(s, 0, sizeof(s));
        cin.getline(s, sizeof(s));
        if (ans == 0 && strlen(s) == 4)
        {
            break;
        }
        num.clear();
        for (int i = 0; i < strlen(s); i++)
            num.push_back(s[i] - 'A' + 1);
        sort(num.begin(), num.end());
        code.clear();
        for (auto v : num)
        {
            for (auto w : num)
            {
                if (w == v)
                    continue;
                for (auto x : num)
                {
                    if ((x == v) || (x == w))
                        continue;
                    for (auto y : num)
                    {
                        if ((y == v) || (y == w) || (y == x))
                            continue;
                        for (auto z : num)
                        {
                            if ((z == v) || (z == w) || (z == x) || (z == y))
                                continue;
                            if (satisfy(v, w, x, y, z))
                            {
                                code.clear();
                                code.push_back(v + 'A' - 1);
                                code.push_back(w + 'A' - 1);
                                code.push_back(x + 'A' - 1);
                                code.push_back(y + 'A' - 1);
                                code.push_back(z + 'A' - 1);
                            }
                        }
                    }
                }
            }
        }
        if (code.empty())
        {
            cout << "no solution" << endl;
        }
        else
        {
            for (auto i : code)
                cout << i;
            cout << endl;
        }
    }
}