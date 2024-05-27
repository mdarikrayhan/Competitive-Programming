// LUOGU_RID: 160309129
#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int n,m,h[N],V=0,d[N];

const int S=N*20;
int idx=0,rt[N],ls[S],rs[S];
struct W{
	int l,r,s,x;W(){}
	W(int k,int x):l(k),r(k),s(k),x(x){};
	W operator+(const W&b)const{
		W c;c.x=x+b.x;
		c.l=l==x?x+b.l:l;
		c.r=b.r==b.x?b.x+r:b.r;
		c.s=max(max(s,b.s),r+b.l);
		return c;
	}
}tr[S];
#define mid (l+r>>1)
#define Ls ls[p],l,mid
#define Rs rs[p],mid+1,r
#define all(x) rt[x],1,n
void build(int&p,int l,int r){p=++idx;tr[p]=W(0,r-l+1);if(l==r)return;build(Ls);build(Rs);}
void upd(int&p,int l,int r,int x){
	idx++;ls[idx]=ls[p];rs[idx]=rs[p];p=idx;
	if(l==r){tr[p]=W(1,1);return;}
	x<=mid?upd(Ls,x):upd(Rs,x);tr[p]=tr[ls[p]]+tr[rs[p]];
}
W qry(int p,int l,int r,int L,int R){if(L<=l&&r<=R)return tr[p];return L>mid?qry(Rs,L,R):R<=mid?qry(Ls,L,R):qry(Ls,L,R)+qry(Rs,L,R);}
#undef mid
basic_string<int>v[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%d",&h[i]);d[++V]=h[i];}
	sort(d+1,d+V+1);V=unique(d+1,d+V+1)-d-1;
	for(int i=1;i<=n;i++)v[lower_bound(d+1,d+V+1,h[i])-d]+=i;
	build(all(V+1));
	for(int i=V;i;i--){rt[i]=rt[i+1];for(int p:v[i])upd(all(i),p);}
	scanf("%d",&m);
	for(int ql,qr,k;m--;){
		scanf("%d%d%d",&ql,&qr,&k);
		int l=1,r=V,mid;
		while(l<r)qry(all(mid=l+r+1>>1),ql,qr).s>=k?l=mid:r=mid-1;
		printf("%d\n",d[l]);
	}
	return 0;
}