// LUOGU_RID: 158451220
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const int N = 2e5+5,mod = 1e9+7;
ll phi[N],F[N];
ll ans,S1[N],S2[N],cur;
int n,vis[N],pr[N],tot,a[N],sz[N],son[N];
ll qpow(ll x,ll y)
{
    ll res = 1;
    for(;y;y>>=1,x=x*x%mod) if(y&1) res = res*x%mod;
    return res;
}
ll Inv(int x){return qpow(x,mod-2);}
vector<int>e[N];
vector<int>p[N];
void getson(int u,int fa)
{
    sz[u] = 1;
    for(auto v:e[u]) if(v != fa)
    {
        getson(v,u);
        sz[u] += sz[v];
        if(sz[son[u]] < sz[v]) son[u] = v;
    }
}
void upd(int x,ll v)
{
    for(auto y:p[x])
    {
        cur = (cur - S1[y]*S2[y]%mod*F[y]%mod + mod)%mod;
        S1[y] = (S1[y] - phi[x]*v%mod + mod)%mod;
        S2[y] = (S2[y] + phi[x]*v)%mod;
        cur = (cur + S1[y]*S2[y]%mod*F[y])%mod;
    }
}
void clear(int u,int fa)
{
    upd(a[u],mod-1);
    for(auto v:e[u]) if(v != fa) clear(v,u);
}
void ins(int u,int fa)
{
    upd(a[u],1);
    for(auto v:e[u]) if(v != fa) ins(v,u);
}
void dfs(int u,int fa)
{
    for(auto v:e[u]) if(v != fa && v != son[u]) dfs(v,u),clear(v,u);
    if(son[u]) dfs(son[u],u);
    upd(a[u],1);
    for(auto v:e[u]) if(v != fa && v != son[u]) ins(v,u);
    ans = (ans + cur)%mod;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    phi[1] = 1;
    F[1] = 1;
    for(int i = 2;i <= n;i++)
    {
        if(!vis[i]) vis[i] = pr[++tot] = i,phi[i] = i-1,F[i] = i*Inv(phi[i])%mod-1;
        for(int j = 1;pr[j]*i <= n;j++)
        {
            vis[i*pr[j]] = pr[j];
            if(vis[i] == pr[j])
            {
                F[i*pr[j]] = 0;
                phi[i*pr[j]] = phi[i]*pr[j];
                break;
            }
            F[i*pr[j]] = F[i]*F[pr[j]]%mod;
            phi[i*pr[j]] = phi[i]*phi[pr[j]];
        }
    }
    for(int i = 1;i <= n;i++)
        for(int j = i;j <= n;j += i) p[j].pb(i),S1[i] = (S1[i] + phi[j])%mod;
    for(int i = 1;i <= n;i++) cin>>a[i];
    for(int i = 1,u,v;i < n;i++) 
    {
        cin>>u>>v;
        e[u].pb(v),e[v].pb(u);
    }
    getson(1,0);
    dfs(1,0);
    upd(a[6],-1),upd(a[7],-1);
    cout<<ans*2*Inv(n)%mod*Inv(n-1)%mod<<"\n";
    return 0;
}