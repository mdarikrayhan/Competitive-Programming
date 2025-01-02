// LUOGU_RID: 160596213
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+50;
int n,m,x,y,sum,cnt,dx,dy,ans=1;
char s[5];
map<int,int> mp[N];
signed main()
{
	scanf("%lld %lld %lld %lld %s",&n,&m,&x,&y,(s+1));
	if(s[1]=='U')dx=-1;else dx=1;
	if(s[2]=='L')dy=-1;else dy=1;
	sum=n+m-2;
	if(x==1||y==1||x==n||y==m)
	{
		mp[x][y]=1;
		sum--;
	}
	while(true)
	{
		cnt++;
		if(cnt>=1000000)
		{
			printf("-1\n");
			return 0;
		}
		int res=2e9;
		if(dx==-1)res=min(res,x-1);
		else res=min(res,n-x);
		if(dy==-1)res=min(res,y-1);
		else res=min(res,m-y);
		ans+=res;
		x+=dx*res;y+=dy*res;
		if(x==1)dx=x;
		else if(x==n)dx=-1;
		if(y==1)dy=y;
		else if(y==m)dy=-1;
	 	if(mp[x][y]==0)mp[x][y]=1,sum--;
	 	if(!sum)
	 	{
	 		printf("%lld\n",ans);
	 		return 0;
		}
	}
	return 0; 
}