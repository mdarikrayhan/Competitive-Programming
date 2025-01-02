// LUOGU_RID: 160573461
// 2024 HOPE IN VALUABLE
#include<bits/stdc++.h>
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
using namespace std;
const int N=500005;
int n,idx,a[N],b[N],vis[N],book[N];
struct Node{ int mx,id; }t[N<<2];
inline Node pu(Node a,Node b){ return a.mx<b.mx?b:a; }
inline void build(int u,int l,int r){
	if(l==r) return t[u].mx=b[l],t[u].id=l,void();
	int mid=l+r>>1;
	build(ls(u),l,mid); build(rs(u),mid+1,r);
	t[u]=pu(t[ls(u)],t[rs(u)]);
}
inline Node ask(int u,int l,int r,int ql,int qr){
	if(l>=ql&&r<=qr) return t[u];
	int mid=l+r>>1;
	if(qr<=mid) return ask(ls(u),l,mid,ql,qr);
	if(ql>mid) return ask(rs(u),mid+1,r,ql,qr);
	return pu(ask(ls(u),l,mid,ql,qr),ask(rs(u),mid+1,r,ql,qr));
}
inline void del(int u,int l,int r,int x){
	if(l==r) return t[u].mx=0,void();
	int mid=l+r>>1;
	if(x<=mid) del(ls(u),l,mid,x); else del(rs(u),mid+1,r,x);
	t[u]=pu(t[ls(u)],t[rs(u)]);
}
inline void dfs(int u){
	if(book[u]) return; book[u]=1; del(1,1,n,u);
	if(b[u]<=n) dfs(b[u]);
	if(a[u]>1){
		while(1){
			Node tmp=ask(1,1,n,1,a[u]-1);
			if(tmp.mx>u) dfs(tmp.id); else break;
		}
	}
	vis[u]=++idx;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) b[i]=n+1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=-1) b[a[i]]=i; else a[i]=n+1;
	}
	build(1,1,n);
	for(int i=1;i<=n;i++) if(!book[i]) dfs(i);
	for(int i=1;i<=n;i++) cout<<vis[i]<<(i==n?'\n':' ');
	return 0;
}