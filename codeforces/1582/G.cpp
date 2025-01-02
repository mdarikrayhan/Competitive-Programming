// LUOGU_RID: 160555708
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<pair<ll,ll>,ll> P3;
typedef pair<pair<ll,ll>,pair<ll,ll> >P4;
#define mkp make_pair
#define fi first
#define se second
#define popcnt __builtin_popcountll
#define pb emplace_back
//#define FastIO
//#define OIcontest
const ll mod=998244353;
const ll maxn=500005;

inline ll read(){
	ll x=0,f=1; char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar(); return x*f;
}
inline ll lowbit(ll x){ return x&-x; }
struct Bit{
	ll c[maxn];
	void update(ll x,ll w){ ++x; while(x<maxn) c[x]+=w, x+=lowbit(x);}
	ll query(ll x){ ++x; ll res=0; while(x) res+=c[x], x-=lowbit(x); return res; }
}bit;

inline ll maxx(ll a,ll b){ return a>b?a:b; }
inline ll minn(ll a,ll b){ return a<b?a:b; }
inline void chkmax(ll &a,ll b){ a = maxx(a, b); }
inline void chkmin(ll &a,ll b){ a = minn(a, b); }

inline void _Add(ll &a,ll b){ a+=b; if(a>=mod) a-=mod; }
inline void _Minus(ll &a,ll b){ a-=b; if(a<0) a+=mod; }
inline ll Add(ll a,ll b){ a+=b; if(a>=mod) a-=mod; return a; }
inline ll Minus(ll a,ll b){ a-=b; if(a<0) a+=mod; return a; }

inline ll qpow(ll a,ll b){
    ll ans=1, base=a;
    while(b){ if(b&1) ans=1ll*ans*base%mod; base=1ll*base*base%mod; b>>=1; }
    return ans;
}
struct Comb{
    ll fac[maxn], inv[maxn];
    Comb(){
       fac[0]=1; for(ll i=1;i<=maxn-5;i++) fac[i]=1ll*fac[i-1]*i%mod;
	   inv[maxn-5]=qpow(fac[maxn-5],mod-2); for(ll i=maxn-6;i>=0;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
    }
    ll C(ll a,ll b){ if(a<0 || b<0 || a<b) return 0; return 1ll*fac[a]*inv[b]%mod*inv[a-b]%mod; }
}comb;
ll Fac(ll x){return comb.fac[x];}ll iFac(ll x){return comb.inv[x];}ll Inv(ll x){return qpow(x, mod-2);}
/*--------------head------------------*/
ll vis[1000005],prim[1000005],cnt,low[1000005];
void init(){
    for(ll i=2;i<=1000000;i++){
        if(!vis[i]) prim[++cnt] = i, low[i] = i;
        for(ll j=1;j<=cnt && i*prim[j]<=1000000;j++){
            vis[i*prim[j]]=1; low[i*prim[j]]=prim[j];
            if(i%prim[j]==0) break;
        }
    }
}
void clear(){  }
ll n,a[1000005],pre[1000005],w[1000005],st[1000005],tp; char str[1000005];
vector<ll>stk[1000005];
void solve(){
    n=read();
    for(ll i=1;i<=n;i++) a[i]=read(); scanf("%s", (str+1));
    for(ll i=1;i<=n;i++){
        if(str[i]=='*'){
            while(a[i]>1){
                stk[low[a[i]]].pb(i);
                a[i]/=low[a[i]];
            }
            pre[i]=i;
        }else{
            if(a[i] == 1){
                pre[i]=i;
            }else{
                pre[i]=1e18;
                while(a[i]>1){
                    if(stk[low[a[i]]].size() == 0){
                        pre[i] = 0;
                        break;
                    }
                    chkmin(pre[i], stk[low[a[i]]].back()); stk[low[a[i]]].pop_back();
                    a[i]/=low[a[i]];
                }
            }
        }
        // cout<<i<<" has: "<<pre[i]<<endl;
    }
    ll ans = 0;
    for(ll i=n;i>=1;i--){
        ll now = 1;
        while(tp && pre[w[tp]] >= pre[i]) now += st[tp], --tp;
        w[++tp] = i, st[tp] = now;
        if(pre[i] == i) ans += now;// cout<<"at "<<i<<" has "<<now<<endl;
    }
    printf("%lld\n", ans);
}
int main(){
    #ifdef OIcontest
        freopen(".in","r",stdin);
        freopen(".out","w",stdout);
    #endif
    #ifdef FastIO
        ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    #endif
    init();
    ll T=1;
    while(T--) clear(), solve();
    return 0;
}
/*
Input1 Text Copied:


Answer1 Text Copied:


Input2 Text Copied:


Answer2 Text Copied:
*/