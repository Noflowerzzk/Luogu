// 双向链表
#include <iostream>

using namespace std;

const int N = 1e5 + 2;

struct Node{
    int pre, suc;
} a[N];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n; cin >> n;

    for(int i = 2; i <= n; ++ i)
    {
        int k, p; cin >> k >> p;
        if(p)
        {
            a[i].suc = a[k].suc;
            a[a[k].suc].pre = i;
            a[k].suc = i;
            a[i].pre = k;
        }
        else
        {
            a[a[k].pre].suc = i;
            a[i].pre = a[k].pre;
            a[k].pre = i;
            a[i].suc = k;
        }
    }

    int m; cin >> m;
    while(m --)
    {
        int x; cin >> x;

        a[a[x].pre].suc = a[x].suc;
        a[a[x].suc].pre = a[x].pre;
        a[x].pre = a[x].suc = 0;
    }

    int strt = 0;
    for(int i = 1; i <= n; ++ i)
        if(a[i].pre == 0 && a[i].suc != 0)
        {
            strt = i;
            break;
        }

    cout << strt << ' ';
    while(true)
    {
        if(0 == (strt = a[strt].suc)) break;
        cout << strt << ' ';
    }

    return 0;
}