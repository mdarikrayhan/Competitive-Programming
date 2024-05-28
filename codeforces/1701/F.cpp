// LUOGU_RID: 159878589
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
const int V=2e5;

struct segtree{
	struct node{
		int f,w,lazy;
	}tree[N*4];
	
	void pushup(int x){
		tree[x].w=tree[x*2].w+tree[x*2+1].w;
		tree[x].f=tree[x*2].f+tree[x*2+1].f;
	}
	
	void pushtag(int x,int tag,int l,int r){
		tree[x].f+=tag*tree[x].w;
		tree[x].lazy+=tag;
	}
	
	void pushdown(int x,int l,int r){
		int tag=tree[x].lazy;
		if(!tag) return; int mid=(l+r)>>1;
		pushtag(x*2,tag,l,mid);
		pushtag(x*2+1,tag,mid+1,r);
		tree[x].lazy=0;
	}
	
	void modifysum(int x,int l,int r,int pos,int val){
		if(l==r&&l==pos){
			tree[x].w+=val;
			return;
		}
		if(pos<l||r<pos) return;
		int mid=(l+r)>>1;
		pushdown(x,l,r);
		modifysum(x*2,l,mid,pos,val);
		modifysum(x*2+1,mid+1,r,pos,val);
		pushup(x);
	}
	
	void modifyF(int x,int l,int r,int L,int R,int val){
		if(l<=L&&R<=r){
			pushtag(x,val,L,R);
			return;
		}
		if(R<l||r<L) return;
		int mid=(L+R)>>1;
		pushdown(x,L,R);
		modifyF(x*2,l,r,L,mid,val);
		modifyF(x*2+1,l,r,mid+1,R,val);
		pushup(x);
	}
	
	int querysum(int x,int l,int r,int L,int R){
		if(l<=L&&R<=r){
			return tree[x].w;
		}
		if(R<l||r<L) return 0;
		int mid=(L+R)>>1;
		pushdown(x,L,R);
		return querysum(x*2,l,r,L,mid)+querysum(x*2+1,l,r,mid+1,R);
	}
	
	int queryF(int x,int l,int r,int L,int R){
		if(l<=L&&R<=r){
			return tree[x].f;
		}
		if(R<l||r<L) return 0;
		int mid=(L+R)>>1;
		pushdown(x,L,R);
		return queryF(x*2,l,r,L,mid)+queryF(x*2+1,l,r,mid+1,R);
	}
}q;

int vis[N];

inline void fake_main(){
	int n,d; cin>>n>>d; int ans=0;
	for(int i=1;i<=n;i++){
		int pos; cin>>pos;
		if(!vis[pos]){
			int t=q.queryF(1,pos-d,pos-1,1,V);
			ans+=t; //cout<<t<<" ";
			t=q.querysum(1,pos+1,pos+d,1,V);
			if(t!=0) ans+=t*(t-1)/2; //cout<<t<<"\n";
			q.modifysum(1,1,V,pos,1);
			q.modifyF(1,pos-d,pos-1,1,V,1);
			q.modifyF(1,pos,pos,1,V,t);
			
		}else{
			int t=q.queryF(1,pos-d,pos-1,1,V);
			int cnt=q.querysum(1,pos-d,pos-1,1,V);
			ans-=t-cnt;
			t=q.querysum(1,pos+1,pos+d,1,V);
			if(t!=0) ans-=t*(t-1)/2; //cout<<"T "<<t<<"\n";
			
			q.modifyF(1,pos-d,pos-1,1,V,-1);
			q.modifyF(1,pos,pos,1,V,-t);
			q.modifysum(1,1,V,pos,-1);
		}
		//for(int j=1;j<=10;j++) cout<<q.queryF(1,j,j,1,V)<<" "; cout<<"\n";
		vis[pos]^=1;
		cout<<ans<<"\n";
	}
}

signed main(){
	ios::sync_with_stdio(false);
	int t; t=1;
	while(t--) fake_main();
}
