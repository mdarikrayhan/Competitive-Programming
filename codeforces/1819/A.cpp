# include <bits/stdc++.h>
using namespace std;
int a[200010];
bool vis[200010];
int MEX(int n)
{
	for(int i=1;i<=n;i++)
		if(a[i]<=n) vis[a[i]]=1;
	int x=0;
	while(vis[x]) x++;
	memset(vis,0,sizeof(bool)*(n+1));
	return x;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		int t=MEX(n),p=1e9,q=0;
		if(t==n){puts("No");continue;}
		for(int i=1;i<=n;i++)
			if(a[i]==t+1) p=min(p,i),q=max(q,i);
		if(p>q){puts("Yes");continue;}
		for(int i=p;i<=q;i++) a[i]=t;
		puts(MEX(n)==t+1?"Yes":"No");
	}
	return 0;
}
