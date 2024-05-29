// LUOGU_RID: 160378128
// 2024 HOPE IN VALUABLE
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n,m,Q; ll a[N],b[N],A[N]; vector<pair<int,int> >q[N];
struct SegTree{
	#define ls(x) (x<<1)
	#define rs(x) (x<<1|1)
	ll t[N<<2],tag[N<<2];
	inline void pu(int u){ t[u]=min(t[ls(u)],t[rs(u)]); }
	inline void lzy(int u,ll x){ t[u]+=x; tag[u]+=x; }
	inline void pd(int u){ if(tag[u]) lzy(ls(u),tag[u]),lzy(rs(u),tag[u]),tag[u]=0; }
	inline void build(int u,int l,int r,ll *a){
		if(l==r) return t[u]=a[l],void();
		int mid=l+r>>1;
		build(ls(u),l,mid,a); build(rs(u),mid+1,r,a);
		pu(u);
	}
	inline void add(int u,int l,int r,int ql,int qr,int x){
		if(l>=ql&&r<=qr) return lzy(u,x);
		int mid=l+r>>1; pd(u);
		if(ql<=mid) add(ls(u),l,mid,ql,qr,x);
		if(qr>mid) add(rs(u),mid+1,r,ql,qr,x);
		pu(u);
	}
}t1,t2;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m>>Q;
	for(int i=1;i<n;i++) cin>>a[i]>>b[i+1];
	for(int i=1;i<=m;i++){
		int x,y,z; cin>>x>>y>>z;
		q[x].emplace_back(y,z);
	}
	t1.build(1,1,n,b);
	for(int i=1;i<=n;i++){
		for(pair<int,int> j:q[i]) 
			t1.add(1,1,n,1,j.first,j.second);
		A[i]=a[i]+t1.t[1];
	}
	t2.build(1,1,n,A); cout<<t2.t[1]<<'\n';
	while(Q--){
		int x,y; cin>>x>>y;
		t2.add(1,1,n,x,x,y-a[x]); a[x]=y;
		cout<<t2.t[1]<<'\n';
	}
	return 0;
}