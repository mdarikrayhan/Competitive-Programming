// LUOGU_RID: 159881392
//By IceKylin
//-std=c++14 -O2 -static
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define _for(i,j,k) for(int i(j),_(k);i<=_;++i)
#define _rep(i,j,k) for(int i(j),_(k);i>=_;--i)
#define Tp template
#define Tn typename
constexpr int maxn=114514;
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
namespace __Operations__{
    Tp<Tn T>void add(T&x,T y,T p){
		x+=y;
		if(x>=p)x-=p;
		if(x<0)x+=p;
	}
    Tp<Tn T>void gmx(T&x,T y){
		if(x<y)x=y;
	}
    Tp<Tn T>void gmi(T&x,T y){
		if(x>y)x=y;
	}
   	Tp<Tn T>T lowbit(T x){
	   	return x&-x;
	}
    Tp<Tn T>T qpow(T x,T y,T p,T k=1){
		for(x%=p;y;y>>=1,x=x*x%p)if(y&1)k=k*x%p;
		return k;
	}
	ll exgcd(ll a,ll b,ll&x,ll&y,ll d=1){
		return b?d=exgcd(b,a%b,y,x),y-=a/b*x,d:(x=1,y=0,a);
	}
}
using namespace __Operations__;
ll a1,a2,b1,b2,l,r;
ll div_c(ll x,ll y){
	if(y<0)x=-x,y=-y;
	return x<0?x/y:(x+y-1)/y;
}
ll div_f(ll x,ll y){
	if(y<0)x=-x,y=-y;
	return x<0?(x-y+1)/y:x/y;
}
signed main(){
	#define ONLINE_JUDGE
    #ifndef ONLINE_JUDGE
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    rd(a1,b1,a2,b2,l,r);
    if(b1>b2)swap(b1,b2),swap(a1,a2);
	ll x=0,y=0,d=exgcd(a1,-a2,x,y);
	if((b2-b1)%d){
		pc('0');
		return 0;
	}
	x=x*(b2-b1)/d;
	ll A1=abs(a2/__gcd(a1,a2)),A2=abs(a1/__gcd(a1,a2));
	x=x%A1;
	if(x<0)x+=A1;
	y=(a1*x-(b2-b1))/a2;
	if(y<0){
		y=y%A2;
		if(y<0)y+=A2;
		x=((b2-b1)+y*a2)/a1;
	}
	ll L=max(0LL,div_c(l-a1*x-b1,a1*A1));
	ll R=div_f(r-a1*x-b1,a1*A1);
	wt(max(0ll,R-L+1));
}