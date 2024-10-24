#include <stdio.h>

#define N 100005

int stk[N], top, m, n, in[N], out[N];

void solve()
{
    scanf("%d", &n);

    top = 0;    // top 当前栈顶
    stk[top] = 0;
    for(int i = 1; i <= n; ++ i) scanf("%d", &in[i]);

    for(int i = 1; i <= n; ++ i) scanf("%d", &out[i]);

    int j = 1;
    for(int i = 1; i <= n; ++ i)
    {
        while(stk[top] == out[j]) // 弹出能形成a的元素
            top --, j ++;

        stk[++ top] = in[i];    // i入栈
    }

    while(stk[top] == out[j])
        top --, j ++;

    // 最后top >= 1
    if(top <= 1) printf("Yes\n");
    else printf("No\n");
    return;
}

int main()
{
    int _; 
    scanf("%d", &_);
    while (_ --) solve();
}
