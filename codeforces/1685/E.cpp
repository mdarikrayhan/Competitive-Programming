// LUOGU_RID: 123258515
#include<bits/stdc++.h>
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
using namespace std;
const int N=2e5+10;
int n,m,q,a[N],b[N];
int s1,s2;
struct node{
	int sum,mn,id;
}tr[N<<2];
node operator+(node a,node b){
	node c;
	c.sum=a.sum+b.sum;
	if(a.mn<=a.sum+b.mn)c.mn=a.mn,c.id=a.id;
	else c.mn=a.sum+b.mn,c.id=b.id;
	return c;
}
#define ls (o<<1)
#define rs (o<<1|1)
void bld(int o,int l,int r){
	if(l==r){
		tr[o].sum=tr[o].mn=(a[l]<=n?-1:(a[l]==n+1?0:1)),tr[o].id=l;
		return;
	}
	int mid=l+r>>1;
	bld(ls,l,mid),bld(rs,mid+1,r);
	tr[o]=tr[ls]+tr[rs];
}
void upd(int o,int l,int r,int x){
	if(l==r)return void(tr[o].sum=tr[o].mn=(a[l]<=n?-1:(a[l]==n+1?0:1)));
	int mid=l+r>>1;
	if(x<=mid)upd(ls,l,mid,x);
	else upd(rs,mid+1,r,x);
	tr[o]=tr[ls]+tr[rs];
}
node qry(int o,int l,int r,int x,int y){
	if(x>y)return (node){0,N};
	if(x<=l&&r<=y)return tr[o];
	int mid=l+r>>1;
	if(y<=mid)return qry(ls,l,mid,x,y);
	if(x>mid)return qry(rs,mid+1,r,x,y);
	return qry(ls,l,mid,x,y)+qry(rs,mid+1,r,x,y);
}
#define pos b[n+1]
void add(int x,int v){
	if(x<=n+1){
		if(x==1)s1+=(b[1]-b[n+1]+m)%m*v;
		else s1+=(b[x]-b[x-1]+m)%m*v;
		if(x==n+1)s1+=(b[1]-b[n+1]+m)%m*v;
		else s1+=(b[x+1]-b[x]+m)%m*v;
	}
	if(x>=n+1){
		if(x==n+1)s2+=(b[n+1]-b[m]+m)%m*v;
		else s2+=(b[x]-b[x-1]+m)%m*v;
		if(x==m)s2+=(b[n+1]-b[m]+m)%m*v;
		else s2+=(b[x+1]-b[x]+m)%m*v;
	}
}
signed main(){
	scanf("%d%d",&n,&q),m=2*n+1;
	for(int i=1;i<=m;i++)scanf("%d",&a[i]),b[a[i]]=i;
	bld(1,1,m);
	for(int i=1;i<=n;i++)s1+=(b[i+1]-b[i]+m)%m;
	s1+=(b[1]-b[n+1]+m)%m;
	for(int i=n+1;i<m;i++)s2+=(b[i+1]-b[i]+m)%m;
	s2+=(b[n+1]-b[m]+m)%m;
	for(int x,y;q--;){
		scanf("%d%d",&x,&y);
		add(a[x],-1),add(a[y],-1);
		b[a[x]]=y,b[a[y]]=x;swap(a[x],a[y]);
		add(a[x],1),add(a[y],1);
		upd(1,1,m,x),upd(1,1,m,y);
		node t=qry(1,1,m,pos,m)+qry(1,1,m,1,pos-1);
		if(t.mn<0)printf("%d\n",tr[1].id%m);
		else if(s1!=m)printf("%d\n",pos%m);
		else if(s2!=m)printf("%d\n",pos-1);
		else puts("-1");
	}
}