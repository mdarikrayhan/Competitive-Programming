#include<bits/stdc++.h>
using namespace std;using ll=long long;using ld=long double;using pii=pair<int,int>;
const int M=998244353;const ll inf=1e17;const double eps=1e-10;
struct MaxFlow{
	int n,m,S,T,tot=1;vector<int>to,cur,d;vector<ll>flow;vector<vector<int>>es;
	void ini(int _n,int _m){_m<<=1;_n++;n=_n,m=_m;to.resize(m),flow.resize(m);
	cur.resize(n);d.resize(n,0);es.resize(n);}//MaxFlow(int n,int m){ini(n,m);}
	void Addedge(int u,int v,ll w){to[++tot]=v;flow[tot]=w;es[u].push_back(tot); }
	void Add(int u,int v,ll w){Addedge(u,v,w);Addedge(v,u,0);}
	bool BFS(){d.clear();d.resize(n);d[S]=1;queue<int>q;q.push(S);while(!q.empty())
		{int x=q.front();q.pop();cur[x]=0;for(auto k:es[x]){int u=to[k];
			if(flow[k]&&!d[u])d[u]=d[x]+1,q.push(u);}}return d[T];}
	ll DFS(int x,ll nowf){if(x==T||!nowf)return nowf;ll res=nowf;
		for(int i=cur[x];i<(int(es[x].size()))&&res>0;i++)
			{cur[x]=i;int k=es[x][i],u=to[k];ll w=flow[k];if(!w||d[u]!=d[x]+1)continue;
	ll opt=DFS(u,min(res,w));res-=opt,flow[k]-=opt,flow[k^1]+=opt;}return nowf-res;}
	ll Solve(int _s,int _t){ll ans=0;S=_s;T=_t;while(BFS())ans+=DFS(S,inf);return ans;}};
struct S
{
	int n,m,S,T,bas=0;MaxFlow A;
	vector<vector<int>>mat;
	void ini()
	{
		cin>>n>>m;mat.resize(n+1,vector<int>(m+1,0));
		A.ini(n+m+5,(n+3)*(m+3));S=n+m+3,T=S+1;
		for(int i=0;i<n;i++)
		{
			string s;cin>>s;
			for(int j=0;j<m;j++)if(s[j]=='B')mat[i][j]=1;
		}
	}
	void solve()
	{
		int div_c=0;
		for(int i=0;i<n-1;i++)for(int j=0;j<m-1;j++)
			mat[i][j]^=mat[i][j+1]^mat[i+1][j]^mat[i+1][j+1],bas+=mat[i][j];
		//for(int i=0;i<n;i++,cout<<'\n')for(int j=0;j<m;j++)cout<<mat[i][j];
		for(int i=0;i<n-1;i++)div_c+=mat[i][m-1]^mat[i+1][m-1],A.Add(S,i,1);
		for(int j=0;j<m-1;j++)div_c+=mat[n-1][j]^mat[n-1][j+1],A.Add(n+j,T,1);
		for(int i=0;i<n-1;i++)for(int j=0;j<m-1;j++)
			if(mat[n-1][j]^mat[n-1][j+1]&&mat[i][m-1]^mat[i+1][m-1]&&mat[i][j])A.Add(i,n+j,1);
		int z1=A.Solve(S,T);bas+=div_c-z1+((z1^mat[n-1][m-1])&1);cout<<bas<<'\n';
	}
};
void precal() {}
int main()
{
	//freopen("1.in","r",stdin);
	//cout<<fixed<<setprecision(12);
	ios::sync_with_stdio(0);cin.tie(0);precal();
	int t=1;//cin>>t;
	//clock_t a=clock();
	while(t--){S SS;SS.ini();SS.solve();}
	//cout<<"Time:"<<double(clock()-a)<<'\n';
}