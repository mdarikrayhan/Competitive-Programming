// LUOGU_RID: 158872707
#include<bits/stdc++.h>
using namespace std;
long long a,b;
int main()
{
	cin>>a>>b;
	long long sum=a+b+1;
	for(int i=sum-a;i<=sum;i++)
	{
		cout<<i<<" ";
	}
	for(int i=sum-a-1;i>=1;i--)
	{
		cout<<i<<" ";
	}
	return 0;
}