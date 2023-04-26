#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int t,n,A[N],s;
pair<int,int>p[N];
signed main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>p[i].first,p[i].second=i;
		sort(p+1,p+n+1),s=0;
		for(int i=1;i<=n;i++)
			A[p[i].second]=pow(-1,i&1)*(n-i+2)/2,s+=2*abs(A[p[i].second])*p[i].first;
		cout<<s<<'\n';
		for(int i=0;i<=n;i++)
			cout<<A[i]<<' ';
		cout<<'\n';
	}
	return 0;}