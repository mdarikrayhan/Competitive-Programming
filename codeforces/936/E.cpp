// LUOGU_RID: 155159028
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll int
#define N 300010
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
using namespace std;
char buf[1<<23],*p1=buf,*p2=buf;
ll rint(){
	ll ret=0,uu=1;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
ll n,q,cnt=0,fa[N],sz[N],mxsz[N],dep[N],dis[N][20],des[N][20];
vector<ll> bit1[N],bit2[N];
bool iscent[N];
map<pair<ll,ll>,ll> idx,pid;
pair<ll,pair<ll,ll> > rgs[N];
vector<ll> seq[N],vt[N],pth;
void dfssz(ll x,ll lst)
{
	ll i;
	pth.push_back(x);
	sz[x]=1,mxsz[x]=0;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst&&(!iscent[vt[x][i]]))
		{
			dfssz(vt[x][i],x);
			sz[x]+=sz[vt[x][i]];
			mxsz[x]=max(mxsz[x],sz[vt[x][i]]);
		}
	}
	return;
}
ll getcent(ll x)
{
	ll i;
	pth.clear();
	dfssz(x,-1);
	for(i=0;i<pth.size();i++)
	{
		if(max(mxsz[pth[i]],sz[x]-sz[pth[i]])*2<=sz[x])
		{
			return pth[i];
		}
	}
	return -1;
}
void dfs(ll x,ll lst,ll d)
{
	ll i;
	if(lst==-1)
	{
		ll id=idx[make_pair(rgs[x].F,rgs[x].S.F)];
		for(i=rgs[x].S.F;i<=rgs[x].S.S;i++,id++)
		{
			dis[id][d]=0;
			des[id][d]=i;
		}
	}
	else
	{
		ll nx=rgs[lst].F,id=idx[make_pair(rgs[x].F,rgs[x].S.F)];
		pair<ll,ll> vr=make_pair(rgs[lst].S.F,rgs[lst].S.S);
		ll lo=idx[make_pair(nx,vr.F)];
		for(i=rgs[x].S.F;i<=rgs[x].S.S;i++,id++)
		{
			ll ny=min(max(vr.F,i),vr.S);
			dis[id][d]=dis[lo+ny-vr.F][d]+1+abs(ny-i);
			des[id][d]=des[lo+ny-vr.F][d];
		}
	}
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst&&(!iscent[vt[x][i]]))
		{
			dfs(vt[x][i],x,d);
		}
	}
	return;
}
void build(ll x,ll lst,ll d=0)
{
	ll i;
	x=getcent(x);
	iscent[x]=true;
	dep[x]=d;
	fa[x]=lst;
	dfs(x,-1,d);
	for(i=rgs[x].S.F;i<=rgs[x].S.S+2;i++)
	{
		bit1[x].push_back(INF+INF);
		bit2[x].push_back(INF+INF);
	}
	for(i=0;i<vt[x].size();i++)
	{
		if(!iscent[vt[x][i]])
		{
			build(vt[x][i],x,d+1);
		}
	}
	return;
}
void update(ll x,ll y)
{
	ll id=idx[make_pair(x,y)],p=pid[make_pair(x,y)];
	while(p>=0)
	{
		ll y=des[id][dep[p]],w=dis[id][dep[p]],i;
		i=y-rgs[p].S.F+1;
		while(i<bit1[p].size())
		{
			bit1[p][i]=min(bit1[p][i],w-y);
			i+=i&(-i);
		}
		i=rgs[p].S.S-y+1;
		while(i<bit2[p].size())
		{
			bit2[p][i]=min(bit2[p][i],w+y);
			i+=i&(-i);
		}
		p=fa[p];
	}
	return;
}
ll query(ll x,ll y)
{
	ll id=idx[make_pair(x,y)],p=pid[make_pair(x,y)],ret=INF;
	while(p>=0)
	{
		ll y=des[id][dep[p]],w=dis[id][dep[p]],i;
		i=y-rgs[p].S.F+1;
		while(i)
		{
			ret=min(ret,bit1[p][i]+w+y);
			i-=i&(-i);
		}
		i=rgs[p].S.S-y+1;
		while(i)
		{
			ret=min(ret,bit2[p][i]+w-y);
			i-=i&(-i);
		}
		p=fa[p];
	}
	return ret;
}
int main(){
	ll i,j,x,y;
	n=rint();
	for(i=0;i<n;i++)
	{
		x=rint()-1,y=rint()-1;
		seq[x].push_back(y);
	}
	ll m=0;
	for(i=0;i<N;i++)
	{
		if(seq[i].empty())
		{
			continue;
		}
		sort(seq[i].begin(),seq[i].end());
		ll lst=0;
		for(j=0;j<seq[i].size();j++)
		{
			idx[make_pair(i,seq[i][j])]=m++;
			if(j==seq[i].size()-1||seq[i][j]+1<seq[i][j+1])
			{
				for(x=lst;x<=j;x++)
				{
					pid[make_pair(i,seq[i][x])]=cnt;
				}
				rgs[cnt++]=make_pair(i,make_pair(seq[i][lst],seq[i][j]));
				lst=j+1;
				continue;
			}
		}
	}
	for(i=j=0;i<cnt;i++)
	{
		while(rgs[j].F<rgs[i].F-1)
		{
			j++;
		}
		if(rgs[j].F==rgs[i].F-1)
		{
			while(rgs[j].F<rgs[i].F&&rgs[j].S.S<rgs[i].S.F)
			{
				j++;
			}
			if(rgs[j].S.F<=rgs[i].S.S)
			{
				while(rgs[j].F<rgs[i].F&&rgs[j].S.F<=rgs[i].S.S)
				{
					vt[i].push_back(j);
					vt[j].push_back(i);
					j++;
				}
				j--;
			}
		}
	}
	build(0,-1);
	q=rint();
	while(q--)
	{
		i=rint(),x=rint()-1,y=rint()-1;
		if(i==1)
		{
			update(x,y);
		}
		else
		{
			ll ret=query(x,y);
			printf("%d\n",ret==INF?-1:ret);
		}
	}
	return 0;
}