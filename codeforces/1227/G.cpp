/*-----------------------------------------------*/
/* Everything that kills me makes me feel alive. */
/* Email: <a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="87e5f5e2e6ecf7ebf2f4c7e1e8ffeae6eeeba9e4e8ea">[email&#160;protected]</a>                  */
/* Author: wzj_zhzx_oicon / BreakPlus            */
/*-----------------------------------------------*/
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
	ll c[maxn], _x[maxn], _w[maxn], tp=0;
	void update(ll x,ll w){ _x[++tp]=x, _w[tp]=w; while(x<maxn) c[x]+=w, x+=lowbit(x);}
	void update2(ll x,ll w){ while(x<maxn) c[x]+=w, x+=lowbit(x);}
	ll query(ll x){ ll res=0; while(x) res+=c[x], x-=lowbit(x); return res; }
	void clear(){ for(ll i=1;i<=tp;i++) update2(_x[i], -_w[i]); tp=0;}
	void fclear(){ tp=0; memset(c, 0, sizeof(c)); }
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
    ll C(ll a,ll b){
		if(a<0 || b<0 || a<b) return 0; return 1ll*fac[a]*inv[b]%mod*inv[a-b]%mod;
	}
};
//ll Fac(ll x){return comb.fac[x];}ll iFac(ll x){return comb.inv[x];}ll Inv(ll x){return qpow(x, mod-2);}
/*--------------head------------------*/
 
int n,a[1005],ans[1005][1005];
struct Node{
	int id, w;
}node[1005];
bool cmp(Node A, Node B){
	return A.w < B.w;
}
void init(){
 
}
void clear(){  }
 
void solve(){
	n=read();
	for(int i=1;i<=n;i++){
		node[i].w=a[i]=read(), node[i].id=i;
	}
	stable_sort(node+1, node+n+1, cmp);
	int now = 0;
	for(int i=1;i<=n;i++){
//		cout<<"turn "<<i<<endl;
		int que = node[i].w;
		for(int j=now+1;j<=now+que;j++){
			for(int k=now+1;k<=now+que;k++){
				ans[j][node[k].id] = (j != k-1);
				node[k].w -= (j != k-1);
			}
		}
		for(int j=now+1;j<=now+que;j++){
			for(int k=now+que+1; k<=now+que+node[j].w; k++)
				ans[k][node[j].id] = 1;
		}
		int rd = n - now - que;
		for(int j=now+que+1; j<=n; j++){
//			cout<<"checking "<<j<<" has "<<node[j].w<<endl;
			
			if(node[j].w > rd){
				int dc = node[j].w - rd;
				for(int k=now+1; k<=now+dc; k++) ans[k][node[j].id] = 1;
				node[j].w = rd; 
			}
		}
		now += que;
		i = now;
	}
	printf("%d\n", n+1);
	for(int i=1; i<=n+1; i++){
		for(int j=1; j<=n; j++){
			printf("%d", ans[i][j]);
		}
		puts("");
	}
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