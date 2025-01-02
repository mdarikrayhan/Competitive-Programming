#include <bits/stdc++.h>

#define N 1000005
#define mod 1000000007
#define hf ((mod+1)/2)
#define num vector<int>

typedef long long ll;

using namespace std;

int n,a[N];

num cmp(num a,num b)
{
	ll sm=0;
	for(int i=1;i<=n;++i)
	{
		sm+=a[i]-b[i];sm*=2;
		if(abs(sm)>20000000000ll)return sm>0?a:b;
	}
	return sm>0?a:b;
}
num calc(int k)
{
	num ans;ans.resize(n+1);
	for(int i=1;i<=n;++i)ans[i]+=abs(a[min(i,k-1)]-a[max(n-i+1,k)]);
	ans[n]+=abs(a[k-1]-a[k]);
	return ans;
}
num sol()
{
	int ax=-1;
	num ans;ans.resize(n+1);
	for(int k=n;k>1;--k)
		if(a[k]-a[k-1]>ax*2)
		{
			ans=cmp(ans,calc(k));
			ax=a[k]-a[k-1];
		}
	return ans;
}

int main()
{
	int i,T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)scanf("%d",&a[i]);
		sort(a+1,a+n+1);auto ans=sol();
		reverse(a+1,a+n+1);for(i=1;i<=n;++i)a[i]=-a[i];
		ans=cmp(ans,sol());
		ll ml=1,o=0;
		for(i=1;i<=n;++i)
		{
			ml=ml*hf%mod;
			(o+=ml*ans[i])%=mod;
		}
		printf("%lld\n",(o+mod)%mod);
	}
	return 0;
}
