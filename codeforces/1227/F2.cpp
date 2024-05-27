// LUOGU_RID: 160428687
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
#include<queue>
#define int long long
#define ll long long
#define ls (x<<1)
#define rs ((x<<1)|1)
#define mid ((l+r)>>1)
#define pc(x) putchar(x)
#define inf ((ll)(1e18+7))
#define lowbit(x) (x&(-x))
#define travel(x) for(int i=head[x];i;i=e[i].nxt)if(e[i].v!=faa)
#define clr(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define pri pair<int,int>
#define fi first
#define se second

using namespace std;

inline ll read()
{
	ll w,f=1;char c;
	while((c=getchar())>'9'||c<'0')
		if(c=='-')f=-1;
	w=c-'0';
	while((c=getchar())>='0'&&c<='9')
		w=w*10+c-'0';
	return w*f;
}

int printt[50],never_use;

inline void print(ll x)
{
	if(x==0)
		pc(48);
	if(x<0)
		pc('-'),x=-x;
	while(x)
		printt[++never_use]=x%10,x/=10;
	while(never_use)
		pc(printt[never_use--]+48);
}

const int N=2e5+5,mod=998244353;

int p2[N];
int J[N],inv[N];
int qp(int x,int y){
	int ans=1;
	for(int i=1;i<=y;i<<=1){
		if(i&y)
			ans=ans*x%mod;
		x=x*x%mod;
	}return ans;
}
int C(int n,int m){
	return J[n]*inv[n-m]%mod*inv[m]%mod;
}

int h[N];

int calc(int n){
	if(n&1)
		return p2[n-1];
	else
		return (p2[n-1]+mod-C(n,n/2)*inv[2]%mod)%mod;
}

signed main()
{
	int n=read(),k=read();
	for(int i=1;i<=n;i++)
		h[i]=read();
	int num=0;
	for(int i=1;i<=n;i++)
		if(h[i]==h[i%n+1])
			num++;
	n-=num;
	J[0]=1,inv[0]=1,p2[0]=1;
	for(int i=1;i<=n;i++)
		J[i]=J[i-1]*i%mod,p2[i]=p2[i-1]*2%mod;
	inv[n]=qp(J[n],mod-2);
	for(int i=n-1;i>=1;i--)
		inv[i]=inv[i+1]*(i+1)%mod;
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=(ans+C(n,i)*calc(i)%mod*qp(k-2,n-i)%mod*qp(k,num))%mod;
	print(ans),pc('\n');
	return 0;
}

