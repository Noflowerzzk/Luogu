#include <iostream>

using namespace std;
using ll = long long;
const int N = 1003;

bool a[N][N];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, n; cin >> m >> n;

    for(int i = 1; i <= n; ++ i)
        for(int j = i; j <= m; ++ j)
        {
            int m; cin >> m;
            if(m == 'F') a[i][j] = true;
        }
    

        

    return 0;
}