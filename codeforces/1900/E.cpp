#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<bitset>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(...) 0
#else
#include "debug.h"
#endif

#define x first 
#define y second 
#define ALL(a) a.begin(),a.end()
using namespace std;

typedef pair<int,int> PII;
typedef pair<PII,int> PIII;
typedef long long LL;
const int N = 2e5 + 10;
vector<int> g[N],scc[N];
int stk[N],dfn[N],low[N],id[N],cnt[N],scc_cnt,timestamp,top;
LL dist[N],f[N],val[N];
bool in_stk[N];
int a[N],n,m;

void tarjan(int u)
{
    dfn[u] = low[u] = ++timestamp;
    in_stk[u] = true,stk[++top] = u;
    for(int i : g[u])
    {
        if(!dfn[i])
        {
            tarjan(i);
            low[u] = min(low[u],low[i]);
        }
        else if(in_stk[i]) low[u] = min(low[u],dfn[i]);
    }
    if(low[u] == dfn[u])
    {
        int y;
        scc_cnt++;
        do
        {
            y = stk[top--];
            id[y] = scc_cnt;
            cnt[scc_cnt] ++;
            val[scc_cnt] += a[y];
            in_stk[y] = false;
        } while (y != u);      
    }
}

void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) 
    {
        g[i].clear();
        scc[i].clear();
        low[i] = dfn[i] = f[i] = dist[i] = cnt[i] = val[i] = 0;
        top = timestamp = scc_cnt = 0;
    }
    for(int i = 1; i <= n; i++) cin >> a[i];
    while(m--)
    {
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    for(int i = 1; i <= n; i++) 
        if(!dfn[i]) tarjan(i);
    for(int i = 1; i <= n; i++) 
        for(int j : g[i])
        {
            if(id[i] != id[j])
                scc[id[i]].push_back(id[j]);
        }
    //debug(scc,scc_cnt + 1);
    for(int i = scc_cnt; i; i--)
    {
        if(!dist[i]) dist[i] = cnt[i],f[i] = val[i];
        for(int j : scc[i]) 
        {
            if(dist[j] < dist[i] + cnt[j])
            {
                dist[j] = dist[i] + cnt[j];
                f[j] = f[i] + val[j];
            }
            else if(dist[j] == dist[i] + cnt[j])
            {
                f[j] = min(f[j],f[i] + val[j]);
            }
          //  debug(cnt[j],val[j],dist[j],f[j]);
        }
    }
    LL mx = 0, mn = LONG_LONG_MAX;
    for(int i = 1; i <= scc_cnt; i++) 
        if(dist[i] > mx) 
        {
            mx = dist[i];
            mn = f[i];
        }
        else if(dist[i] == mx)
        {
            mn = min(mn,f[i]);
        }
    cout << mx << " " << mn << "\n";
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}