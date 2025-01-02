// LUOGU_RID: 159177632
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 2000000100
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll int
#define N 1000010
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
using namespace std;
char buf[1<<23],*p1=buf,*p2=buf;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
ll n,m1,m2,t,f[N],trs[N];
set<ll> hv[2];
vector<ll> pre[N];
map<pair<ll,ll>,ll> idx;
vector<pair<ll,ll> > pos;
void init()
{
	ll i;
	vector<ll> cur;
	cur.push_back(0);
	for(i=0;i<pos.size();i++)
	{
		ll x=pos[i].F,y=pos[i].S;
		if(!idx.count(make_pair(x-1,y)))
		{
			pre[i]=cur;
		}
		if(y==0)
		{
			if(idx.count(make_pair(x-1,y^1)))
			{
				cur.clear();
				cur.push_back(idx[make_pair(x-1,y^1)]);
				cur.push_back(i);
			}
		}
		else
		{
			if(idx.count(make_pair(x,y^1)))
			{
				cur.clear();
				cur.push_back(idx[make_pair(x,y^1)]);
				cur.push_back(i);
			}
			else if(idx.count(make_pair(x-1,y^1)))
			{
				cur.clear();
				cur.push_back(idx[make_pair(x-1,y^1)]);
				cur.push_back(i);
			}
		}
	}
	return;
}
vector<ll> chg;
vector<pair<ll,ll> > shot;
void print(ll i)
{
	if(!i)
	{
		return;
	}
	ll x=pos[i].F,y=pos[i].S,okl;
	if(x!=(*hv[y].begin()))
	{
		okl=(*prev(hv[y].lower_bound(x)))+1;
	}
	else
	{
		okl=0;
	}
	pair<ll,ll> lstp=pos[trs[i]];
	while(true)
	{
		set<ll>::iterator it=hv[lstp.S].lower_bound(lstp.F+1);
		ll nxt=(it==hv[lstp.S].end()?LINF:*it);
		if(lstp.S==y&&nxt==x)
		{
			break;
		}
		if(nxt>okl)
		{
			assert(lstp.S!=y);
			chg.push_back(okl);
			break;
		}
		chg.push_back(nxt-1);
		lstp=make_pair(nxt-1,lstp.S^1);
	}
	if(i<pos.size()-1)
	{
		shot.push_back(make_pair(f[i],y+1));
	}
	print(trs[i]);
	return;
}
int main(){
	ll i,j;
	n=rint(),m1=rint(),m2=rint(),t=rint();
	for(i=0;i<m1;i++)
	{
		ll x=rint();
		hv[0].insert(x);
		pos.push_back(make_pair(x,0));
	}
	for(i=0;i<m2;i++)
	{
		ll x=rint();
		hv[1].insert(x);
		pos.push_back(make_pair(x,1));
	}
	hv[0].insert(0);
	hv[0].insert(LINF);
	pos.push_back(make_pair(0,0));
	pos.push_back(make_pair(LINF,0));
	sort(pos.begin(),pos.end());
	for(i=0;i<pos.size();i++)
	{
		f[i]=LINF+114514;
		idx[pos[i]]=i;
	}
	init();
	f[0]=0;
	for(i=1;i<pos.size();i++)
	{
		ll x=pos[i].F,y=pos[i].S,okl;
		if(x!=(*hv[y].begin()))
		{
			okl=*prev(hv[y].lower_bound(x));
			ll lst=idx[make_pair(okl,y)];
			if(f[lst]<x-t)
			{
				if(f[i]>f[lst]+t)
				{
					f[i]=f[lst]+t;
					trs[i]=lst;
				}
			}
			okl++;
		}
		else
		{
			okl=0;
		}
		for(j=0;j<pre[i].size();j++)
		{
			if(max(f[pre[i][j]],okl-t)<x-t)
			{
				if(f[i]>max(f[pre[i][j]]+t,okl))
				{
					f[i]=max(f[pre[i][j]]+t,okl);
					trs[i]=pre[i][j];
				}
			}
		}
	}
	if(f[pos.size()-1]>=LINF)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	print(pos.size()-1);
	sort(chg.begin(),chg.end());
	printf("%d\n",chg.size());
	for(i=0;i<chg.size();i++)
	{
		printf("%d ",chg[i]);
	}
	puts("");
	sort(shot.begin(),shot.end());
	printf("%d\n",shot.size());
	for(i=0;i<shot.size();i++)
	{
		printf("%d %d\n",shot[i].F,shot[i].S);
	}
	return 0;
}