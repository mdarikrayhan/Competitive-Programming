#include<bits/stdc++.h>
using namespace std;
int main()
{int n;
 cin>>n;
 int a[n];
 cin>>a[0];
 int ans=a[0];
 for(int i=1;i<n;i++)
	{cin>>a[i];
	 ans+=abs(a[i-1]-a[i])+1;
	}
	cout<<ans+n;
	return 0;	
}