// Author: Little09
// Problem: Reunion
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1517F
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// Start Time: 2024-05-29 09:09:52
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define i128 __int128
#define mem(x) memset(x,0,sizeof(x))
#define endl "\n"
#define printYes cout << "Yes\n"
#define printYES cout << "YES\n"
#define printNo cout << "No\n"
#define printNO cout << "NO\n"
#define lowbit(x) ((x)&(-(x)))
#define pb push_back
#define mkp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define rep(i,j,k) for (int i=(j);i<=(k);i++)
#define per(i,j,k) for (int i=(j);i>=(k);i--)
#define pcnt(x) __builtin_popcount(x)
mt19937 rnd(time(0));
template<class T>void chkmin(T&x,T y){x=min(x,y);}
template<class T>void chkmax(T&x,T y){x=max(x,y);}

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
const ll mod=998244353;
//const ll mod=1000000007;

const int N=305;
int n,m,k; 
vector<int>t[N];
ll ksm(ll x,ll y)
{
	ll res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod,y>>=1;
	}
	return res;
}
ll ans;
ll dp[N][N][2],tmp[N][2];
void dfs(int x,int f)
{
	rep(i,0,k) dp[x][i][0]=1,dp[x][i][1]=0;
	for (int v:t[x])
	{
		if (v==f) continue;
		dfs(v,x);
		rep(i,0,k) rep(j,0,1) tmp[i][j]=dp[x][i][j],dp[x][i][j]=0;
		rep(i,0,k) rep(j,0,1) rep(d,-1,1)
		{
			if (i+d>=0&&i+d<=k) 
			{
				if (d==-1||i+d==k) (dp[x][i][j|(d==1)]+=tmp[i][j]*dp[v][i+d][0])%=mod;
				(dp[x][i][j|(d==1)]+=tmp[i][j]*dp[v][i+d][1])%=mod;
			}
		}
	}
}
void solve(int _k)
{
	k=_k;
	dfs(1,0);
	ll res=dp[1][k][0];
	rep(i,0,k) (res+=dp[1][i][1])%=mod;
	res=(ksm(2,n)-res+mod)%mod;
	(ans+=res)%=mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	rep(i,1,n-1)
	{
		int x,y;
		cin >> x >> y;
		t[x].pb(y),t[y].pb(x);
	}
	rep(i,1,n-1) solve(i);
	cout << ans*ksm((mod+1)/2,n)%mod;
	return 0;
}
