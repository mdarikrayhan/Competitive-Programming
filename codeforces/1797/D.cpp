#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,m;
int siz[N],v[N],s[N],fa[N];
vector<int>son[N];
struct cx{
	int x;
	bool operator <(const cx &t)const{return siz[x]!=siz[t.x]?siz[x]>siz[t.x]:x<t.x;}
};
set<cx>e[N];
void dfs(int x,int prt){
	fa[x]=prt,siz[x]=1,s[x]=v[x];
	for(int y:son[x])if(y!=prt)dfs(y,x),siz[x]+=siz[y],s[x]+=s[y],e[x].insert((cx){y});
}
inline void del(int x,int y){if(e[x].find((cx){y})!=e[x].end())e[x].erase((cx){y}),siz[x]-=siz[y],s[x]-=s[y];}
inline void add(int x,int y){e[x].insert((cx){y}),siz[x]+=siz[y],s[x]+=s[y],fa[y]=x;}
inline void change(int x){
	if(e[x].size()){
		int u=(*e[x].begin()).x,prt=fa[x];
		del(prt,x),del(x,u),add(u,x),add(prt,u);
	}
}
signed main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>v[i];
	for(int i=1,x,y;i<n;++i)cin>>x>>y,son[x].push_back(y),son[y].push_back(x);
	dfs(1,0);
	while(m--){
		int op,x;
		cin>>op>>x;
		if(op==1)cout<<s[x]<<"\n";
		else change(x);
	}
	return 0;
}