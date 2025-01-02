#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define F first
#define S second
using namespace std;
typedef int ll;
const ll oo=2e5+9;
ll tt=1,n,a[oo],sz[oo],c[oo];
vector<ll>v[oo],dv[oo];
bool vis[oo];
long long ans[oo],dp[oo];
set<ll,greater<ll>>s;
void build_sz(ll nd,ll par)
{
    sz[nd]=1;
    for(auto&z:v[nd])
        if(z!=par&&!vis[z])
            build_sz(z,nd),sz[nd]+=sz[z];
}
ll get_centroid(ll nd,ll par,ll k)
{
    for(auto&z:v[nd])
        if(z!=par&&!vis[z]&&sz[z]*2>k)
            return get_centroid(z,nd,k);
    return nd;
}
void calc(ll d,ll p,ll g)
{
    g=__gcd(a[d],g);
    for(auto&z:dv[g])
        ans[z]+=c[z];
    for(auto&z:v[d])
        if(z!=p&&!vis[z])
        calc(z,d,g);
}
void add(ll d,ll p,ll g)
{
    g=__gcd(a[d],g);
    for(auto&z:dv[g])
        c[z]++;
    for(auto&z:v[d])
        if(z!=p&&!vis[z])
        add(z,d,g);
}
void centroid(ll nd)
{
    build_sz(nd,nd);
    ll x=get_centroid(nd,nd,sz[nd]);
    vis[x]=1;
    for(auto&z:dv[a[x]])
        ans[z]++,c[z]++;
    for(auto&z:v[x])
        if(!vis[z])
    {
        calc(z,x,a[x]);
        add(z,x,a[x]);
    }
    for(auto&z:dv[a[x]])
        c[z]=0;
    for(auto&z:v[x])
        if(!vis[z])
            centroid(z);
}
void solve()
{
    cin>>n;
    for(ll i=1; i<=n; i++)
        cin>>a[i];
    for(ll i=1; i<n; i++)
    {
        ll x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    centroid(1);
    for(ll i=2e5;i;i--)
    {
        for(ll j=i+i;j<=2e5;j+=i)
            ans[i]-=ans[j];
    }
    for(ll i=1; i<=2e5; i++)
        if(ans[i])
            cout<<i<<" "<<ans[i]<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    for(ll i=1; i<=2e5; i++)
        for(ll j=i; j<=2e5; j+=i)
            dv[j].push_back(i);
    //cin>>tt;
    while(tt--)
        solve();
    return 0;
}
