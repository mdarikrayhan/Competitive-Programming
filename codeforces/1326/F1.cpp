#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=18;
int n,sz[1<<N];
string a[N];
vector<ll>f[1<<N][N];
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=1;i<1<<n;i++)sz[i]=1<<__builtin_popcount(i)-1;
	for(int i=0;i<1<<n;i++)for(int j=0;j<n;j++)if(i>>j&1)f[i][j].resize(sz[i]);
	for(int i=0;i<n;i++)f[1<<i][i][0]=1;
	for(int i=1;i<1<<n;i++)for(int j=0;j<n;j++)if(i>>j&1)for(int k=0;k<sz[i];k++)if(f[i][j][k]) {
		for(int l=0;l<n;l++)if(i>>l&1^1)f[i|1<<l][l][k*2+a[j][l]-'0']+=f[i][j][k];
	}
	for(int i=0;i<1<<n-1;i++) {
		ll F=0;for(int j=0;j<n;j++)F+=f[(1<<n)-1][j][i];
		cout<<F<<' ';
	}
	return 0;
}