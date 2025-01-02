// LUOGU_RID: 158261536
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxk=101,N=250000;
int a[maxk];
ll ans,f[maxk][N];
inline ll F(register ll n,register int k)
{
	if(!(k&&n)) return 0;
	if(n<N) return f[k][n];
	return n/a[k]+F(n,k-1)-F(n/a[k],k-1);
}
int main()
{
	ll n;
	int k;
	scanf("%lld%d",&n,&k);
	for(register int i=1;i<=k;i++) scanf("%d",&a[i]);
	sort(a+1,a+k+1);
	for(register int i=1;i<=k;i++) for(register int j=1;j<N;j++) f[i][j]=j/a[i]+f[i-1][j]-f[i-1][j/a[i]];
	printf("%lld",n-F(n,k));
	return 0;
}