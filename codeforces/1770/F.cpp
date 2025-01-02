// Hydro submission #66554e395fc569b8dac6ecf2@1716866669121
#include<bits/stdc++.h>
using namespace std;
long long s,all=(1<<20)-1,n,X,Y,x;
int main()
{
	scanf("%lld%lld%lld",&n,&X,&Y);
	if(!(n&1)){cout<<0;return 0;}
	for(int i=0;i<=19;i++)
	{
		x=(1<<i);
		for(int j=0;j<=all;j++)
		{
			if((!(j&(1<<i)))||((j&Y)!=j))continue;
			if(((X-x)&(n*j-x))==(X-x))s^=x;
		}
	}
	cout<<s;
  return 0;
}