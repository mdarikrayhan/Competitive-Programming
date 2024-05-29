#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,bo;
int main()
{
	cin>>n>>m;
	for(long long i=1,x,y;i<=m;i++)
	{
		cin>>x>>y;
		sum+=y;
		bo+=x*y%n;
	}
	printf("%d",(bo%n==(n-1)*n/2%n||sum<n)?1:-1);
}