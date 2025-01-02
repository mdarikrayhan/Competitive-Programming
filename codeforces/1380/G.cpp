// LUOGU_RID: 159337306
#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,invn;
long long a[300005],s[300005],ans[300005];
long long ksm(long long a,long long b)
{
	long long res=1;
	while(b)
	{
		if(b&1)
			res=res*a%mod;
		a=a*a%mod;
		b>>=1; 
	}
	return res;
} 
long long inv(long long x)
{
	return ksm(x,mod-2); 
}
signed main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	invn=inv(n);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;i++)
	{
		s[i]=(s[i-1]+a[i])%mod;
	} 
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j+=i)
		{
			ans[i]=((ans[i]+((j-i-1)/i+1)*(s[min(1ll*j+i-1,n)]-s[j-1]))%mod+mod)%mod;
			
			//cout<<i<<":"<<s[min(1ll*j+i-1,n-i)]-s[j-1]<<endl;
		}
	}
	/*
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<" "; 
	}
	cout<<endl<<endl;
	*/
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]*invn%mod<<" ";
	}
	return 0;
}
//Skadi_H
