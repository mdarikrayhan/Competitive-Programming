#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define faster ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0)
double n,m,a[502],ans;
int u,v,w; 
int main()
{
	faster;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		ans=max(ans,(a[u]+a[v])/w);
	}
	printf("%.15lf",ans);
    return 0;
}
  			 				 	 		 			     		