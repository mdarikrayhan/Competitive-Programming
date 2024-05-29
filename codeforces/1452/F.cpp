// LUOGU_RID: 157353490
#include<bits/stdc++.h>
using namespace std;

constexpr int maxn=30;

long long cnt[maxn];

int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	int n,q,i,op,x;
	long long k;
	cin>>n>>q;
	for(i=0;i<n;i++) cin>>cnt[i];
	while(q--)
	{
		cin>>op>>x;
		if(op==1) cin>>cnt[x];
		else
		{
			long long rem=0,ans=0;
			cin>>k;
			for(i=0;i<=x;i++) k-=cnt[i],rem+=((1<<i)-1)*cnt[i];
			for(i=x+1;i<n&&k>0;i++)
			{
				long long use=min(k>>(i-x),cnt[i]);
				k-=use<<(i-x);
				ans+=((1<<(i-x))-1)*use;
				rem+=((1<<x)-1)*use<<(i-x);
				if(use<cnt[i])
				{
					while(k>rem)
					{
						ans++;
						i--;
						if(k>=1<<(i-x))
						{
							k-=1<<(i-x);
							ans+=(1<<(i-x))-1;
							rem+=((1<<x)-1)<<(i-x);
						}
					}
					ans+=k;
					k=0;
					break;
				}
			}
			if(k>0&&k<=rem) ans+=k,k=0;
			cout<<(k>0?-1:ans)<<'\n';
		}
	}
	return 0;
}
