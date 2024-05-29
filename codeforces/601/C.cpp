// LUOGU_RID: 158736398
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
double f[101][N*101],ans,s[N*101];
int n,m,a[N],ss;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i],ss+=a[i];
	for(int i=1;i<=m;i++)
	if(i!=a[1])f[1][i]=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m*i;j++)
		s[j]=s[j-1]+f[i-1][j];
		for(int j=i;j<=m*i;j++){
			if(j<=m+1)f[i][j]=s[j-1]-f[i-1][j-a[i]]*(j-a[i]>=1);
			else f[i][j]=s[j-1]-s[j-m-1]-f[i-1][j-a[i]];
			f[i][j]/=(double)(m-1);
		}
	}
	for(int i=1;i<=ss-1;i++)
	ans+=f[n][i];
	printf("%.15lf\n",ans+1);
	return 0;
}