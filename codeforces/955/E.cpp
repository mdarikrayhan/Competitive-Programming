#include<bits/stdc++.h>
using namespace std;
const int I=1e9;
int n,a[200100],ans=I,fz[200100];
struct qb{
	int f[200100][20];
	inline void build(int *e){
		for(int i=1;i<=n;i++)f[i][0]=e[i];
		for(int j=1;j<20;j++)for(int i=1;i+(1<<j)-1<=n;i++)
			f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	}
	inline int ask(int l,int r){
		int k=log2(r-l+1);
		return min(f[l][k],f[r-(1<<k)+1][k]);
	}
	inline int ask2(int l,int r,int t){
		for(int j=19;j>=0;j--)if(l+(1<<j)-1<=r&&f[l][j]>=t)l+=(1<<j);
		if(l>r)return -1;return l;
	}
}T[4];
int as(int l,int r,int t){
	if(t<l)return T[0].ask(l,r)-t;
	if(t>r)return T[1].ask(l,r)+t;
	return min(T[1].ask(l,t)+t,T[0].ask(t,r)-t);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)fz[i]=a[i]+i;T[0].build(fz);
	for(int i=1;i<=n;i++)fz[i]=a[i]-i;T[1].build(fz);
	for(int i=1;i<=n;i++)fz[i]=a[i]-i*2;T[2].build(fz);
	for(int i=1;i<=n;i++)fz[i]=a[i];T[3].build(fz);
	for(int t=1;t<=n;t++){
		int e=T[2].ask2(1,t,-t);//a[i]-2i<-t
		if(e==-1)e=T[3].ask2(t,n,t);//a[i]<t
		if(e==-1)continue;
		int o1=as(1,e-1,t),o2=as(e,n,t);
		ans=min(ans,max(o1,o2));
	}
	if(ans==I)puts("-1");
	else printf("%d",ans);
	return 0;
}