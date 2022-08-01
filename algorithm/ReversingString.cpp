#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
string s;
void func()
{
    for (int i = s.length(); i >= 1; i--)
    {
        for (int j = 0; j <= s.length() - i; j++)
        {
            string temp1, temp2;
            temp1 = s.substr(j, i);
            temp2 = temp1;
            reverse(temp1.begin(), temp1.end());
            if (temp1 == temp2)
            {
                cout << temp1 << endl;
                return;
            }
        }
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    while (n--)
    {
        cin >> s;
        func();
    }
}