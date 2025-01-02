// LUOGU_RID: 160180341
#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const int N=2520;
int vis[N+1],a[25];
ll f[25][N+1][51];
void init()
{
	int num=0;
	for (int i=1;i<=N;i++)
	{
		if (N%i==0) {
			vis[i]=++num;
		}
	}
	memset(f,-1,sizeof(f));
}
int gcd(int x,int y) {return y?gcd(y,x%y):x;}
int lcmm(int x,int y) {return x*y/gcd(x,y);}
ll dp(int pos,int cur,int lcm,int ok)
{
	if (pos==0) return cur%lcm==0;
	if (!ok&&f[pos][cur][vis[lcm]]!=-1) return  f[pos][cur][vis[lcm]];
	ll ans=0;
	int mx=ok==1?a[pos]:9;
	for (int i=0;i<=mx;i++)
	{
		int ncur=(cur*10+i)%N;
		int nlcm=(i==0?lcm:lcmm(i,lcm));
		ans+=dp(pos-1,ncur,nlcm,ok&&i==mx);
	}
	if (!ok) f[pos][cur][vis[lcm]]=ans;
	return ans;
}
ll solve(ll x)
{
//	if (x==0) return 0;
 	int cnt=0;
	while(x)
	{
		a[++cnt]=x%10;
		x/=10;
	}
	return dp(cnt,0,1,1);
}
signed main()
{
	int t;cin>>t;
	init();
	while(t--)
	{
		ll l,r;scanf("%lld%lld",&l,&r);
		printf("%lld\n",solve(r)-solve(l-1));
	}
}