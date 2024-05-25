#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mxN(1e5),mxK(5e2);
const ll INF(1e16);
int n,a[mxN+5];
ll psm[mxN+5],f[mxN+5][mxK+5];
ll SUM(int l,int r){return psm[r]-psm[l-1];}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i(1);i<=n;++i)scanf("%d",&a[i]),psm[i]=psm[i-1]+a[i];
		
		for(int i(0);i*i<=((n+1)<<1);++i)f[n+1][i]=-INF;f[n+1][0]=INF;//f(n+1,0)=INF保证了最后k至少大于等于0.
		
		for(int i(n);i>=1;--i)
			for(int j(0);j*j<=((n+1)<<1);++j){
				f[i][j]=f[i+1][j];
				if(j&&i+j-1<=n&&SUM(i,i+j-1)<f[i+j][j-1])f[i][j]=max(f[i][j],SUM(i,i+j-1));
			}
		for(int i(sqrt((n+1)<<1));;--i)if(f[1][i]>0){printf("%d\n",i);break;}
	}
	return 0;
}