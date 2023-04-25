#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[320],f[320][180020];
const int p=998244353;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=-90000;i<=90000;i++) f[n][i]=1;
	for(int i=n-1;i>1;i--)
		for(int j=-90000;j<=90000;j++)
			f[i][j]=(f[i+1][a[i+1]+j]+(j!=0)*f[i+1][a[i+1]-j])%p;
	cout<<f[2][a[2]]<<endl;
	return 0;
}