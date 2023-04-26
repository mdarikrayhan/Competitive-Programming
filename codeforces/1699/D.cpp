#include<bits/stdc++.h>
using namespace std;const int N=5e3+7;
int T_T,i,j,n,k,a[N],f[N],c[N];
int main(){
	for(scanf("%d",&T_T);T_T--;){
		for(scanf("%d",&n),i=1;i<=n;++i)scanf("%d",a+i);
		for(i=1;i<=n+1;++i){
			for(f[i]=-N,k=j=0;j<i;++j)c[a[j]]=0;
			for(j=i-1;j!=-1;--j){
				if((i-j&1)&&k*2<i-j&&(a[j]==a[i]||i>n||!j))f[i]=max(f[i],f[j]+1);
				k=max(k,++c[a[j]]);
			}
		}printf("%d\n",f[n+1]-1);
	}
}