#include <iostream>
#include <vector>
#include <bitset>

using namespace std;
using ll = long long;

const int N = 1e5 + 4;
// const ll NINF = -1e10;

vector<int> g[N];
int w[N];
bitset<N> vis;

ll ans;

// ll max(ll a, ll b) {return a > b ? a : b;}

ll dfs(int p)
{
    ll ret = 0;
    vis[p] = true;

    for(auto &i : g[p])
    {
        if(vis[i]) continue;
        ll t = dfs(i);
        ret += (t > 0) ? t : 0;
    }
    ans = max(ans, ret + w[p]);

    return ret + w[p];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;

    for(int i = 1; i <= n; ++ i) cin >> w[i];

    for(int i = 1; i < n; ++ i)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);
    cout << ans << '\n';

    return 0;
}