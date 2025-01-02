// LUOGU_RID: 160608961
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
#define ull unsigned long long
#define reg register
#define fo(a,b,c) for(reg ll a=b;a<=c;++a)
#define re(a,b,c) for(reg ll a=b;a>=c;--a)
#define pii pair<ll,ll>
#define pdd pair<db,db>
#define fi first
#define pb push_back
#define se second
#define ite set<pii> ::iterator
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
const ll inf=1e17+5,iinf=2e9;
const ll N=1000005;
ll bit[N],lim=2e5;
ll lb(ll x)
{
	return x&-x;
}
void add(ll x,ll y)
{
	for(;x<=lim;x+=lb(x)) bit[x]+=y;
}
ll qr(ll x)
{
	ll res=0;
	for(;x;x-=lb(x)) res+=bit[x];
	return res;
}
ll ck(ll x)
{
	if(x>lim) return -1;
	return qr(x)-qr(x-1);
}
set<pii> s;
vector<pii> jr,sc;
void mg(ll l,ll r)
{
	ite it=s.lower_bound({l,-1e9});
	if(it==s.end()||it->se>r)
	{
		jr.pb({l,r});
		s.insert({r,l});
		return;
	}
	ll zl=it->se,zr=it->fi;
	s.erase(it);
	sc.pb({zl,zr});
	ll dt=min(r,zr)-max(l,zl)+1;
	mg(min(l,zl),max(r,zr)+dt);
}
void split(ll x)
{
	ite it=s.lower_bound({x,-1e9});
	ll l=it->se,r=it->fi;
	ll rs=2;
	sc.pb({l,r});
	s.erase(it);
	while(rs)
	{
		if(ck(l)==-1) rs--,l++;
		else break;
	}
	while(rs)
	{
		if(ck(r)==-1) rs--,r--;
		else break;
	}
	if(rs==0)
	{
		if(l>=r) return;
		jr.pb({l,r});
		s.insert({r,l});
		return;
	}
	ll sl=qr(l-1),sr=qr(r),pos=0;
	fo(i,l,r)
	{
		if(qr(i)-sl==0&&sr-qr(i+rs)==0)
		{
			pos=i;
			break;
		}
	}
	jr.pb({l,pos});
	jr.pb({pos+rs+1,r});
	s.insert({pos,l});
	s.insert({r,pos+rs+1});
}
void wk()
{
	cout<<sc.size()<<'\n';
	for(pii p:sc)
	{
		cout<<p.fi<<" "<<p.se<<'\n';
	}
	cout<<jr.size()<<'\n';
	for(pii p:jr)
	{
		cout<<p.fi<<" "<<p.se<<'\n';
	}
	cout<<'\n';
}
void sol()
{
	ll n=gi();
	fo(i,1,lim) add(i,-1);
	fo(i,1,n)
	{
		ll x=gi();
		jr.clear();
		sc.clear();
		if(ck(x)==-1)
		{
			add(x,2);
			mg(x,x+1);
		}
		else
		{
			add(x,-2);
			split(x);
		}
		wk();
	}
}
int main()
{
//	_=gi();
	while(_--)
	{
		sol();
//		printf("\n");
	}
	return 0;
}