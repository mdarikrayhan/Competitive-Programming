// LUOGU_RID: 159832967
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
struct edge{
	int u,v,w;
	bool operator<(const edge&t)const{return w>t.w;}
};
vector<edge> e;
int a[N],b[N],fa[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
signed main() {
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n,m,sum=0;cin>>m>>n;
	for(int i=1;i<=m;++i)cin>>a[i];
	for(int i=1;i<=n;++i)cin>>b[i];
	for(int i=1;i<=m;++i){
		int k;cin>>k;
		while(k--){
			int u;cin>>u;
			e.push_back({u,n+i,a[i]+b[u]});
			sum+=a[i]+b[u];
		}
	}
	sort(e.begin(),e.end());
	int cnt=0,res=0;
	for(int i=1;i<=n+m;++i)fa[i]=i;
	for(int i=0;i<e.size();++i){
		int u=e[i].u,v=e[i].v,w=e[i].w,x=find(u),y=find(v);
		if(x!=y){
			fa[x]=y,res+=w;
			if(++cnt==n+m-1)break;
		}
	}
	cout<<sum-res<<'\n';
	return 0;
}