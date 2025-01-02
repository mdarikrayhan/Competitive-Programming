// LUOGU_RID: 160027035
#include<bits/stdc++.h>
using namespace std;
const int NN=2004,P=1e9+7;
int f[NN][NN],g[NN][NN];
char s[NN];
int main()
{
	int n,m;
	scanf("%d%d%s",&n,&m,s+1);
	f[0][0]=g[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++)
		{
			f[i][j]=(f[i][j]+1ll*(s[i]-'a')*g[i-1][j]%P)%P;
			int w=j-(n-i+1);
			for(int k=i-1;~k&&w>=0;k--)
			{
				f[i][j]=(f[i][j]+1ll*('z'-s[i])*f[k][w]%P)%P;
				w-=n-i+1;
			}
			g[i][j]=(g[i-1][j]+f[i][j])%P;
		}
	printf("%d",g[n][m]);
	return 0;
}