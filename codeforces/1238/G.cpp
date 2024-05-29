// LUOGU_RID: 159250130
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <cstring>
#include <array>
#include <algorithm>
#include <queue>
#include <vector>
#include <bitset>
#include <ctime>
#include <cstdlib>
#include <random>
#include <set>
#include <ctime>
#include <map>
#include <stack>
#include <unordered_map>
#include <assert.h>
#define ll long long
#define db double
#define ull unsigned long long
#define reg register
#define fo(a,b,c) for(reg ll a=b;a<=c;++a)
#define re(a,b,c) for(reg ll a=b;a>=c;--a)
#define pii pair<ll,ll>
#define pdd pair<db,db>
#define fi first
#define pb push_back
#define se second
#define ite multiset<ll> ::iterator
using namespace std;
const ll mod=998244353;
inline ll gi()
{
	ll x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x<<1) + (x<<3) + (ch^48);
		ch = getchar();
	}
	return x * f;
}
ll _=1;
const ll inf=1e17+5;
const ll N=500005;
set<ll> s;
map<ll,ll> mp;
struct IO
{
	ll t,a,b;
}px[N];
bool cmp(IO za,IO zb)
{
	return za.t<zb.t;
}
void sol()
{
	s.clear();
	mp.clear();
	ll n=gi(),m=gi(),c=gi(),c0=gi();
	fo(i,1,n)
	{
		px[i]={gi(),gi(),gi()};
	}
	sort(px+1,px+1+n,cmp);
	mp[0]=c0;
	s.insert(0);
	ll las=0,ans=0,num=c0;
	px[n+1].t=m;
	fo(i,1,n+1)
	{
//		cout<<"TEST "<<i<<'\n';
		ll dt=px[i].t-las;
		while(!s.empty())
		{
			ll x=*s.begin();
			if(mp[x]>=dt)
			{
				mp[x]-=dt;
				num-=dt;
				ans+=x*dt;
				if(mp[x]==0) s.erase(x);
				dt=0;
				break;
			}
			else
			{
				s.erase(x);
				ans+=x*mp[x];
				dt-=mp[x];
				num-=mp[x];
				mp[x]=0;
			}
		}
		if(dt)
		{
			cout<<-1;
			return;
		}
		if(i==n+1) break;
		s.insert(px[i].b);
		mp[px[i].b]+=px[i].a;
		num+=px[i].a;
		while(num>c)
		{
			ll cj=num-c;
			ll x=*(--s.end());
			if(mp[x]>=cj)
			{
				mp[x]-=cj;
				num-=cj;
				if(mp[x]==0) s.erase(x);
			}
			else
			{
				num-=mp[x];
				s.erase(x);
				mp[x]=0;
			}
		}
		las=px[i].t;
	}
	cout<<ans;
}
int main()
{
	_=gi();
	while(_--)
	{
		sol();
		printf("\n");
	}
	return 0;
}