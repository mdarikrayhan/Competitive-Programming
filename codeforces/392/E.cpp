// LUOGU_RID: 136192069
#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
int n,w[405],a[405],f[405][405],d[405][405],g[405][405];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int ans=0;
	for(int len=1;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			f[l][r]=-inf;
			if(l!=r) d[l][r]=d[r][l]=-inf;
			for(int j=l;j<r;j++) if(a[j]+1==a[r]) d[l][r]=max(d[l][r],d[l][j]+f[j+1][r-1]);
			for(int j=r;j>l;j--) if(a[j]+1==a[l]) d[r][l]=max(d[r][l],d[r][j]+f[l+1][j-1]);
			for(int j=l;j<r;j++) f[l][r]=max(f[l][r],f[l][j]+f[j+1][r]),g[l][r]=max(g[l][r],g[l][j]+g[j+1][r]);
			for(int j=l;j<=r;j++)if(a[j]>=a[l]&&a[j]>=a[r]&&a[j]-a[l]+a[j]-a[r]+1<=n){
				f[l][r]=max(f[l][r],d[l][j]+d[r][j]+w[a[j]+a[j]-a[l]-a[r]+1]);
			}
			g[l][r]=max(g[l][r],f[l][r]);
		}
	}
	printf("%d",g[1][n]);
	return 0;
}