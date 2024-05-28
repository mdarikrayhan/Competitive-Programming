// LUOGU_RID: 158792599
#include<bits/stdc++.h>
#include<stdint.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<typename A,typename B>
// using htable=gp_hash_table<A,B>;
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define int long long
#define mod (1000000007)
// int mod;
#ifndef ONLINE_JUDGE
#pragma GCC optimize(2)
#endif
using namespace std;
namespace IO{
	inline int read(){
		int n=0;
		int s=1;
		char x;
		while((x=getchar())<'0'||x>'9')
			if(x=='-')
				s=-1;
		while(x>='0'&&x<='9'){
			n=(n<<1)+(n<<3)+(x^48),
			x=getchar();
		}
		return n*s;
	}
	void write(char x){
		if(x)putchar(x);
	}
	void write(const char *x){
		for(;*x;++x)
			putchar(*x);
	}
	void write(char *x){
		for(;*x;++x)
			putchar(*x);
	}
	void write(signed x){
		if(x<0)putchar('-'),x=-x;
		if(x>9)write(x/10);
		putchar('0'+x-x/10*10);
	}
	void write(long long x){
		if(x<0)putchar('-'),x=-x;
		if(x>9)write(x/10);
		putchar('0'+x-x/10*10);
	}
	// void write(__int128 x){
	// 	if(x<0)putchar('-'),x=-x;
	// 	if(x>9)write(x/10);
	// 	putchar('0'+x-x/10*10);
	// }
	void write(double x){
		printf("%lf",x);
	}
	template<typename type1,typename type2,typename ...typen>
	void write(type1 a1,type2 a2,typen ...an){
		write(a1);
		write(a2,an...);
	}
}// namespace IO
inline long long max(long long a,long long b){return a>b?a:b;}
inline long long min(long long a,long long b){return a>b?b:a;}
inline signed max(signed a,signed b){return a>b?a:b;}
inline signed min(signed a,signed b){return a>b?b:a;}
class Frac{
	private:
		int a,b;
	public:
		Frac(){a=0,b=1;}
		Frac(int x,int y){assert(y!=0);if(y>0)a=x,b=y;else a=-x,b=-y;}
		Frac(int x){a=x,b=1;}
		Frac(Frac x,Frac y){*this=x/y;}
		bool operator==(Frac x){return x.a*b==a*x.b;}
		bool operator<(Frac x){return a*x.b<x.a*b;}
		bool operator>(Frac x){return a*x.b>x.a*b;}
		bool operator<=(Frac x){return a*x.b<=x.a*b;}
		bool operator>=(Frac x){return a*x.b>=x.a*b;}
		Frac operator-(){return Frac(-a,b);}
		Frac& operator+=(Frac x){return *this=Frac(a*x.b+x.a*b,b*x.b);}
		Frac& operator-=(Frac x){return *this=Frac(a*x.b-x.a*b,b*x.b);}
		Frac& operator*=(Frac x){return *this=Frac(a*x.a,b*x.b);}
		Frac& operator/=(Frac x){return *this=Frac(a*x.b,b*x.a);}
		Frac operator+(Frac x){return Frac(a*x.b+x.a*b,b*x.b);}
		Frac operator-(Frac x){return Frac(a*x.b-x.a*b,b*x.b);}
		Frac operator*(Frac x){return Frac(a*x.a,b*x.b);}
		Frac operator/(Frac x){return Frac(a*x.b,b*x.a);}
		void yf(){
			int g=__gcd(a,b);
			a/=g,b/=g;
		}
};
int pw(int a,int b){
	a%=mod;
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
inline int lowbit(int i){return i&(-i);}
int bit(unsigned int x,unsigned int i){
	return (x&(1ull<<i))>>i;
}
int popc(int s){
	int ans=0;
	while(s){
		ans++;
		s^=lowbit(s);
	}
	return ans;
}
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
// stop
const int p=10000019;
int f[50][1001];
int n,q,k,cc;
int timl[30001],timr[30001];
int v[30001],w[30001];
void add(int *f,int v,int w){
	for(int i=k;i>=w;i--)f[i]=max(f[i],f[i-w]+v);
	for(int i=k;i>=1;i--)f[i]=max(f[i],f[i-1]);
}
struct Node{
	int l,r;
	vector<pair<int,int> >v;
	#define l(p) tree[p].l
	#define r(p) tree[p].r
	#define v(p) tree[p].v
	#define lson (p<<1)
	#define rson (p<<1|1)
}tree[120001];
void build(int p,int l,int r){
	l(p)=l,r(p)=r,v(p).clear();
	if(l==r)return;
	int mid=(l+r)>>1;
	build(lson,l,mid),build(rson,mid+1,r);
}
void change(int p,int l,int r,int v,int w){
	if(l<=l(p)&&r(p)<=r){
		v(p).pb(mp(v,w));
		return;
	}
	if(l<=r(lson))change(lson,l,r,v,w);
	if(r>=l(rson))change(rson,l,r,v,w);
}
void dfs(int p,int dep){
	memcpy(f[dep],f[dep-1],sizeof(f[dep]));
	for(auto o:v(p)){
		add(f[dep],o.first,o.second);
	}
	if(l(p)==r(p)){
		int ans=0,now=1;
		for(int i=1;i<=k;i++)ans=(ans+now*f[dep][i])%mod,now=now*::p%mod;
		IO::write(ans,'\n');
		return;
	}
	dfs(lson,dep+1),dfs(rson,dep+1);
}
// #define wtf
signed main(){
	using namespace IO;
	// define int long long
	// mod = input
	#ifdef wtf
	string filename="yiyan";
	freopen((filename+".in").c_str(),"r",stdin);
	freopen((filename+".out").c_str(),"w",stdout);
	#endif
	n=read(),k=read();
	for(int i=1;i<=n;i++)timl[i]=1,timr[i]=-1,v[i]=read(),w[i]=read();
	q=read();
	for(int i=1;i<=q;i++){
		int op=read();
		if(op==1){n++,v[n]=read(),w[n]=read(),timl[n]=cc+1,timr[n]=-1;}
		if(op==2){int x=read();timr[x]=cc;}
		if(op==3){cc++;}
	}
	build(1,1,cc);
	for(int i=1;i<=n;i++){
		if(timr[i]==-1)timr[i]=cc;
		// cout<<timl[i]<<" "<<timr[i]<<" "<<v[i]<<" "<<w[i]<<"\n";
		if(timr[i]>=timl[i])change(1,timl[i],timr[i],v[i],w[i]);
	}
	dfs(1,1);
	return 0;
}
/*
  ----  ----
   ----  ----
    ----  ----
    ----  ----
                       ----
               ----
         ----
    ----
                        ----
                 ----
          ----
   ----
                        ----
                 ----
            ----
      ----
                          ----
                ----
          ----
    ----
                          ----
                  ----
           ----
     ----

                     ----   ----

                     ----   ----

    ----   ----

    ----   ----

----------------------------------------
 ______                    __   _        
|  ____|                  / _| (_)       
| |__      __ _   _   _  | |_   _  __  __
|  __|    / _` | | | | | |  _| | | \ \/ /
| |____  | (_| | | |_| | | |   | |  >  < 
|______|  \__, |  \__,_| |_|   |_| /_/\_\
             | |                         
             |_|
*/
// 5 2 3 1 4