// LUOGU_RID: 159417167
#include<bits/stdc++.h>
#define x first
#define y second
#define int long long 
#define pb push_back
using namespace std;
typedef pair<int,int>PII;
const int N=2e5+5,M=1e6+5,P=1e9+7,K=13331;
int n,m,q,f[N],cnt,res,fir[N],se[N],dep[N];
PII mx;
vector<int>v[N];
void dfs(int u,int fa,int d)
{
	dep[u]=d;
	int son=0;
	for(int x:v[u])
	if(x!=fa)
	{
		son++;
		dfs(x,u,d+1);
		if(dep[fir[x]]>dep[fir[u]])
		se[u]=fir[u],fir[u]=fir[x];
		else if(dep[fir[x]]>dep[se[u]])se[u]=fir[x];
	}
	if(!son)fir[u]=u;
	if(son>=2)
	{
		PII tmp={dep[u],dep[fir[u]]+dep[se[u]]};
		if(tmp>mx)
		{
			mx=tmp;
			res=u;
		}
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		v[a].pb(b),v[b].pb(a);
	}
	dfs(1,0,1);
	int ans1=fir[res],ans2=se[res];
	mx={0ll,0ll};
	memset(fir,0,sizeof(fir));
	memset(se,0,sizeof(se));
	dfs(res,0,1);
	int ans3=fir[res],ans4=se[res];
	cout<<ans1<<" "<<ans3<<'\n';
	cout<<ans2<<" "<<ans4<<'\n';
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	// int T;cin>>T;
	// while(T--)
	solve();
	return 0;
}