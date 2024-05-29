#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define ll long long
using namespace std;
#define pb push_back
typedef vector<int>vi;
#define maxn 500005
int n,m,a[maxn],vis[maxn],fa[maxn],ce;
vi e[maxn],o;
void dfs(int u){
	o.pb(u),vis[u]=1,ce+=e[u].size();
	for(int v:e[u])if(!vis[v])dfs(v);
}
void yes(){
	puts("YES");
	For(i,1,n)cout<<a[i]<<" \n"[i==n]; 
}
void dfs(int u,int pa){
	if(o.size()>9)return;
	o.pb(u),fa[u]=pa;
	for(int v:e[u])if(v!=pa)dfs(v,u);
}
void work()
{
	cin>>n>>m; 
	For(i,1,n)e[i].clear(),a[i]=vis[i]=0;
	For(i,1,m){
		int u,v;cin>>u>>v;
		e[u].pb(v),e[v].pb(u);
	}
	For(i,1,n){
		if(vis[i])continue;
		o.clear(),ce=0,dfs(i),ce/=2;
		vi oo=o;
		if(ce>=o.size()){
			for(int u:o)a[u]=1;
			return yes();
		}
		int c1=0;
		for(int u:o)c1+=(e[u].size()==1);
		if(c1>=4){
			for(int u:o)a[u]=(e[u].size()==1?1:2);
			return yes();
		}
		if(c1<3)continue;
		int rt=0;
		for(int u:o)if(e[u].size()>2)rt=u;
		vector<vi>t;
		for(int v:e[rt])o.clear(),dfs(v,rt),t.pb(o);
		o=oo;
		sort(t.begin(),t.end(),[&](vi a,vi b){return a.size()<b.size();});
		a[rt]=(t[0].size()+1)*(t[1].size()+1)*(t[2].size()+1);
		For(i,0,2){
			int sz=t[i].size();
			For(j,1,sz)a[t[i][j-1]]=a[rt]/(sz+1)*(sz+1-j);
		}
		int sum=0;
		for(int u:o){
			sum-=a[u]*a[u];
			if(u!=rt)sum+=a[u]*a[fa[u]];
		}
		if(sum>=0)return yes();
		for(int u:o)a[u]=0;
	}puts("NO");
}

signed main()
{
	int T;cin>>T;
	while(T--)work();
    return 0;
}