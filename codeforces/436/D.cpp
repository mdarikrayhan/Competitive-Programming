// LUOGU_RID: 158832736
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=2e3+5,mx=2e5;
int n,m,a[N],spe[M],f[N],g[N];
int sum[mx+5],l[N],r[N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=m;i++){
		scanf("%d",&spe[i]);
		sum[spe[i]]++;
	}
	sort(spe+1,spe+1+m);
	for(int i=1;i<=mx;i++){
		sum[i]+=sum[i-1];
	}
	a[0]=-mx;
	a[n+1]=mx*2;
	for(int i=1;i<=n;i++){
		l[i]=(a[i-1]+1==a[i])?l[i-1]:i;
	}
	for(int i=n;i>=1;i--){
		r[i]=(a[i+1]-1==a[i])?r[i+1]:i;
	}
	for(int i=1;i<=n;i++){
		f[i]=max(f[i],f[i-1]+sum[a[i]]-sum[a[i]-1]);
		g[i]=max(g[i],f[i-1]+sum[a[i]]-sum[a[i]-1]);
		for(int j=1;spe[j]<a[i]&&j<=m;j++){
			if(a[i]-spe[j]<i){
				g[i]=max(g[i],sum[a[i]]-sum[spe[j]-1]+f[l[i-a[i]+spe[j]]-1]);
			}
		}
		f[i]=max(f[i],g[i]);
		for(int j=m;j>=1&&spe[j]>=a[i];j--){
			if(spe[j]-a[i]<=n-i){
				f[r[i+spe[j]-a[i]]]=max(f[r[i+spe[j]-a[i]]],g[i]+sum[spe[j]]-sum[a[i]]); 
			}
		}
	}
	printf("%d",f[n]);
	return 0;
} 