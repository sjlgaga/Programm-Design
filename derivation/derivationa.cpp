#include <cstdlib>
#include <iostream>
using namespace std;
int strlen(const char *s)
{
    int i = 0;
    for (; s[i]; ++i)
        ;
    return i;
}
void strcpy(char *d, const char *s)
{
    int i = 0;
    for (i = 0; s[i]; ++i)
        d[i] = s[i];
    d[i] = 0;
}
int strcmp(const char *s1, const char *s2)
{
    for (int i = 0; s1[i] && s2[i]; ++i)
    {
        if (s1[i] < s2[i])
            return -1;
        else if (s1[i] > s2[i])
            return 1;
    }
    return 0;
}
void strcat(char *d, const char *s)
{
    int len = strlen(d);
    strcpy(d + len, s);
}
class MyString
{
    // 在此处补充你的代码
    char *p;

public:
    MyString(const char *s)
    {
        if (s)
        {
            p = new char[strlen(s) + 1];
            strcpy(p, s);
        }
        else
            p = NULL;
    }
    MyString()
    {
        p = NULL;
    };

    MyString(const MyString &s)
    {
        if (s.p)
        {
            p = new char[strlen(s.p) + 1];
            strcpy(p, s.p);
        }
        else
            p = NULL;
    }
    friend ostream &operator<<(ostream &o, const MyString &s)
    {
        if (s.p)
            o << s.p;
        return o;
    }
    MyString operator=(const MyString &s)
    {
        if (s.p)
        {
            p = new char[strlen(s.p) + 1];
            strcpy(p, s.p);
        }
        else
            p = NULL;
        return *this;
    }
    MyString operator+(const MyString &s)
    {
        char *temp = new char[strlen(p) + strlen(s.p) + 1];
        strcpy(temp, p);
        strcat(temp, s.p);
        temp[strlen(p) + strlen(s.p)] = 0;
        return MyString(temp);
    }
    friend MyString operator+(const char *s, MyString &r)
    {
        return MyString(s) + r;
    }
    friend MyString operator+(MyString &r, const char *s)
    {
        return r + MyString(s);
    }
    char &operator[](int n)
    {
        return p[n];
    }
    MyString &operator+=(const char *s)
    {
        strcat(p, s);
        return *this;
    }
    friend int operator<(const MyString &s, const MyString &r)
    {
        if (strcmp(s.p, r.p) == -1)
            return 1;
        else
            return 0;
    }
    friend int operator>(const MyString &s, const MyString &r)
    {
        if (strcmp(s.p, r.p) == 1)
            return 1;
        else
            return 0;
    }
    friend int operator==(const MyString &s, const MyString &r)
    {
        if (strcmp(s.p, r.p) == 0)
            return 1;
        else
            return 0;
    }
    MyString operator()(int axis, int len)
    {
        char *temp = new char[len + 1];
        for (int i = 0; i < len; i++)
        {
            temp[i] = p[axis + i];
        }
        temp[len] = 0;
        return MyString(temp);
    }
};

int CompareString(const void *e1, const void *e2)
{
    MyString *s1 = (MyString *)e1;
    MyString *s2 = (MyString *)e2;
    if (*s1 < *s2)
        return -1;
    else if (*s1 == *s2)
        return 0;
    else if (*s1 > *s2)
        return 1;
}
int main()
{
    freopen("out.txt", "w", stdout);
    MyString s1("abcd-"), s2, s3("efgh-"), s4(s1);
    MyString SArray[4] = {"big", "me", "about", "take"};
    cout << "1. " << s1 << s2 << s3 << s4 << endl;

    s4 = s3;

    s3 = s1 + s3;

    cout << "2. " << s1 << endl;
    cout << "3. " << s2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;

    cout << "6. " << s1[2] << endl;
    s2 = s1;

    s1 = "ijkl-";
    s1[2] = 'A';
    cout << "7. " << s2 << endl;
    cout << "8. " << s1 << endl;
    s1 += "mnop";
    cout << "9. " << s1 << endl;
    s4 = "qrst-" + s2;
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";
    cout << "11. " << s1 << endl;
    qsort(SArray, 4, sizeof(MyString), CompareString);
    for (int i = 0; i < 4; i++)
        cout << SArray[i] << endl;
    // s1的从下标0开始长度为4的子串
    cout << s1(0, 4) << endl;
    // s1的从下标5开始长度为10的子串
    cout << s1(5, 10) << endl;
    return 0;
}