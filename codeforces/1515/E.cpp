#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <bitset>
using namespace std;
typedef double db; 
typedef long long ll;
typedef unsigned long long ull;
const int N=1010;
const int LOGN=28;
//const ll  TMD=0;
const ll  INF=2147483647;
int n;
ll  TMD;
ll  f[N];
ll  dp[N][N];

//-------------------------------------------------
//涉及变量:fac[],inv[],TMD,N(上界)
//注意:TMD自取 

ll fac[N],inv[N];

ll pw(ll x,ll p)
{
	if(!p) return 1;
	ll y=pw(x,p>>1);
	y=(y*y)%TMD;
	if(p&1) y=(y*(x%TMD))%TMD;	//典中典:若底数太大要对底数取模! 
	return y;
}

void init()
{
	fac[0]=1;
	for(int i=1;i<N;i++) fac[i]=(fac[i-1]*i)%TMD;
	inv[N-1]=pw(fac[N-1],TMD-2);
 	for(int i=N-2;i>=0;i--) inv[i]=(inv[i+1]*(i+1))%TMD;
}

ll C(int n,int m)
{
	if(n<m||n<0||m<0) return 0;	//特殊情况 
	return fac[n]*inv[m]%TMD*inv[n-m]%TMD; 
}

ll A(int n,int m)
{
	if(n<m||n<0||m<0) return 0;	//特殊情况 
	return fac[n]*inv[n-m]%TMD; 
}

ll INV(ll x)
{
    return pw(x,TMD-2);
}

//-------------------------------------------------


int main()
{
	//freopen("test.in","r",stdin);
	
	scanf("%d%I64d",&n,&TMD);
	init();
	f[1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			int x=j-1,y=i-j;
			f[i]=(f[i]+C(x+y,y))%TMD;
		}
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			for(int k=1;i-k>=j-1;k++)
			{
				dp[i][j]=(dp[i][j]+dp[i-k][j-1]*C(i,i-k)%TMD*f[k])%TMD;
			}
		}
	}
	ll ans=0;
	for(int i=0;i<=(n-1)/2;i++)
	{
		ans=(ans+dp[n-i][i+1])%TMD;
	} 
	printf("%I64d\n",ans);
	
	//fclose(stdin);
	return 0;
}
