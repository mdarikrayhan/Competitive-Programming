// Author: Little09
// Problem: Starry Night Camping
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1517G
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// Start Time: 2024-05-29 10:11:34
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define i128 __int128
#define mem(x) memset(x,0,sizeof(x))
#define endl "\n"
#define printYes cout << "Yes\n"
#define printYES cout << "YES\n"
#define printNo cout << "No\n"
#define printNO cout << "NO\n"
#define lowbit(x) ((x)&(-(x)))
#define pb push_back
#define mkp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define rep(i,j,k) for (int i=(j);i<=(k);i++)
#define per(i,j,k) for (int i=(j);i>=(k);i--)
#define pcnt(x) __builtin_popcount(x)
mt19937 rnd(time(0));
template<class T>void chkmin(T&x,T y){x=min(x,y);}
template<class T>void chkmax(T&x,T y){x=max(x,y);}

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=1000005;
int n,m; 
namespace DINIC
{
	int n,S,T;
	const int N=2e5+5,M=5e5+5;
	int h[N],nxt[M*2],t[M*2],cnt=1;
	ll w[M*2];
	inline void add(int x,int y,ll z)
	{
		t[++cnt]=y;
		w[cnt]=z,nxt[cnt]=h[x];
		h[x]=cnt;
	}
	inline void addedge(int x,int y,ll z)
	{
		add(x,y,z),add(y,x,0);
	}
	
	int deth[N],cur[N];
	queue<int>q;
	bool bfs()
	{
		for (int i=1;i<=n;i++) deth[i]=0,cur[i]=h[i];
		deth[S]=1;
		q.push(S);
		while (!q.empty())
		{
			int u=q.front();
			q.pop();
			for (int i=h[u];i;i=nxt[i])
			{
				if (w[i]&&deth[t[i]]==0)
				{
					deth[t[i]]=deth[u]+1;
					q.push(t[i]);
				}
			}
		}
		return (deth[T]!=0);
	}
	
	ll dfs(int u,ll dist)
	{
		if (u==T) return dist;
		for (int i=cur[u];i;i=nxt[i])
		{
			cur[u]=i;
			if (deth[t[i]]==deth[u]+1&&w[i])
			{
				ll v=dfs(t[i],min(dist,w[i]));
				if (v==0) continue;
				w[i]-=v,w[i^1]+=v;
				return v;
			}
		}
		deth[u]=0;
		return 0;
	}
	
	ll dinic()
	{
		ll res=0;
		while (bfs()) 
		{
			while (ll ans=dfs(S,inf)) res+=ans;
		}
		return res;
	}	
	void init(int _n,int _S,int _T)
	{
		n=_n,S=_S,T=_T;
		rep(i,1,n) h[i]=0;
		cnt=1;
	}
}
int a[N],b[N],c[N],tp[N];
int gettp(int x)
{
	if (a[x]%2&&b[x]%2) return 1;
	if (b[x]%2) return 2;
	if (a[x]%2) return 4;
	return 3;
}
inline int dis(int x,int y)
{
	return abs(a[x]-a[y])+abs(b[x]-b[y]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	int S=2*n+1,T=2*n+2;
	DINIC::init(T,S,T);
	rep(i,1,n) cin >> a[i] >> b[i] >> c[i];
	ll sum=0;
	rep(i,1,n) sum+=c[i];
	rep(i,1,n) tp[i]=gettp(i);
	rep(i,1,n) DINIC::addedge(i,i+n,c[i]);
	rep(i,1,n) if (tp[i]==1) DINIC::addedge(S,i,inf);
	rep(i,1,n) rep(j,1,n) if (tp[j]==tp[i]+1&&dis(i,j)==1)
	{
		DINIC::addedge(i+n,j,inf);
	}
	rep(i,1,n) if (tp[i]==4) DINIC::addedge(i+n,T,inf);
	cout << sum-DINIC::dinic();
	return 0;
}
