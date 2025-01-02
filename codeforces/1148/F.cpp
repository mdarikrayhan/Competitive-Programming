// LUOGU_RID: 160321881
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=3e5+5;
int n,mx[maxn];
ll val[maxn],msk[maxn],ans,sum,s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>val[i]>>msk[i];
		s+=val[i];
		for(int j=0;j<=61;j++)
			if(msk[i]&(1ll<<j)) mx[i]=j;
	}
	for(int j=0;j<=61;j++)
	{
		sum=0;
		for(int i=1;i<=n;i++) if(mx[i]==j) sum+=val[i];
		if((sum<0 && s<0) || (sum>0 && s>0))
		{
			ans|=(1ll<<j);
			for(int i=1;i<=n;i++) if(msk[i]&(1ll<<j)) val[i]=-val[i];
		}
	}
	cout<<ans<<'\n';
	return 0;
}