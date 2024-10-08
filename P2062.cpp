// dp
#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

const int N = 1e6 + 3;

int a[N], dp[N], mx[N]; // dp[i]表示前i个人能排的队伍数最大值

// dp[i] = max(dp[1 .. a[i]]) + 1
// mx[i] = max(dp[1 .. i])

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; ++ i) cin >> a[i];

    sort(a + 1, a + n + 1);

    dp[1] = 1;

    for(int i = 1; i <= n; ++ i)
    {
        if(i >= a[i]) dp[i] = mx[i - a[i]] + 1;
        mx[i] = max(mx[i - 1], dp[i]);
    }

    cout << dp[n] << '\n';

    return 0;
}