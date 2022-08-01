#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
class rec
{
public:
    int poi;
    int wid;
    int hei;
    rec(int a, int b, int c) : poi(a), wid(b), hei(c){};
}; //每一个点
vector<rec> recset;
long long leftstd = 0; //满足两边面积之差最小的左边的面积
bool satisfy(int k)    //判断x=k这条直线划分下左边面积是否大于等于右边面积
{
    long long leftsum = 0;
    long long rightsum = 0;
    for (auto i : recset)
    {
        if (i.poi < k)
        {
            if (i.poi + i.wid <= k)
                leftsum += i.wid * i.hei;
            else
            {
                leftsum += i.hei * (k - i.poi);
                rightsum += i.hei * (i.poi + i.wid - k);
            }
        }
        else
            rightsum += i.hei * i.wid;
    }
    return leftsum >= rightsum;
}
bool satisfy2(int k) //判断所有满足左边面积大于右边面积的直线中x=k所划分的左边面积是否等于leftstd，只要左面积不变就可以往右拓到k
{
    long long sum = 0;
    for (auto i : recset)
    {
        if (i.poi < k)
        {
            if (i.poi + i.wid <= k)
                sum += i.wid * i.hei;
            else
                sum += i.hei * (k - i.poi);
        }
    }
    return sum == leftstd;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int maxsize, recnum;
    cin >> maxsize >> recnum;
    int lpoi, t, w, h;
    for (int i = 1; i <= recnum; i++)
    {
        cin >> lpoi >> t >> w >> h;
        recset.push_back(rec(lpoi, w, h));
    }
    int l = 0, r = maxsize, d;
    //第一次二分 找到满足左边大于等于右边的下界
    while (r - l > 1)
    {
        d = l + (r - l) / 2;
        if (satisfy(d))
            r = d;
        else
            l = d;
    }

    int l2 = 0, r2 = maxsize;
    leftstd = 0;
    if (satisfy(l))
        l2 = l;
    else
        l2 = r;
    //计算下界的左面积
    for (auto i : recset)
    {
        if (i.poi < l2)
        {
            if (i.poi + i.wid <= l2)
                leftstd += i.wid * i.hei;
            else
                leftstd += i.hei * (l2 - i.poi);
        }
    }
    //第二次二分 找到保持差最小不变同时让大矩形面积最大的直线
    while (r2 - l2 > 1)
    {
        d = l2 + (r2 - l2) / 2;
        if (satisfy2(d))
            l2 = d;
        else
            r2 = d;
    }

    if (satisfy2(r2))
        cout << r2;
    else
        cout << l2;
}