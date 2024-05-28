#include<bits/stdc++.h>
using namespace std;
int n,m;
#define ll long long
struct ed{int x,z;};
vector<ed>g[101000];
struct qb{ll lm,rm,mx,su;};
qb operator + (const qb &a,const qb &b){
	return (qb){max(a.lm,a.su+b.lm),max(b.rm,a.rm+b.su),max(a.rm+b.lm,max(a.mx,b.mx)),a.su+b.su};
}
qb a[401000];
struct qu{int id,l,r;};
vector<qu>o[101000];
int q;ll ans[101000];
void up(int p,int l,int r,int x,ll z){
	if(l==r){a[p]=(qb){z,z,z,z};return;}
	int mid=(l+r)>>1;
	if(x<=mid)up(p<<1,l,mid,x,z);
	else up(p<<1|1,mid+1,r,x,z);
	a[p]=a[p<<1]+a[p<<1|1];
}
qb ask(int p,int l,int r,int x,int y){
	if(x<=l&&r<=y)return a[p];
	int mid=(l+r)>>1;
	if(y<=mid)return ask(p<<1,l,mid,x,y);
	if(x>mid)return ask(p<<1|1,mid+1,r,x,y);
	return ask(p<<1,l,mid,x,y)+ask(p<<1|1,mid+1,r,x,y);
}
#define pb push_back
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,l,r,z;i<=m;i++){
		scanf("%d%d%d",&l,&r,&z);
		g[l].pb((ed){i,z});
		g[r+1].pb((ed){i,0});
	}
	scanf("%d",&q);
	for(int i=1,l,r,x;i<=q;i++){
		scanf("%d%d%d",&x,&l,&r);
		o[x].pb((qu){i,l,r});
	}
	for(int i=1;i<=n;i++){
		for(ed t:g[i])up(1,1,m,t.x,t.z);
		for(qu t:o[i])ans[t.id]=ask(1,1,m,t.l,t.r).mx;
	}
	for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
	return 0;
}