#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#pragma pack(1)

using namespace std;

typedef unsigned char BYTE;
typedef unsigned int DWORD;
typedef unsigned short WORD;
typedef long LONG;

class Head
{
public:
    WORD type;
    DWORD bfsize;
    WORD r1;
    WORD r2;
    DWORD offBits;
};

class Info
{
public:
    DWORD size;
    LONG w;
    LONG h;
    WORD biPlanes;
    WORD bitc;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
};

class RGB24
{
public:
    RGB24()
    {
        green = 0;
        red = 0;
        blue = 0;
    }
    BYTE green;
    BYTE red;
    BYTE blue;
};

class RGB32 : public RGB24
{
public:
    RGB32() : RGB24(), alpha(0){};
    BYTE alpha;
};

int getZero(Info &info)
{
    int t = (info.w * info.bitc + 31) / 8;
    t -= t % 4;
    return t - info.w * info.bitc / 8;
}

template <typename T>
bool Trans(ifstream &src, ofstream &dest, Head &head, Info &info)
{
    Head new_head = head;
    Info new_info = info;
    new_info.h = info.w;
    new_info.w = info.h;

    int Zero = getZero(info);
    T *pic = new T[info.h * info.w];

    for (int i = 0; i < info.h; i++)
    {
        src.read((char *)(pic + i * info.w), info.w * sizeof(T));
        src.seekg(Zero, ios::cur);
    }

    Zero = getZero(new_info);
    char *null = new char[Zero + 1];
    memset(null, 0, Zero + 1);
    new_info.biSizeImage = new_info.h * (new_info.w + Zero);
    new_head.bfsize = new_info.biSizeImage + sizeof(new_head) + sizeof(new_info);
    T *new_pic = new T[new_info.w * new_info.h];

    for (int i = 0; i < new_info.h; i++)
    {
        for (int j = 0; j < new_info.w; j++)
        {
            *(new_pic + (new_info.h - 1 - i) * new_info.w + j) =
                *(pic + j * info.w + i);
        }
    }
    dest.write((char *)&new_head, sizeof(Head));
    dest.write((char *)&new_info, sizeof(Info));

    for (int i = 0; i < new_info.h; i++)
    {
        dest.write((char *)(new_pic + new_info.w * i), new_info.w * sizeof(T));
        dest.write((char *)null, Zero);
    }
    return true;
}

int main(int argc, char *argv[])
{
    char *srcname;
    char *destname;
    if (argc == 1)
    {
        cout << "use \"src.bmp\" as default input bmp file name, and \"dest.bmp\" as default ouput name\n";
        srcname = new char[10];
        destname = new char[10];
        strcpy(srcname, "src.bmp");
        strcpy(destname, "dest.bmp");
    }
    else
    {
        srcname = argv[1];
        destname = argv[2];
    }
    Head head;
    Info info;
    ifstream src(srcname, ios::in | ios::binary);
    if (!src)
    {
        cout << "文件读取失败~" << endl;
        return 0;
    }
    ofstream dest(destname, ios::out | ios::binary);

    src.read((char *)&head, sizeof(Head));
    src.read((char *)&info, sizeof(Info));

    if (info.bitc == 24)
        Trans<RGB24>(src, dest, head, info);
    else
        Trans<RGB32>(src, dest, head, info);
    return 0;
}