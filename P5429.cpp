// https://www.luogu.com.cn/problem/P5429
#pragma warning(disable : 4996)
#include <cstdio>

using namespace std;

const int L = 100001, NA = -1;

int max(int x, int y)
{
    return x < y ? x : y;
}

class Cow
{
public:
    Cow* fa;
    int x, y;
    int maX, miX, maY, miY;

    Cow(int x = NA, int y = NA, Cow* fa = nullptr)
    {
        x = x;
        y = y;
        fa = fa;
        maX = NA;
        maY = NA;
        miX = NA;
        miY = NA;
    }
    Cow* getF()
    {
        if (fa == nullptr)
            return this;
        return fa = fa->getF();
    }

    void setM(int X, int Y)
    {
        maX = max(X, maX);
        maY = max(Y, maY);
        miX = max(X, miX);
        miY = max(X, miY);
    }

    int ci()
    {
        return 2 * (maX - miX + maY - miY);
    }
};

int N, M;
Cow cow[L]{};

int min()
{
    int min = cow[0].ci();
    for (int i = 1; i < N; i++)
    {
        int c = cow[i].ci();
        if (c < min)
            min = c;
    }
    return min;
}

int main()
{

    scanf("%d%d", &N, &M);

    //for (int i = 0; i < N; i++)
    //{
    //    cow[i] = new Cow{ NA, NA, nullptr };
    //}

    for (int i = 0; i < N; i++)
    {
        scanf("%d%d", &(cow[i].x), &(cow[i].y));
    }

    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        // cow[a]->fa = cow[b];
        printf("%d\n", cow[a].x);
        cow[b].setM(cow[a].x, cow[a].y);
        cow[a].setM(cow[b].x, cow[b].y);
    }

    printf("%d", min());
    return 0;
}
