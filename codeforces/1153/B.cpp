#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1E3+5;
bool mat[N][N];
int n,m,a[N],b[N],ans[N][N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int h;cin>>n>>m>>h;
	for (int i=1;i<=m;i++) cin>>b[i];
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cin>>mat[i][j];
			if (mat[i][j]) ans[i][j]=min(a[i],b[j]);
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cout<<ans[i][j]<<" \n"[j==m];
		}
	}
	return 0;
}