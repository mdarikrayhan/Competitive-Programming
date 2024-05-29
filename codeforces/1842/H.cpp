// LUOGU_RID: 160541236
#include<bits/stdc++.h>
#define ll long long
#define ci const int
#define ld long double
#define fo(i,l,r) for(int i=(l);i<=(r);++i)
#define fd(i,l,r) for(int i=(l);i>=(r);--i)
#define fu(i,l,r) for(int i=(l);i<(r);++i)
#define gcd __gcd
#define P(x) __builtin_popcountll(x)
using namespace std;
ci N=2e6+5,M=2e2+5,mod=998244353;
const ll inf=1e18;
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
inline ll read(){ll u,f=1;char o;while((o=getchar())<48||o>57)if(o==45)f=-1;u=(o^48);while((o=getchar())>=48&&o<=57)u=(u<<1)+(u<<3)+(o^48);return u*f;}
void write(ll x){if(x<0)putchar(45),x=-x;if(x>9)write(x/10);putchar(x%10+48);}
mt19937 rad(chrono::steady_clock::now().time_since_epoch().count());
ll n,f[N];
bool t[2][M][M];
void _(ll &a,ll b){a=(a+b)%mod;}
int main()
{//freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	int TT=1;
	while(TT--)
	{
		n=read();ll m=read();
		fo(i,1,m)
		{
			ll tp=read(),x=read(),y=read();
			t[tp][x][y]=t[tp][y][x]=1;
		}
		int S=(1<<n);
		f[0]=1;
		fu(i,1,S)
		{
			fo(j,1,n)if(i&(1<<(j-1)))
			{
				int F=0;
				fo(k,1,n)if(i&(1<<(k-1)))
				{
					if(t[0][k][j])
					{
						if(F==2)
						{
							F=-1;
							break;
						}
						F=1;
					}
					if(t[1][k][j])
					{
						if(F==1)
						{
							F=-1;
							break;
						}
						F=2;
					}
				}
				if(F==0)_(f[i],f[i^(1<<(j-1))]*2);
				if(F>0)_(f[i],f[i^(1<<(j-1))]);
			}
//			cout<<i<<' '<<f[i]<<'\n';
		}
		ll ans=1;
		fo(i,1,n)ans=ans*i%mod;
		cout<<f[S-1]*ksm(ans*ksm(2,n)%mod)%mod<<'\n';
	}
	return 0;
}