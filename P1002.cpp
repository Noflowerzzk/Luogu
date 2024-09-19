#include <iostream>

using namespace std;

#define INT long long int

int x1, y1, x2, y2;

INT f(int i, int j)
{
    if (i < 0 || j < 0 || (i == x2 && j == y2) || (i == x2 - 1 && j == y2 - 2) || (i == x2 - 2 && j == y2 - 1) || (i == x2 + 1 && j == y2 + 2) || (i == x2 + 2 && j == y2 + 1) || (i == x2 - 1 && j == y2 + 2) || (i == x2 + 1 && j == y2 - 2) || (i == x2 - 2 && j == y2 + 1) || (i == x2 + 2 && j == y2 - 1))
        return 0;
    else if (i == 0 && j == 0)
        return 1;
    else
        return f(i - 1, j) + f(i, j - 1);
}

int main()
{
    INT sum = 0;

    cin >> x1 >> y1 >> x2 >> y2;

    cout << f(x1, y1);

    return 0;
}