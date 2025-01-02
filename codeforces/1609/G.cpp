// LUOGU_RID: 157109432
#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define eb emplace_back
using namespace std;
using ll=long long;
using pii=pair<int,int>;
constexpr int N=1E5+10;
constexpr int inf=1E9;
constexpr int p=998244353;
int qpow(int x,int n){int y=1;for(;n;n>>=1,x=1LL*x*x%p)if(n&1)y=1LL*y*x%p;return y;}
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

ll a[110],b[N],f[N],g[N],n,m,q;
void add(int i,ll x)
{
    ll y=(i-1)*x;
    for(;i<=m;i+=i&-i)
    {
        f[i]+=x;
        g[i]+=y;
    }
}
ll ask(int i)
{
    ll u=0,v=0;
    for(int j=i;j;j-=j&-j)
    {
        u+=f[j];
        v+=g[j];
    }
    return u*i-v;
}
int lb(ll x)
{
    int i=0;
    for(int j=1<<17;j>>=1;)
    {
        if(i+j<=m&&f[i+j]<x)
        {
            x-=f[i+=j];
        }
    }
    return i;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>q;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=m;++i)cin>>b[i];
    ll s=(a[1]+b[1])*(n+m-1);
    for(int i=n;i>1;--i)
    {
        a[i]-=a[i-1];
        s+=a[i]*(n-i+1);
    }
    for(int i=m;i>1;--i)
    {
        b[i]-=b[i-1];
        s+=b[i]*(m-i+1);
    }
    add(2,b[2]);
    for(int i=3;i<=m;++i)add(i,b[i]-b[i-1]);
    for(int op,k,d;q--;)
    {
        cin>>op>>k>>d;
        if(op&1)
        {
            if(k==n)s+=d*(n+m-1),--k;
            for(int i=n-k+1;i<=n;++i)a[i]+=d;
        }
        else
        {
            if(k==m)s+=d*(n+m-1),--k;
            add(m-k+1,d);
        }
        s+=1LL*k*(k+1)/2*d;
        ll t=0;
        for(int i=2;i<=n;++i)
        {
            int j=lb(a[i]);
            t+=a[i]*(m-j)+ask(j);
        }
        cout<<s+t<<'\n';
    }
    return 0;
}
