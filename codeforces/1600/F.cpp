#include<bits/stdc++.h>
using namespace std;

int n,m;
int mp[50][50];

signed main()
{
	scanf("%d%d",&n,&m);n=min(n,48);
	for(int i=1,u,v;i<=m;++i){
		scanf("%d%d",&u,&v);
		if(u<=48&&v<=48) mp[u][v]=mp[v][u]=1;
	}
	for(int i1=1;i1<=n;++i1)
	for(int i2=1;i2<=n;++i2) if(i1^i2)
	for(int i3=1;i3<=n;++i3) if(i1^i3&&i2^i3)
	for(int i4=1;i4<=n;++i4) if(i1^i4&&i2^i4&&i3^i4)
	for(int i5=1;i5<=n;++i5) if(i1^i5&&i2^i5&&i3^i5&&i4^i5)
	{
		bool f1=mp[i1][i2]&&mp[i1][i3]&&mp[i1][i4]&&mp[i1][i5]&&mp[i2][i3]&&mp[i2][i4]&&mp[i2][i5]&&mp[i3][i4]&&mp[i3][i5]&&mp[i4][i5];
		bool f2=mp[i1][i2]||mp[i1][i3]||mp[i1][i4]||mp[i1][i5]||mp[i2][i3]||mp[i2][i4]||mp[i2][i5]||mp[i3][i4]||mp[i3][i5]||mp[i4][i5];
		if(f1==1||f2==0){
			printf("%d %d %d %d %d\n",i1,i2,i3,i4,i5);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}