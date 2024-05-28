// LUOGU_RID: 160011453
#include<bits/stdc++.h>
#define ll long long
#define int ll
#define L x<<1
#define R L|1
#define mid (l+r>>1)
#define lc L,l,mid
#define rc R,mid+1,r
#define OK Ll<=l&&r<=Rr
#define Root 1,1,n
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define repn(x) rep(x,1,n)
#define repm(x) rep(x,1,m)
#define pb push_back
#define e(x) for(int i=h[x],y=to[i];i;i=nxt[i],y=to[i])
#define E(x) for(auto y:p[x])
#define Pi pair<int,int>
#define ui unsigned ll
#define double long double
inline int read(){int s=0,w=1;char c=getchar();while(c<48||c>57) {if(c=='-') w=-1;c=getchar();}while(c>=48&&c<=57)s=(s<<1)+(s<<3)+c-48,c=getchar();return s*w;}
inline void pf(ll x){if(x<0) putchar('-'),x=-x;if(x>9)pf(x/10);putchar(x%10+48);}
using namespace std;
const int N =4e5+5,M=1.1e6+5,inf=(1LL<<30)-1,mod=998244353;
const ll llf=1e18;
inline void add(int &a,int b){((a+=b)>=mod) and (a-=mod);}
inline int Add(int a,int b){return add(a,b),a;}
inline int mul(int a,int b){return 1LL*a*b%mod;}
inline void Mul(int &a,int b){a=mul(a,b);}
inline void red(int &a,int b){add(a,mod-b);}
inline int Red(int a,int b){return red(a,b),a;}
inline int qp(int a,int b){if(!b)return 1;int c=qp(a,b>>1);Mul(c,c);if(b&1)Mul(c,a);return c;}
inline int INV(int x){return qp(x,mod-2);}
int n,k;
double p[25],dp[M];
inline int get(int x){
	int ans=0;
	while(x)ans++,x-=x&-x;
	return ans;
}
double as[N];
inline void Main(){
	n=read(),k=read();
	repn(i)cin>>p[i];
	if(k==1)repn(i)printf("%.6Lf ",p[i]);
	if(k==1)return;
	if(k==n){
		repn(i)if(p[i]>0)printf("%.6Lf ",(double)1.000000);
		else cout <<"0 ";
		return;
	}
	int S=(1<<n)-1;
	dp[0]=1.;
	int c=0;
	repn(i)c+=p[i]>0;
	if(c<=k){
		repn(i)if(p[i]>0)printf("%.6Lf ",(double)1.000000);
		else cout <<"0 ";
		return;
	}
	rep(s,0,S){
		int c=get(s);
		if(c>k)continue;
		if(c==k){
			repn(i)if((s>>i-1)&1)as[i]+=dp[s];
			continue;
		}
		double sp=0;
		repn(i)if((s>>i-1)&1)sp+=p[i];
		if(sp>=1){
			repn(i)if((s>>i-1)&1)as[i]+=dp[s];
			continue;
		}
		repn(i)if(!((s>>i-1)&1)){
			dp[s|(1<<i-1)]+=dp[s]*p[i]/((double)1.00-sp);
		}
	}
	repn(i)printf("%.7Lf ",as[i]);
}
signed main(){
	int T=1;
	while(T--)Main();
	return 0;
}