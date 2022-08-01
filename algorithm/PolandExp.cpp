#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;
double poland()
{
    char s[20];
    cin >> s;
    if (s[0] == '+')
        return poland() + poland();
    else if (s[0] == '-')
        return poland() - poland();
    else if (s[0] == '*')
        return poland() * poland();
    else if (s[0] == '/')
        return poland() / poland();
    else
        return atof(s);
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    printf("%f\n", poland());
}