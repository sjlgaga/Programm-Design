#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
queue<char> q;
vector<char> p;
int ep = 0, item = 0, factor = 0;
bool expvalue();
bool itemvalue();
bool factorvalue();
bool expvalue()
{
    bool v = itemvalue();
    while (true)
    {
        char c = q.front();
        if (c == '|')
        {
            q.pop();
            v = v || (itemvalue());
        }
        else
            break;
    }
    return v;
}
bool itemvalue()
{
    bool v = factorvalue();
    while (true)
    {
        char c = q.front();
        if (c == '&')
        {
            q.pop();
            v = v && (factorvalue());
        }
        else
            break;
    }
    return v;
}
bool factorvalue()
{
    bool v;
    char c = q.front();
    if (c == '!')
    {
        q.pop();
        bool temp = factorvalue();
        v = !temp;
    }
    else if (c == '(')
    {
        q.pop();
        v = expvalue();
        q.pop();
    }
    else if (c == 'V')
    {
        q.pop();
        v = true;
    }
    else if (c == 'F')
    {
        q.pop();
        v = false;
    }
    return v;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 0;
    char s[105];
    memset(s, 0, sizeof(s));
    while (cin.getline(s, 105))
    {
        for (int i = 0; i < strlen(s); i++)
        {
            if (s[i] != ' ')
            {
                q.push(s[i]);
                p.push_back(s[i]);
            }
        }
        t++;
        if (expvalue() == 1)
            cout << "Expression " << t << ": V" << endl;
        else
            cout << "Expression " << t << ": F" << endl;

        memset(s, 0, sizeof(s));
    }
}
