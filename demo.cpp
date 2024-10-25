#include <stdio.h>

#define N 1003

int stk[N], top, m, n, a[N];

void solve()
{
    top = 0;    // top 当前栈顶
    for(int i = 1; i <= n; ++ i) scanf("%d", &a[i]);

    int j = 1;
    for(int i = 1; i <= n; ++ i)
    {
        if(top == m + 1)    // 如果超出范围
        {
            printf("NO\n");
            return;
        }

        while(stk[top] == a[j]) // 弹出能形成a的元素
            top --, j ++;

        stk[++ top] = i;    // i入栈
    }
    if(top == m + 1)    // 如果超出范围
    {
        printf("NO\n");
        return;
    }

    while(stk[top] == a[j])
        top --, j ++;
    // 最后top >= 1
    if(top <= 1) printf("YES\n");
    else printf("NO\n");
    return;
}

int main()
{
    int _; 
    scanf("%d %d %d", &m, &n, &_);
    while (_ --) solve();
}
