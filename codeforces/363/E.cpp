#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

int N,M,R,a[505][505],r[505],rr[1005],s[505][505],f[505][505],g[505][505];
ll h[505][505];

void renew(int&x,ll&y,int a,int b) {if (a>x) x=a,y=b; else if (a==x) y+=b;}

void init()
{
	scanf("%d%d%d",&N,&M,&R);
	for (int i=1; i<=N; i++)
		for (int j=1; j<=M; j++) scanf("%d",&a[i][j]),s[i][j]=s[i][j-1]+a[i][j];
}

void doit()
{
	for (int i=0,j=R; i<=R; r[i++]=j)
		for (;i*i+j*j>R*R; j--);
	for (int i=0; i<=R+R; i++)
		for (int j=max(i-R,0); j<=i&&j<=R; j++) rr[i]=max(rr[i],r[j]+r[i-j]+1);
	memset(g,192,sizeof(g));
	for (int i=R+1; i+R<=N; i++)
		for (int j=R+1; j+R<=M; j++)
		{
			f[i][j]=s[i][j+R]-s[i][j-R-1];
			for (int k=1; k<=R; k++) f[i][j]+=s[i+k][j+r[k]]-s[i+k][j-r[k]-1]+s[i-k][j+r[k]]-s[i-k][j-r[k]-1];
			g[i][j]=g[i][j-1],h[i][j]=h[i][j-1],renew(g[i][j],h[i][j],f[i][j],1);
		}
	int ans1=0; ll ans2=0;
	for (int i=R+1; i+R<=N; i++)
		for (int j=R+1; j+R<=M; j++)
			for (int k=R+1,p; k<=i+R+R&&k<=N; k++) if (i-k>R+R)
			{
				renew(ans1,ans2,f[i][j]+g[k][M-R],h[k][M-R]);
			}
			else
			{
				p=j-rr[i>k?i-k:k-i];
				if (p>R) renew(ans1,ans2,f[i][j]+g[k][p],h[k][p]);
			}
	printf("%d %I64d\n",ans1,ans2);
}

int main()
{
	init();
	doit();
	return 0;
}