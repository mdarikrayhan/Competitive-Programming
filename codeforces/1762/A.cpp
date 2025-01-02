#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,a,s,mn,i,j;
	cin>>t; 
	while(t--)
	{
		cin>>n;s=0,mn=19;
		for(i=1;i<=n;i++)
		{
			cin>>a;s+=a%2;
			for(j=1;(a-a/2)%2==0;j++,a/=2);
			mn=min(mn,j);
		}
		printf("%d\n",s%2?mn:0);
	}
	return 0;
}