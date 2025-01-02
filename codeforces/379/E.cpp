#pragma GCC optimize("O2")
#include<bits/stdc++.h>
#define K 2000
#define maxn 2000
using namespace std;
int n,k,y,h;
double s[maxn];
int a[maxn][maxn];

int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k+1;j++)
			scanf("%d",&a[i][j]);
	for(int now=1;now<=k;now++)
		for(int j=0;j<=K;j++)
			for(int i=1,nowy=0;i<=n;i++)
			{
				y=a[i][now]*(K-j)+a[i][now+1]*j;
				h=max(0,y-nowy);nowy=max(nowy,y);
				s[i]+=h*(j&&j<K?2:1);
			}
	for(int i=1;i<=n;i++)
		printf("%.12lf\n",s[i]/(2*K*K));//一个是解析式一个是宽度
	return 0;
}