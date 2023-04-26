#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL k,m=1e9+7,n,s,t,a[200004],f[400005]={1};
LL P(LL x,LL y)
{
	for(LL i=m-2;i;i>>=1)
	{
		if(i&1)x=x*y%m;
		y=y*y%m;
	}
	return x;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int i=1;i<=400000;i++)f[i]=f[i-1]*i%m;
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>0)s=(s+P(f[i+a[i]],f[a[i]-1]*f[i+1]%m))%m;
	}
	cout<<s;
}