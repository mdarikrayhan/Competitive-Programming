#include<bits/stdc++.h>
using namespace std;
int t,n;
long long ans;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=1;
		while(n)
		{
			int k=n%10;
			n/=10;
			ans*=1ll*(k+2)*(k+1)/2;
		}
		cout<<ans<<endl;
	}
	return 0;
}
