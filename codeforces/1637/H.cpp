// LUOGU_RID: 157181759
#include<bits/stdc++.h>
#define ll long long
#define rg int
#define ci const int
#define ls x<<1
#define rs x<<1|1
#define mid ((l+r)>>1)
#define ld long double
#define fo(i,l,r) for(int i=(l);i<=(r);++i)
#define fd(i,l,r) for(int i=(l);i>=(r);--i)
#define fu(i,l,r) for(int i=(l);i<(r);++i)
#define gcd __gcd
#define P(x) __builtin_popcountll(x)
using namespace std;
ci N=2e6+5,M=5e3+5,mod=998244353,_g=3,_ig=(mod+1)/3;
ll ksm(ll a,ll b=mod-2)
{
	ll ans=1;
	while(b)
	{
		if(b&1)ans=(ll)ans*a%mod;
		a=(ll)a*a%mod,b>>=1;
	}
	return ans;
}
const ld eps=1e-10;
inline ll read(){ll u,f=1;char o;while((o=getchar())<48||o>57)if(o==45)f=-1;u=(o^48);while((o=getchar())>=48&&o<=57)u=(u<<1)+(u<<3)+(o^48);return u*f;}
void write(ll x){if(x<0)putchar(45),x=-x;if(x>9)write(x/10);putchar(x%10+48);}
mt19937_64 rad(chrono::steady_clock::now().time_since_epoch().count());
ll n,a[N],d[N];
ll tree[N];
int lowbit(int x){return x&-x;}
void add(int x)
{
	for(rg i=x;i;i-=lowbit(i))tree[i]++;
}
ll cha(int x)
{
	ll q=0;
	for(rg i=x;i<=n;i+=lowbit(i))q+=tree[i];
	return q;
}
int main()
{//freopen("1.in","r",stdin);
	int T=read();
	while(T--)
	{
		n=read();
		fo(i,1,n)tree[i]=0;
		ll ans=0;
		fo(i,1,n)
		{
			a[i]=read();
			ll u=cha(a[i]);
			ans+=u;
			d[i]=i-1-2*u;
			add(a[i]);
		}
		fo(i,1,n)tree[i]=0;
		fd(i,n,1)
		{
			ll u=cha(a[i]);
			d[i]+=2*(n-i-u);
			add(a[i]);
		}
		sort(d+1,d+n+1);
		cout<<ans<<' ';
		fo(i,1,n)
		{
			ans+=d[i];
			cout<<ans-((ll)i*(i-1))/2<<' ';
		}cout<<'\n';
	}
	return 0;
}