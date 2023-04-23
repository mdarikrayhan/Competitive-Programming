#include<bits/stdc++.h>
using namespace std;
const int o=4010;
int T,n,m,u[o],v[o],ans[o],h[o],cnt,dfn[o],ed[o],fa[o],fae[o];mt19937 rnd(time(0));
struct Edge{int v,p,w;}e[o];
inline void ad(int U,int V,int W){e[++cnt].v=V;e[cnt].p=h[U];e[h[U]=cnt].w=W;}
void dfs(int nw){
	dfn[nw]=++cnt;
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^fa[nw]) fa[e[i].v]=nw,fae[e[i].v]=e[i].w,dfs(e[i].v);
	ed[nw]=cnt;
}
inline bool chk(int x,int y){
	for(int i=1,t;i<=45;++i){
		cout<<"? "<<((rnd()%2)?x:y)<<endl;cin>>t;
		if(!t) return false;
	}
	return true;
}
int main(){
	for(cin>>T;T--;cout<<endl,cin>>n,cnt=0){
		cin>>n>>m;
		for(int i=1;i<=n;++i) h[i]=0;
		for(int i=1;i<=m;++i) cin>>u[i]>>v[i];
		for(int i=1;i<=m;++i){
			cout<<"- "<<i<<endl;
			if(chk(u[i],v[i])) ans[i]=0;
			else ans[i]=1,cout<<"+ "<<i<<endl,ad(u[i],v[i],i),ad(v[i],u[i],i);
		}
		cnt=0;dfs(1);
		for(int i=1,t;i<=m;++i) if(!ans[i]){
			if(dfn[u[i]]<=dfn[v[i]]&&ed[v[i]]<=ed[u[i]]) t=fae[v[i]];
			else t=fae[u[i]];
			cout<<"- "<<t<<endl<<"+ "<<i<<endl;
			ans[i]=chk(u[i],v[i]);
			cout<<"+ "<<t<<endl<<"- "<<i<<endl;
		}
		cout<<"! ";
		for(int i=1;i<=m;++i) cout<<ans[i]<<" ";
	}
	return 0;
}