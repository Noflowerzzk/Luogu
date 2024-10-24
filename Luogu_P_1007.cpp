#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

const int N = 5e3 + 3;
const int INF = 1e8;

int a[N];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int l, n, Max = 0, Min = 0;

    cin >> l >> n;

    if(n == 0)
    {
        cout << 0 << ' ' << 0 << '\n';
        return 0;
    }
    // if(l == 1)
    // {
    //     cout << 1 << 1 <<'\n';
    //     return 0;
    // }

    for (int i = 1; i <= n; ++ i) cin >> a[i];

    sort(a + 1, a + n + 1);
    
    int m = 0;
    for(int i = 1; i <= n; ++ i) m = max(m, min(a[i], l + 1 - a[i]));

    Min = m;
    Max = max(l + 1 - a[1], a[n]);

    cout << Min << ' ' << Max << '\n';

    return 0;
}