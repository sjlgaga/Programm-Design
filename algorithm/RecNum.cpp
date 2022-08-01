#include <iostream>
#include <cstring>
#include <set>
using namespace std;
class dot
{
public:
    int xx, yy;
    dot(int i, int j) : xx(i), yy(j){};
};
bool operator<(const dot &i, const dot &j)
{
    if (i.xx != j.xx)
        return i.xx < j.xx;
    else
        return i.yy < j.yy;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, n;
    cin >> t;
    while (t--)
    {
        set<dot> s;
        cin >> n;
        int xx, yy, ans = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> xx >> yy;
            s.insert(dot(xx, yy));
        }
        set<dot>::iterator i, j;
        for (i = s.begin(); i != s.end(); i++)
        {
            for (j = i; j != s.end(); j++)
            {
                if (i->xx != j->xx && i->yy != j->yy)
                {
                    if (s.find(dot(i->xx, j->yy)) != s.end() && s.find(dot(j->xx, i->yy)) != s.end())
                        ans++;
                }
            }
        }

        cout << ans / 2 << endl;
    }
}