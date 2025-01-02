// LUOGU_RID: 159387029
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10,M=998244353;
int n,m,v[110][110],p[128],ans;
char a[110][110];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	p['W']=1;
	p['B']=-1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=n;i;i--)
		for(int j=m;j;j--){
			if(p[a[i][j]]!=v[i][j]){
				ans++;
				int x=p[a[i][j]]-v[i][j];
				for(int k=1;k<=i;k++)
					for(int l=1;l<=j;l++)
						v[k][l]+=x;
					}
				}
	cout<<ans;
	return 0;
}
