#include <bits/stdc++.h>
using namespace std;
string s,t;
const long long mod=1000000007;
long long dp[1000001],tdp[1000001];
long long hs1[1000001],hs2[1000001],pw1[1000001],pw2[1000001],bas=33333331,mod1=998244353,mod2=1000000007;
int pos[1000001],tpos[1000001];
int getpos(){
	int i,j,n=t.length(),c=0;
	for(i=0;i<n;i++)
	{
		if(i==n-1||t[i]>t[i+1])
		{
			for(j=i;j>-1&&t[j]==t[i];j--)
			{
				tpos[c]=j;
				c++;
			}
		}
	}
	tpos[c]=n;
	c++;
	for(i=n-2;i>-1;i--)
	{
		if(t[i]<t[i+1])
		{
			for(j=i;j>-1&&t[j]==t[i];j--)
			{
				tpos[c]=j;
				c++;
			}
		}
	}
	return c;
}
bool check(int p1,int p2){
	int i,j,n=s.length(),m=t.length();
	i=0;
	j=0;
	while(1)
	{
		if(i==p1)i++;
		if(j==p2)j++;
		if(i>=n)return 1;
		if(j>=m)return 0;
		if(s[i]<t[j])return 1;
		if(s[i]>t[j])return 0;
		i++;
		j++;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int q,n,m,i,j;
	long long cans;
	cin>>q>>t;
	q--;
	m=getpos();
	for(i=0;i<m;i++)tdp[i]=1;
	for(i=0;i<m;i++)
	{
		pos[i]=tpos[i];
		dp[i]=tdp[i];
		tpos[i]=0;
		tdp[i]=0;
	}
	s=t;
	n=m;
	for(;q>0;q--)
	{
		cin>>t;
		m=getpos();
		j=0;
		cans=0;
		for(i=0;i<m;i++)
		{
			for(;j<n&&check(pos[j],tpos[i]);j++)cans=(cans+dp[j])%mod;
			tdp[i]=cans;
		}
		for(i=0;i<m;i++)
		{
			pos[i]=tpos[i];
			dp[i]=tdp[i];
			tpos[i]=0;
			tdp[i]=0;
		}
		s=t;
		n=m;
	}
	cans=0;
	for(i=0;i<n;i++)cans=(cans+dp[i])%mod;
	cout<<cans<<'\n';
	return 0;
}