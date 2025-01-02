#include<bits/stdc++.h>
using namespace std;
const int Maxn=1010;
int n,ans,q;
int a[Maxn];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int t;
			cin>>t;
			if(i==j) a[i]=t,ans+=t*t;
		}
	}
	cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x;
		if(x==3) cout<<ans%2;
		else
		{
			cin>>y;
			ans-=a[y]*a[y];
			a[y]=!a[y];
			ans+=a[y]*a[y];
			ans=(ans+2)%2;
		}
	}
}
	 	 	  		 	   	  		 		  	  	 		