#include<bits/stdc++.h>
using namespace std;

constexpr int maxn=510;

char s[maxn],t[maxn];
unsigned dp[maxn];

int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		int n,k,i;
		cin>>n>>k>>s;
		for(i=0;i<n;i++)
		{
			s[i]-='a';
			t[i]=(s[i]==0||s[i]==k-1)?0:s[i]-1;
		}
		memset(dp+1,0xff,n*4);
		auto out=[](unsigned x){cout<<char(x+'a');};
		for(i=0;i<n;i++)
		{
			if(i>=4) out(dp[i]>>24);
			dp[i]<<=8;
			dp[i+1]=min(dp[i+1],dp[i]|t[i]);
			if(i) dp[i+1]=min(dp[i+1],(dp[i]&0xffff0000)|((dp[i]>>8)&0xff)|s[i]<<8);
			if(i+1==n) continue;
			dp[i]<<=8;
			dp[i+2]=min(dp[i+2],dp[i]|t[i+1]<<8|s[i]);
			if(i) dp[i+2]=min(dp[i+2],(dp[i]&0xff000000)|((dp[i]>>8)&0xff00)|s[i+1]<<16|s[i]);
		}
		for(i=min(n-1,3);i>=0;i--) out(dp[n]>>i*8&0xff);
		cout<<'\n';
	}
	return 0;
}
