// LUOGU_RID: 160520712
#include<bits/stdc++.h>
using namespace std;
long long n,a,d;
long long m=368131125,mod=1e9,x=1.2e10;
int main()
{
    cin>>n>>a>>d;
	printf("%llu %llu\n",m*a%mod*x+1,m*d%mod*x);
	return 0;
}