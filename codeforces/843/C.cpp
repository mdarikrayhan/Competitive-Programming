// LUOGU_RID: 155546607
#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10;
int head[N], ver[2 * N], Next[2 * N], tot = 1, n, root[N], stk[N], top, fa[N];

struct Op{
    int x, y, z;
};
vector <Op> G1;

void add(int x, int y)
{
    ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}


int dfswc(int x, int fa, int tot)
{
//    if(del[x]) return 0;
    int sz = 1, mp = 0;
    for(int i = head[x]; i; i = Next[i])
    {
        int y = ver[i];
        if(y != fa)
        {
            int t = dfswc(y, x, tot);
            mp = max(t, mp);
            sz += t;
        }
    }
    mp = max(mp, tot - sz);
    if(mp * 2 <= tot) root[x] = 1;
    return sz;
}
void dfs1(int x)
{
    for(int i = head[x]; i; i = Next[i])
    {
        int y = ver[i];
        if(y != fa[x])
        {
            fa[y] = x;
            dfs1(y);
        }
    }
    stk[++top] = x;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
    {
        int x, y; scanf("%d%d", &x, &y); add(x, y), add(y, x);
    }
    dfswc(1, 0, n);
    for(int rt = 1; rt <= n; rt++)
    {
        if(root[rt])
        {
            for(int i = head[rt]; i; i = Next[i])
            {
                int p = ver[i];
                if(!root[p])
                {
                    top = 0; stk[top] = rt; fa[p] = rt; dfs1(p);
                    G1.push_back(Op({rt, p, stk[1]}));
                    for(int j = 1; j < top; j++)
                    {
                        if(fa[stk[j]] != stk[j + 1]) G1.push_back(Op({stk[j], fa[stk[j]], stk[j + 1]}));
                    }
                    for(int j = top - 3; j >= 0; j--)
                    {
                        G1.push_back(Op({stk[j], stk[j + 1], stk[top - 1]}));
                    }
                }
            }
        }
    }
    printf("%d\n", G1.size());
    for(auto& op : G1) printf("%d %d %d\n", op.x, op.y, op.z);
    return 0;
}
