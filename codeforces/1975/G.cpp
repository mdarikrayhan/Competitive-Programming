//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll int
#define N ((1<<22)+10)
using namespace std;
mt19937_64 rnd(std::chrono::system_clock::now().time_since_epoch().count());
ll ksm(ll x,ll y)
{
	ll ret=1;
	while(y>0)
	{
		if(y&1)
		{
			ret=(1ll*ret*x)%mod;
		}
		x=(1ll*x*x)%mod;
		y>>=1;
	}
	return ret;
}
ll pinv[N];
struct Ntt{
	ll n,m,rev[N],resnum,lim,mxbit;
	void NTT(ll* a,ll flag)
	{
		ll i,j,k,l;
		for(i=0;i<lim;i++)
		{
			if(rev[i]<i)
			{
				swap(a[i],a[rev[i]]);
			}
		}
		for(l=2;l<=lim;l<<=1)
		{
			i=l>>1;
			ll gn=pinv[l];
			for(j=0;j<lim;j+=l)
			{
				ll g=1;
				for(k=0;k<i;++k)
				{
					ll x=(1ll*a[i+j+k]*g)%mod;
					a[i+j+k]=(a[j+k]+mod-x)%mod;
					a[j+k]=(a[j+k]+x)%mod;
					g=(1ll*g*gn)%mod;
				}
			}
		}
		if(flag==-1)
		{
			reverse(a+1,a+lim);
			ll inv=ksm(lim,mod-2);
			for(i=0;i<lim;i++)
			{
				a[i]=(1ll*a[i]*inv)%mod;
			}
		}
		return;
	}
	ll a1[N],a2[N];
	vector<ll> do_ntt(vector<ll> v1,vector<ll> v2)
	{
		ll i;
		vector<ll> ret;
		n=v1.size(),m=v2.size();
		resnum=n+m-1;
		for(lim=1,mxbit=0;lim<n+m;lim<<=1,mxbit++);
		--mxbit;
		for(i=0;i<lim;++i)
		{
			a1[i]=a2[i]=0;
		}
		for(i=0;i<n;++i)
		{
			a1[i]=v1[i];
		}
		for(i=0;i<m;++i)
		{
			a2[i]=v2[i];
		}
		rev[0]=0;
		for(i=1;i<lim;++i)
		{
			rev[i]=(rev[i>>1]>>1)|((i&1)<<mxbit);
		}
		NTT(a1,1);
		NTT(a2,1);
		for(i=0;i<lim;++i)
		{
			a1[i]=(1ll*a1[i]*a2[i])%mod;
		}
		NTT(a1,-1);
		for(i=0;i<resnum;++i)
		{
			ret.push_back(a1[i]);
		}
		return ret;
	}
}ntt;
ll n,m,rk[N];
string s,t;
ll getplc(ll l1,ll r1,ll l2,ll r2)
{
	if(l1>r1||l2>r2)
	{
		return -1;
	}
	ll i;
	vector<ll> v1,v2;
	v1.resize(r1-l1+1);
	v2.resize(r2-l2+1);
	for(i=l1;i<=r1;i++)
	{
		ll v=(s[i]=='-'?0:rk[s[i]-'a']);
		v1[i-l1]=(1ll*v*((1ll*v*v)%mod))%mod;
	}
	for(i=l2;i<=r2;i++)
	{
		v2[r2-i]=(t[i]=='-'?0:rk[t[i]-'a']);
	}
	vector<ll> res1=ntt.do_ntt(v1,v2);
	for(i=l1;i<=r1;i++)
	{
		ll v=(s[i]=='-'?0:rk[s[i]-'a']);
		v1[i-l1]=(1ll*v*v)%mod;
	}
	for(i=l2;i<=r2;i++)
	{
		ll v=(t[i]=='-'?0:rk[t[i]-'a']);
		v2[r2-i]=(1ll*v*v)%mod;
	}
	vector<ll> res2=ntt.do_ntt(v1,v2);
	for(i=l1;i<=r1;i++)
	{
		v1[i-l1]=(s[i]=='-'?0:rk[s[i]-'a']);
	}
	for(i=l2;i<=r2;i++)
	{
		ll v=(t[i]=='-'?0:rk[t[i]-'a']);
		v2[r2-i]=(1ll*v*((1ll*v*v)%mod))%mod;
	}
	vector<ll> res3=ntt.do_ntt(v1,v2);
	for(i=l1;i+r2-l2<=r1;i++)
	{
		if((1ll*res1[i-l1+r2-l2]+1ll*res3[i-l1+r2-l2]+1ll*mod+1ll*mod-2ll*res2[i-l1+r2-l2])%mod==0)
		{
			return i;
		}
	}
	return -1;
}
void solve()
{
	ll i,j,lst=0;
	for(i=0;i<t.size();i=j)
	{
		if(t[i]=='*')
		{
			j=i+1;
			continue;
		}
		for(j=i;j<t.size()&&t[j]!='*';j++);
		ll l=i,r=j-1;
		while(true)
		{
			ll nw=getplc(lst,min((ll)s.size()-1,lst+(r-l+1)*2),l,r);
			if(nw!=-1)
			{
				lst=nw+r-l+1;
				break;
			}
			lst+=r-l+1;
			if(lst>=(ll)s.size())
			{
				puts("No");
				return;
			}
		}
	}
	puts("Yes");
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	ll i,j;
	for(i=1;i<N;i<<=1)
	{
		pinv[i]=ksm(3,(mod-1)/i);
	}
	for(i=0;i<26;i++)
	{
		rk[i]=rnd()%mod;
	}
	cin>>n>>m>>s>>t;
	for(i=0;i<n&&i<m;i++)
	{
		if(s[i]=='*'||t[i]=='*')
		{
			break;
		}
		if(s[i]==t[i]||s[i]=='-'||t[i]=='-')
		{
			continue;
		}
		puts("No");
		return 0;
	}
	if(i>=n&&i>=m)
	{
		puts("Yes");
		return 0;
	}
	for(j=0;j<n&&j<m;j++)
	{
		if(s[n-j-1]=='*'||t[m-j-1]=='*')
		{
			break;
		}
		if(s[n-j-1]==t[m-j-1]||s[n-j-1]=='-'||t[m-j-1]=='-')
		{
			continue;
		}
		puts("No");
		return 0;
	}
	if(j>=n&&j>=m)
	{
		puts("Yes");
		return 0;
	}
	ll sl=i,sr=n-j-1,tl=i,tr=m-j-1;
	if(sl>sr&&tl>tr)
	{
		puts("Yes");
		return 0;
	}
	if(sl>sr)
	{
		for(i=tl;i<=tr;i++)
		{
			if(t[i]!='*')
			{
				puts("No");
				return 0;
			}
		}
		puts("Yes");
		return 0;
	}
	if(tl>tr)
	{
		for(i=sl;i<=sr;i++)
		{
			if(s[i]!='*')
			{
				puts("No");
				return 0;
			}
		}
		puts("Yes");
		return 0;
	}
	bool oks=false,okt=false;
	for(i=sl;i<=sr;i++)
	{
		if(s[i]=='*')
		{
			oks=true;
			break;
		}
	}
	for(i=tl;i<=tr;i++)
	{
		if(t[i]=='*')
		{
			okt=true;
			break;
		}
	}
	if(oks&&okt)
	{
		puts("Yes");
		return 0;
	}
	s=s.substr(sl,sr-sl+1);
	t=t.substr(tl,tr-tl+1);
	if(!okt)
	{
		swap(s,t);
	}
	solve();
	return 0;
}