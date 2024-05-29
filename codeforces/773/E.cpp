// LUOGU_RID: 158920248
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,sft=5e5;
struct segtree{
	int sum[N+1<<2];
	struct node{
		int l,r,res;
	}V[N+1<<2];
	inline node merge(node A,node B){
		int G=min(A.r,B.l);node C;
		C.res=A.res+B.res+G;
		C.r=A.r+B.r-G,C.l=A.l+B.l-G;
		return C;
	}
	inline void change(int x,int y,int k,int pos){
		if(x==y){sum[k]++;V[k].l++;return;}
		int mid=x+y>>1;
		if(pos<=mid)change(x,mid,k<<1,pos);
		else change(mid+1,y,k<<1|1,pos);
		sum[k]=sum[k<<1]+sum[k<<1|1];
		V[k]=merge(V[k<<1],V[k<<1|1]);
	}
	inline int binary(int x,int y,int k,int res){
		if(x==y)return x;int mid=x+y>>1;
		if(res+sum[k<<1]+mid>=sft)return binary(x,mid,k<<1,res);
		else return binary(mid+1,y,k<<1|1,res+=sum[k<<1]);
	}
	inline node query(int x,int y,int k,int l,int r){
		if(x==l&&y==r)return V[k];int mid=x+y>>1;
		if(l<=mid&&r>mid)return merge(query(x,mid,k<<1,l,mid),query(mid+1,y,k<<1|1,mid+1,r));
		else if(l<=mid)return query(x,mid,k<<1,l,r);else return query(mid+1,y,k<<1|1,l,r);
	}
	inline void build(int x,int y,int k){
		if(x==y){V[k].r=1;return;}
		int mid=x+y>>1;
		build(x,mid,k<<1);
		build(mid+1,y,k<<1|1);
		V[k].r=y-x+1;
	}
}tr;
int n,a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	tr.build(0,N,1);
	for(int i=1;i<=n;++i){
		tr.change(0,N,1,a[i]+sft);
		int val=tr.binary(0,N,1,0)-sft;
		cout<<val+tr.query(0,N,1,val+sft,N).res<<'\n';
	}
}