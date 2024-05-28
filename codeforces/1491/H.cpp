#include<bits/stdc++.h>
using namespace std;
int n,q,len;
const int maxn=1e5+10;
const int maxm=320;
int a[maxn],b[maxn],p[maxn];
int L[maxm],R[maxm],f[maxm],cnt[maxm];
void update(int x){
	for(int i=L[x];i<=R[x];i++){
		a[i]=max(a[i]-f[x],1);
	}
	f[x]=0;
	for(int i=L[x];i<=R[x];i++){
		if(a[i]<L[x]){
			b[i]=a[i];
		}
		else{
			b[i]=b[a[i]];
		}
	}
}
void solve(int l,int r,int x){
	if(p[l]==p[r]){
		for(int i=l;i<=r;i++){
			a[i]=max(a[i]-x,1);
		}
		update(p[l]);
	}
	else{
		for(int i=l;i<=R[p[l]];i++){
			a[i]=max(a[i]-x,1);
		}
		update(p[l]);
		for(int i=L[p[r]];i<=r;i++){
			a[i]=max(a[i]-x,1);
		}
		update(p[r]); 
		for(int i=p[l]+1;i<=p[r]-1;i++){
			cnt[i]++;
			f[i]=min(f[i]+x,n);
			if(cnt[i]<=len){
				update(i);
			}
		}
	}
}
int B(int x){
	return max(b[x]-f[p[x]],1);
}
int lca(int u,int v){
	while(1){
		if(p[u]<p[v]){
			swap(u,v);
		}
		if(p[u]!=p[v]){
			u=B(u);
		}
		else{
			if(B(u)!=B(v)){
				u=B(u),v=B(v);
			}
			else{
				break;
			}
		}
	}
	while(u!=v){
		if(u<v){
			swap(u,v);
		}
		u=max(a[u]-f[p[u]],1);
	}
	return u;
}
int main(){
	scanf("%d%d",&n,&q);
	len=sqrt(n);
	p[1]=1;
	for(int i=2;i<=n;i++){
		scanf("%d",&a[i]);
		p[i]=(i-1)/len+1;
	}		
	for(int i=1;i<=(n-1)/len+1;i++){
		L[i]=(i-1)*len+1;
		R[i]=min(i*len,n);
		update(i);
	}
	while(q--){
		int op;
		scanf("%d",&op);
		if(op==1){
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			solve(l,r,x);
		}
		else{
			int u,v;
			scanf("%d%d",&u,&v);
			printf("%d\n",lca(u,v));
		}
	}
	return 0;
}