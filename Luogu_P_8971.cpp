// dfs + 剪枝
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;
using ll = long long;

const ll p = 1e9 + 7;
const int N = 2e5 + 3;

struct Node
{
    int n;  // 编号
    ll w;   // 长度
};


vector<Node> g[N];
vector<int> rt;
bitset<N> vis;
ll l, r, _l, _r;
int pre[N];

void init(int n)
{
    for (int i = 1; i <= n; ++ i)
    {
        pre[i] = i;
        g[i].clear();
    }
    rt.clear();
    vis.reset();
    _l = l, _r = r;
}

int root(int x)
{
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}

void merge(int x, int y)
{
    pre[root(x)] = root(y);
}

ll dfs(int x, ll add = 0, bool sgn = true)
{
    vis[x] = true;

    for(auto &i : g[x])
    {
        if(vis[i.n]) continue;
        dfs(i.n, i.w - add, !sgn);
    }

    _l = max(_l, sgn ? (l - add) : (add - r));
    _r = min(_r, sgn ? (r - add) : (add - l));

    return (_l <= _r) ? (_r - _l + 1) : 0;
}

void solve()
{
    int n; cin >> n >> l >> r;

    init(n);

    for(int i = 1; i < n; ++ i)
    {
        int op; cin >> op;
        if(op)
        {
            int u, v, w; cin >> u >> v >> w;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
            merge(u, v);
        }
        else
        {
            int u, v; cin >> u >> v;
        }
    }

    for(int i = 1;i <= n; ++ i) if(root(i) == i) rt.push_back(i);
    // 前期处理完成

    ll res = 1;
    for(auto &r0 : rt)
    {
        _l = l, _r = r;
        res = res * dfs(r0) % p;
    }

    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int _; cin >> _;
    while(_--) solve();

    return 0;
}