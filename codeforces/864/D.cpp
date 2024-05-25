#include<bits/stdc++.h>
using namespace std;
const int Maxn=int(2e5);

int n,tot,a[Maxn+5];
int vis[Maxn+5],res[Maxn+5];
vector<int> v;

int main()
{
	scanf("%d",&n);
	for(register int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		vis[a[i]]++;
	}
	for(register int i=1;i<=n;++i)
		if(!vis[i]) v.push_back(i);
	printf("%d\n",v.size());
	for(register int i=1;i<=n;++i)
	{
		if(vis[a[i]]>1 && v[tot]<a[i])
		{
			printf("%d ",v[tot]);
			tot++,vis[a[i]]--;
		}
		else if(res[a[i]])
		{
			printf("%d ",v[tot]);
			++tot;
		}
		else
		{
			res[a[i]]++;
			printf("%d ",a[i]);
		}
	}
	return 0;
}
  	   	 		 		 	  	  			 		 	 		