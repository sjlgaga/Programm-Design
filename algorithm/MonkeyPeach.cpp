#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int honey, ans;
vector<int> peach, bee;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    for (;;)
    {
        cin >> honey;
        ans = 0;
        peach.clear();
        bee.clear();
        if (honey == -1)
            break;
        for (;;)
        {
            int a, b;
            cin >> a >> b;
            if (a == -1 && b == -1)
                break;
            peach.push_back(a);
            bee.push_back(b);
        }
        for (int i = 0; i < peach.size(); i++)
        {
            int temp = honey, num = 0;
            for (int j = i; j < peach.size(); j++)
            {
                if (temp >= bee[j])
                {
                    temp -= bee[j];
                    num += peach[j];
                }
                else
                    break;
            }
            ans = max(ans, num);
        }
        cout << ans << endl;
    }
}