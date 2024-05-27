// LUOGU_RID: 160446704
#include<bits/stdc++.h>
using namespace std;
template<class T1,class T2> bool cmax(T1& a,const T2& b){return a<b?a=b,1:0;}
template<class T1,class T2> bool cmin(T1& a,const T2& b){return b<a?a=b,1:0;}
#define fir(i,x,y,...) for(int i(x),##__VA_ARGS__;i<=(y);i++)
#define firr(i,x,y,...) for(int i(x),##__VA_ARGS__;i>=(y);i--)
#define fird(i,x,y,d,...) for(int i(x),##__VA_ARGS__;i<=(y);i+=(d))
#define firrd(i,x,y,d,...) for(int i(x),##__VA_ARGS__;i>=(y);i-=(d))
#define Yes cout<<"Yes\n"
#define No cout<<"No\n"
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define endl "\n"
#define ll long long
#define ull unsigned long long
int T;
bool _mul=1;
ll gcd(ll x,ll y){if(!y) return x;return gcd(y,x%y);}
ll power(ll b,ll p,ll mod){ll res=1;while(p){if(p&1) res=res*b%mod;b=b*b%mod;p>>=1;}return res;}
mt19937 rnd(time(0));
const int N=3e5+5,mod=998244353;
int n,m,h[N],ans;
ll a[N];
map<ll,int> mp;
void solve()
{
    ans=1;
    cin>>n>>m;
    fir(i,1,m,l,r)
    {
        cin>>l>>r;
        ll x=1ll*(rnd()%INT_MAX)*(rnd()%INT_MAX);
        a[l]^=x,a[r+1]^=x;
    }
    fir(i,1,n) a[i]^=a[i-1],mp[a[i]]++;
    for(auto [x,y]:mp)
    {
        if(y%2) ans=0;
        else ans=1ll*ans*h[y/2]%mod;
    }
    cout<<(ans+mod)%mod<<endl;
    mp.clear();
    fir(i,1,n+1) a[i]=0;
    return;
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    srand(time(0));
    h[0]=1;
    fir(i,1,300000) h[i]=1ll*h[i-1]*(4*i%mod-2)%mod*power(i+1,mod-2,mod)%mod;
    cin.tie(nullptr)->sync_with_stdio(false);
    if(_mul) cin>>T;
    else T=1;
    while(T--) solve();
    return 0;
}