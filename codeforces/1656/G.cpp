// LUOGU_RID: 159721617
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define ll long long
#define _mp make_pair
#define _pb push_back
#define _1 first
#define _2 second
#define inf 3423423423423423422ll
#define MAX_N 522222

using namespace std;

ll read(){ll x = 0;char c = 0, v = 0;do{c = getchar();if(c == '-')v = 1;} while(c < '0' || c > '9');do{x = (x << 3) + (x << 1) + c - '0';c = getchar();} while(c >= '0' && c <= '9');return v ? -x : x;}
char gtc(){char c = 0;while(c < 33)c = getchar();return c;}

int n, m, p;
vector<int> vec[MAX_N];
int a[MAX_N], apr[MAX_N], offp[MAX_N];
int mat[MAX_N];
bool vis[MAX_N];
int ans[MAX_N], ans2[MAX_N];

void dfs(int x, vector<int>& vec)
{
    vis[x] = 1;
    vec._pb(x);
    if(x != p && !vis[mat[x]])
        dfs(mat[x], vec);
    if(x == p && !vis[(n + 1) >> 1])
        dfs((n + 1) >> 1, vec);
    if(!vis[n + 1 - x])
        dfs(n + 1 - x, vec);
}

void MAIN()
{
    n = read();
    for(int i = 1; i <= n; i++)
        a[i] = read();
    for(int i = 1; i <= n; i++)
        apr[a[i]]++;
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        if(apr[i] & 1)
            cnt++;
    if(cnt > 1)
    {
        printf("NO\n");
        return;
    }
    p = 0;
    if(cnt == 1)
    {
        for(int i = 1; i <= n; i++)
            if(i != ((n + 1) >> 1) && (apr[a[i]] & 1))
            {
                p = i;
                break;
            }
        if(!p)
        {
            printf("NO\n");
            return;
        }
    }
    for(int i = 1; i <= n; i++)
        if(i != p)
        {
            if(offp[a[i]])
            {
                int v = offp[a[i]];
                offp[a[i]] = 0;
                mat[i] = v, mat[v] = i;
            }
            else
                offp[a[i]] = i;
        }
    /*for(int i = 1; i <= n; i++)
        printf("%d ", mat[i]);
    printf("\n");
    return;*/
    m = 0;
    if(cnt == 1)
        dfs(p, vec[++m]);
    for(int i = 1; i <= n; i++)
        if(!vis[i])
            dfs(i, vec[++m]);
    int tot = 0;
    for(int i = 1; i <= m; i++)
        for(int j = 0; j <= vec[i].size() - 2; j++)
            ans[++tot] = vec[i][j];
    for(int i = 1; i <= m; i++)
        ans[++tot] = vec[i].back();
    for(int i = 1; i < n; i++)
        ans2[ans[i + 1]] = ans[i];
    ans2[ans[1]] = ans[n];
    printf("YES\n");
    for(int i = 1; i <= n; i++)
        printf("%d%c", ans2[i], " \n"[i == n]);
}

void CLEAR()
{
    for(int i = 0; i <= n + 1; i++)
    {
        a[i] = apr[i] = offp[i] = mat[i] = vis[i] = ans[i] = ans2[i] = 0;
        vec[i].clear();
    }
    n = m = p = 0;
}

void EXP()
{
    ;
}

int main()
{
    EXP();
    int T = read();
    while(T--)
        MAIN(), CLEAR();
    return 0;
}