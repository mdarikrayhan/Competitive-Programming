// LUOGU_RID: 158898270
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,v[1000005],p[1000005],cnt;
void prime()
{
    for(int i=2;i<=1000000;i++)
	{
        if(!v[i])
		{
			p[++cnt]=i;
		}
        for(int j=1;p[j]*i<=1000000&&j<=cnt;j++)
		{
            v[p[j]*i]=1;
            if(i%p[j]==0)
			{
				break;
			}
        }
    }
}
int reverse(int n)
{
	int ans=0;
	while(n)
	{
		ans=ans*10+n%10;
		n/=10;
	}
	return ans;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	prime();
	cnt=0;
	for(int i=2;i<=1000000;i++)
	{
		int tgx=reverse(i);
		if(tgx==i)
		{
			continue;
		}
		if(v[i]==0&&v[tgx]==0)
		{
			cnt++;
		}
		if(cnt==n)
		{
			cout<<i;
			return 0;
		}
	}
	return 0;
}