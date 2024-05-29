#include<bits/stdc++.h>
using namespace std;
int n,x[1100001],sum[1100001],dp[1100001],cnt=0;
char s[1100001];
bool none(int l,int r){return l>r||sum[l-1]==sum[r];}
void update(int &a,int b){if(a<b)a=b;}
bool check(int t)
{
	memset(dp,0,sizeof dp);
	for(int i=0;i<cnt;i++)
	{
		if(none(dp[i]+1,x[i]-t-1))update(dp[i+1],x[i]);
		if(none(dp[i]+1,x[i]-1))update(dp[i+1],x[i]+t);
		if(i&&none(dp[i-1]+1,x[i]-t-1))update(dp[i+1],x[i-1]+t);
	}
	return none(dp[cnt]+1,n);
}
int main()
{
	scanf("%d%s",&n,s+1);
	int pos=-1;
	for(int i=1;i<=n;i++)
		if(s[i]=='P')pos=x[cnt++]=i;
	if(cnt==1)
	{
		int L=0,R=0,lpos=-1,rpos=-1;;
		for(int i=pos-1;i;i--)
			if(s[i]=='*')L++,lpos=i;
		for(int i=pos+1;i<=n;i++)
			if(s[i]=='*')R++,rpos=i;
		if(L!=R)printf("%d %d\n",max(L,R),L>R?pos-lpos:rpos-pos);
		else printf("%d %d\n",L,min(pos-lpos,rpos-pos));
		return 0;
	}
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+(s[i]=='*');
	int l=0,r=n,ans=n;
	while(l<=r)
	{
		int m=(l+r)/2;
		if(check(m))r=m-1,ans=m;
		else l=m+1;
	}
	printf("%d %d\n",sum[n],ans);
}
