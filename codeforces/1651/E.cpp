// LUOGU_RID: 156890559
// 2024 HOPE IN VALUABLE
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3005;
int n,anc; ll res,sum; vector<int>e[N]; 
inline void dfs0(int u,int fa,int l0,int r0,int l1,int r1,int lim,int o){
	int qwq=-1;
	for(int v:e[u]){
		if(v==fa||v==anc) continue;
		assert(qwq==-1); qwq=v;
	}
	if(qwq==-1) return;
	if(o) return dfs0(qwq,u,min(l0,qwq),max(r0,qwq),l1,r1,lim,o^1);
	else dfs0(qwq,u,l0,r0,min(l1,qwq),max(r1,qwq),lim,o^1);
	if(u<anc) return;
	int x=qwq,y=lim; if(x>y) swap(x,y);
	if((x>=l1&&x<=r1)||(y>=l1&&y<=r1)) return;
	if(x>r1) res+=1ll*l0*(n-r0+1)*(l1-n)*(x-r1);
	else if(y<l1) res+=1ll*l0*(n-r0+1)*(l1-y)*(n*2-r1+1);
	else res+=1ll*l0*(n-r0+1)*(l1-x)*(y-r1);
}
inline void dfs1(int u,int fa,int l0,int r0,int l1,int r1,int lim,int o){
	int qwq=-1;
	for(int v:e[u]){
		if(v==fa||v==anc) continue;
		assert(qwq==-1); qwq=v;
	}
	if(qwq==-1) return;
	if(!o) return dfs1(qwq,u,l0,r0,min(l1,qwq),max(r1,qwq),lim,o^1);
	else dfs1(qwq,u,min(l0,qwq),max(r0,qwq),l1,r1,lim,o^1);
	if(u<anc) return;
	int x=qwq,y=lim; if(x>y) swap(x,y);
	if((x>=l0&&x<=r0)||(y>=l0&&y<=r0)) return;
	if(x>r0) res+=1ll*(l1-n)*(n*2-r1+1)*l0*(x-r0);
	else if(y<l0) res+=1ll*(l1-n)*(n*2-r1+1)*(l0-y)*(n-r0+1);
	else res+=1ll*(l1-n)*(n*2-r1+1)*(l0-x)*(y-r0);
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n*2;i++){
		int u,v; cin>>u>>v;
		e[u].emplace_back(v); e[v].emplace_back(u);
	}
	for(anc=1;anc<=n;anc++){
		dfs0(e[anc][0],anc,anc,anc,e[anc][0],e[anc][0],e[anc][1],1);
		dfs0(e[anc][1],anc,anc,anc,e[anc][1],e[anc][1],e[anc][0],1);
		int x=e[anc][0],y=e[anc][1]; if(x>y) swap(x,y);
		res+=1ll*anc*(n-anc+1)*((y-x)*(y-x-1)/2+(x-n)*(x-n-1)/2+(n*2-y+1)*(n*2-y)/2);
	}
	for(anc=n+1;anc<=n*2;anc++){
		dfs1(e[anc][0],anc,e[anc][0],e[anc][0],anc,anc,e[anc][1],0);
		dfs1(e[anc][1],anc,e[anc][1],e[anc][1],anc,anc,e[anc][0],0);
		int x=e[anc][0],y=e[anc][1]; if(x>y) swap(x,y);
		res+=1ll*(anc-n)*(n*2-anc+1)*((y-x)*(y-x-1)/2+x*(x-1)/2+(n-y+1)*(n-y)/2);
	}
	for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) sum+=1ll*(j-i+1)*n*(n+1);
	cout<<sum/2-res/2<<'\n';
	return 0;
}