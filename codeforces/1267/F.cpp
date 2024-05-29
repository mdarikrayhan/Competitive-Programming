#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,m,len[2];
int a[2][maxn],ptr[2];
int deg[maxn];
priority_queue< int,vector<int>,greater<int> > q; 
int main()
{
	scanf("%d%d%d%d",&n,&m,&len[0],&len[1]);
	for(int i=1;i<=len[0];i++)
		scanf("%d",&a[0][i]),deg[a[0][i]]++;
	for(int i=1;i<=len[1];i++)
		scanf("%d",&a[1][i]),deg[a[1][i]]++;
	if(len[0]>=m||len[1]>=n){puts("No");return 0;}
	ptr[0]=ptr[1]=1;
	puts("Yes");
	deg[a[0][len[0]]]=deg[a[1][len[1]]]=1e9;
	for(int i=1;i<=n+m;i++)
		if(!deg[i])q.push(i);
	while(!q.empty())
	{
		int u=q.top(),v;
		q.pop();
		int p=u<=n;
		printf("%d %d\n",u,v=a[p][ptr[p]]);
		deg[v]--;
		ptr[p]=min(ptr[p]+1,len[p]);
		if(!deg[v])q.push(v);
	}
	printf("%d %d\n",a[0][len[0]],a[1][len[1]]);
}