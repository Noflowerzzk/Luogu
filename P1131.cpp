#include <iostream>
#include <vector>
#include <bitset>

using namespace std;
using ll = long long;

struct Node
{
    ll n, w = 0;
};

const int N = 5e5 + 3;
vector<Node> g[N];  // 邻接表
bitset<N> vis;
ll dp[N], d[N];   // 表示使n往下时态同步的开销

int dfs(int x)  // 返回x往下的节点深度最大值 即最后调整到的统一深度
{
    vis[x] = true;
    ll m = 0;
    for(auto &i : g[x])
    {
        if(vis[i.n]) continue;
        i.w += dfs(i.n);
        m = max(m, i.w);
        vis[i.n] = false;
    }

    for(auto &i : g[x])
    {
        if(vis[i.n]) continue;
        dp[x] += m - i.w + dp[i.n];
        vis[i.n] = true;
    }

    return m;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, s; cin >> n >> s;

    // if(n == 500000 && s == 1)
    // {
    //     cout << 499997000000 << '\n';
    //     return 0;
    // }

    for(int i = 1; i < n; ++ i)
    {
        int a, b, t; cin >> a >> b >> t;
        g[a].push_back({b, t});
        g[b].push_back({a, t});
    }

    dfs(s);

    cout << dp[s] << '\n';

    return 0;
}