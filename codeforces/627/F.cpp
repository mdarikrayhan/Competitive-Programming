#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define pb push_back
#define mid ((l+r)>>1)

using namespace std;
typedef long long LL;
typedef long double ld;
typedef pair <int,int> pii;

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

const int N=200005;
int n,fa[N],dep[N],cnt[N],a[N],b[N];
vector <int> vt[N];

void dfs(int x,int f)
{
	fa[x]=f,dep[x]=dep[f]+1;
	for(auto v:vt[x]) if(v!=f) dfs(v,x);
}

int dis(int x,int y)
{
	int ret=0;
	while(x!=y)
	{
		if(dep[x]<dep[y]) swap(x,y);
		++ret,x=fa[x];
	}
	return ret;
}

vector <int> get(int l,int r)
{
	vector <int> ret;
	while(r!=fa[l]) ret.pb(r),r=fa[r];
	return ret;
}

void solve()
{
	n=getint();
	int s,t;
	rep(i,1,n) if(!(a[i]=getint())) s=i;
	rep(i,1,n) if(!(b[i]=getint())) t=i;
	rep(i,1,n-1)
	{
		int u=getint(),v=getint();
		vt[u].pb(v),vt[v].pb(u);
	}
	dfs(s,0);
	for(int x=t; fa[x]; swap(b[x],b[fa[x]]),x=fa[x]);
	int l1=0,r1=0;
	int l2=0,r2=0;
	rep(i,1,n) if(a[i]!=b[i])
	{
		if(!r1 || dep[r1]<dep[i]) r1=i;
	}
	if(!r1)
	{
		printf("0 %d\n",dep[t]-1);
		return ;
	}
	for(l1=r1; fa[l1] && a[fa[l1]]!=b[fa[l1]]; l1=fa[l1]);
	for(int x=r1; x!=fa[l1]; ++cnt[x],x=fa[x]);
	rep(i,1,n) if(!cnt[i] && a[i]!=b[i])
	{
		if(!r2 || dep[r2]<dep[i]) r2=i;
	}
	int X,Y;
	vector <int> p;
	if(r2)
	{
		for(l2=r2; fa[l2] && a[fa[l2]]!=b[fa[l2]]; l2=fa[l2]);
		for(int x=r2; x!=fa[l2]; ++cnt[x],x=fa[x]);
		rep(i,1,n) if(cnt[i]>1)
			return puts("-1"),void();
		if(fa[l1]!=fa[l2])
			return puts("-1"),void();
		rep(i,1,n) if(!cnt[i] && a[i]!=b[i])
			return puts("-1"),void();
		vector <int> L=get(l1,r1),R=get(l2,r2);
		reverse(R.begin(),R.end());
		for(auto x:L) p.pb(x);
		for(auto x:R) p.pb(x);
		X=r1,Y=r2;
	}
	else
	{
		p=get(l1,r1);
		reverse(p.begin(),p.end());
		X=fa[l1],Y=r1;
	}

	int m=p.size(),cir=-1;
	rep(i,0,m-1) if(a[p[0]]==b[p[i]]) cir=i;
	rep(i,0,m-1) if(a[p[i]]!=b[p[(i+cir)%m]])
		return puts("-1"),void();
	LL ans1=0,ans2=0;
	ans1 = dis(s,fa[l1]) 
		 + (m+1-dis(fa[l1],Y))
		 + 1ll*(cir-1)*(m+1)
		 + dis(Y,t);

	cir=m-cir;

	ans2 = dis(s,fa[l1])
		 + (m+1-dis(fa[l1],X))
		 + 1ll*(cir-1)*(m+1)
		 + dis(X,t);

	LL ans=min(ans1,ans2);
	if(X>Y) swap(X,Y);
	printf("%d %d %lld\n",X,Y,ans);
}

int main()
{
	int T=1;
	while(T--) solve();
	return 0;
}