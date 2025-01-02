#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,x,y,u,v;
void exgcd(ll a,ll b,ll &x,ll &y) { if (!b) x=1,y=0; else exgcd(b,a%b,y,x),y-=a/b*x; }
int main() {
	scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&u,&v);
	if (u==0) return x==0 || x==n ? printf("%d %d\n",x,(v>0)*m):puts("-1"),0;
	if (v==0) return y==0||y==m ? printf("%d %d\n",(u>0)*n,y):puts("-1"),0;
	if (u<0) u=1,x=n-x; else u=0;
	if (v<0) v=1,y=m-y; else v=0;
	if ((x-y)%__gcd(n,m)) return puts("-1"),0;
	ll A,B,g=__gcd(n,m),mod=m/g;
	exgcd(n,-m,A,B),A*=(x-y)/g,B*=(x-y)/g;
	if (x-y!=A*n-B*m) A=-A,B=-B;
	ll AA=((A+mod-1)%mod+mod)%mod+1,BB=(AA*n-x+y)/m;
	u^=AA&1,v^=BB&1;
	return printf("%d %d\n",u?n:0,v?m:0),0;
}