#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;

int a[maxn],b[maxn],c[maxn];

bool cmp(int x,int y)
{
	return x<y;
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		int n;cin>>n;
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1,cmp);
		int m=0;
		for (int i=1;i<=n;i++)
			if (a[i]!=a[i-1])
				c[++m]=a[i];
		for (int i=1;i<=m;i++)
		{
			b[i]=c[i]-c[i-1];
		}
		int j=0;
		while (b[j+1]==1&&j<=m){j++;}
		if (j==m) j++;
		if (j%2==0)
			printf("Alice\n");
		else
			printf("Bob\n");
		for (int i=0;i<=n;i++)
			a[i]=b[i]=0;
	}
	
}
