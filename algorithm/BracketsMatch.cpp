#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    char ans[105];
    string s;
    while (cin >> s)
    {
        memset(ans, 0, sizeof(ans));
        stack<int> left;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                ans[i] = '$';
            else if (s[i] == ')')
                ans[i] = '?';
            else
                ans[i] = ' ';
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                left.push(i);
            else if (s[i] == ')')
            {
                if (!left.empty())
                {
                    int k = left.top();
                    left.pop();
                    ans[k] = ' ';
                    ans[i] = ' ';
                }
            }
        }
        cout << s << endl;
        for (int i = 0; i < s.size(); i++)
            cout << ans[i];
        cout << endl;
    }
}