// LUOGU_RID: 160072004
//By IceKylin
//-std=c++14 -O2 -static
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define _for(i,j,k) for(ll i(j),_(k);i<=_;++i)
#define _rep(i,j,k) for(ll i(j),_(k);i>=_;--i)
#define Tp template
#define Tn typename
constexpr int maxn=314514;
namespace __FastIO__{
	#define gc getchar
	#define pc putchar
	#define ios ios::sync_with_stdio(0)
    ll rd(){
        char c=gc(),f=0;ll x=0;
		for(;!isdigit(c);c=gc())if(c=='-')f=1;
        for(;isdigit(c);c=gc())x=x*10+c-'0';
		return f?-x:x;
    }
    void rd(ll&x){
		x=rd();
	}
    Tp<Tn ...R>void rd(ll&x,R&...r){
		rd(x),rd(r...);
	}
    Tp<Tn T>void wt(T x){
		if(x<0)x=-x,pc('-');
		if(x>9)wt(x/10);
		pc(x%10+'0');
	}
    Tp<Tn T>void wt(T x,char c){
		wt(x),pc(c);
	}
    Tp<Tn ...R,Tn T>void wt(T x,char c,R...r){
		wt(x),pc(c),wt(r...);
	}
    Tp<Tn T>void in(T a[],T n){
		_for(i,1,n)rd(a[i]);
	}
    Tp<Tn T>void out(T a[],T n){
		_for(i,1,n-1)wt(a[i],' ');
		wt(a[n],'\n');
	}
}
using namespace __FastIO__;
ll T,n,a[maxn],b[maxn],mi[maxn<<2],id[maxn],t[maxn];
queue<ll>bel[maxn];
#define ls (k<<1)
#define rs (k<<1|1)
void build(ll k,ll l,ll r){
	if(l==r){
		mi[k]=a[l];
		return;
	}
	ll mid=l+r>>1;
	build(ls,l,mid),build(rs,mid+1,r),mi[k]=min(mi[ls],mi[rs]);
}
void update(ll k,ll l,ll r,ll x){
	if(l==r){
		mi[k]=n+1;
		return;
	}
	ll mid=l+r>>1;
	if(x<=mid)update(ls,l,mid,x);
	else update(rs,mid+1,r,x);
	mi[k]=min(mi[ls],mi[rs]);
}
ll query(ll k,ll l,ll r,ll x){
	if(r<=x)return mi[k];
	ll mid=l+r>>1,ans=n+1;
	if(x>mid)ans=query(rs,mid+1,r,x);
	return min(ans,query(ls,l,mid,x));
}
signed main(){
	#define ONLINE_JUDGE
    #ifndef ONLINE_JUDGE
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    rd(T);
	while(T--){
		rd(n),in(a,n),in(b,n);
		_for(i,1,n)t[i]=0;
		_for(i,1,n)++t[a[i]];
		ll f=0;
		_for(i,1,n)if(--t[b[i]]<0){
			f=1;
			break;
		}
		if(f){
			printf("NO\n");
			continue;
		}
		build(1,1,n);
		_for(i,1,n)while(!bel[i].empty())bel[i].pop();
		_for(i,1,n)bel[a[i]].push(i);
		_for(i,1,n){
			ll x=bel[b[i]].front();
			bel[b[i]].pop();
			if(query(1,1,n,x)!=b[i]){
				f=1;
				break;
			}
			update(1,1,n,x);
		}
		printf(f?"NO\n":"YES\n");
	}
}