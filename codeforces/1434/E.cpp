#include<bits/stdc++.h>
using namespace std;
int v[100005];
int f[100005],p[100005],zy[100005],fa[100005];
int findfather(int x){
	return x==fa[x]?x:fa[x]=findfather(fa[x]);
}
int main(){
	int n;
	scanf("%d",&n);
	int yh=0;
	for(int i=1;i<=n;++i){
		int m;
		scanf("%d",&m);
		for(int i=1;i<=m;++i)scanf("%d",&v[i]);
		if(m==1){
			yh^=1;
			continue;
		}
		for(int j=0;j<=m;++j)f[j]=0;
		for(int j=1;j<=m;++j){
			f[j]=f[j-1];
			while(f[j]<j&&v[f[j]+1]<=2*v[j]-v[m])++f[j];
		}
		v[0]=0,v[m+1]=v[m]+1;
		for(int j=0;j<=m;++j)for(int k=v[j];k<v[j+1];++k)zy[k]=j;
		int fl=0;
		for(int j=1;j<=m;++j)if(f[j]==j)fl=1;
		int sg=0;
		while(fl){
			++sg;
			for(int j=1;j<=m;++j)p[j]=j;
			for(int j=1;j<=m+1;++j)fa[j]=j;
			fl=0;
			for(int j=m;j>=1;--j){
				if(f[j]<j){
					int L=f[j]+1,R=zy[max(0,2*v[j]-v[p[j]])];
					if(L<=R){
						f[j]=R;
						for(int k=findfather(L);k<=R;k=findfather(fa[k]=k+1))p[k]=max(p[k],j);
						if(f[j]==j)fl=1;
					}
				}
			}
		}
		yh^=sg;
	}
	puts(yh?"YES":"NO");
	return 0;	
}
