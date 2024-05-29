// LUOGU_RID: 158288003
//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 1010
using namespace std;
ll n,k,ans[N][N],mxlen[N][N];
pair<ll,ll> nxt[N][N];
char s[N][N];
int main(){
	ll T,i,j;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%s",&s[i]);
			for(j=0;j<n;j++)
			{
				ans[i][j]=0;
				mxlen[i][j]=0;
				nxt[i][j]=(s[i][j]=='1')?make_pair(i,j):make_pair((ll)INF,(ll)INF);
			}
		}
		for(i=n-1;i>0;i--)
		{
			for(j=n-1;j>0;j--)
			{
				nxt[i-1][j-1]=min(nxt[i-1][j-1],nxt[i][j]);
			}
		}
		bool isok=true;
		for(i=0;i<(n-k+1);i++)
		{
			for(j=0;j<(n-k+1);j++)
			{
				if(i)
				{
					mxlen[i][j]=max(mxlen[i][j],mxlen[i-1][j]);
				}
				if(j)
				{
					mxlen[i][j]=max(mxlen[i][j],mxlen[i][j-1]);
				}
				if(i+mxlen[i][j]>=n||j+mxlen[i][j]>=n)
				{
					isok=false;
					break;
				}
				pair<ll,ll> upd=nxt[i+mxlen[i][j]][j+mxlen[i][j]];
				if(upd.F>=n)
				{
					isok=false;
					break;
				}
				ans[upd.F][upd.S]=1;
				mxlen[i][j]=upd.F-i;
			}
			if(!isok)
			{
				break;
			}
		}
		if(!isok)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				putchar(ans[i][j]^49);
			}
			puts("");
		}
	}
	return 0;
}