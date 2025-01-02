// LUOGU_RID: 160393188
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=1010;
int prex[3][N*N];
int prey[3][N*N];
int n,m;
vector<int>a[N*N];
int pref[N*N];
int f[N*N];
int pow_m(int a,int x)
{
	int res=1;
	while(x)
	{
		if(x&1)
		{
			res=res*a;
			res%=mod;
		}
		a=a*a%mod;
		x>>=1;
	}
	return res;
}
int inv(int x)
{
	return pow_m(x,mod-2);
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int b;
			cin>>b;
			a[(i-1)*m+j]=vector<int>{b,i,j};
		}
	}
	sort(a+1,a+n*m+1);
	int sx,sy;
	cin>>sx>>sy;
	for(int i=1;i<=n*m;i++)
	{
		int l=0,r=n*m;
		while(l<r)
		{
			int mid=l+r+1>>1;
			if(a[mid][0]<a[i][0])
			l=mid;
			else r=mid-1;
		}
		if(l!=0)
		{
			f[i]+=(prex[2][l]+prey[2][l])%mod;
			f[i]%=mod;
			f[i]+=l*a[i][2]%mod*a[i][2]%mod;
			f[i]%=mod;
			
			f[i]+=l*a[i][1]%mod*a[i][1]%mod;
			f[i]%=mod;
			
			f[i]=(f[i]-2*a[i][1]%mod*prex[1][l]%mod+2*mod)%mod;
			f[i]=(f[i]-2*a[i][2]%mod*prey[1][l]%mod+2*mod)%mod;
			f[i]+=pref[l];
			f[i]%=mod;
		}
		f[i]=f[i]*inv(l)%mod;
		pref[i]=pref[i-1]+f[i];
		pref[i]%=mod;
		
		prex[2][i]=prex[2][i-1]+a[i][1]*a[i][1]%mod;
		prex[2][i]%=mod;
		
		prey[2][i]=prey[2][i-1]+a[i][2]*a[i][2]%mod;
		prey[2][i]%=mod;
		
		prex[1][i]=prex[1][i-1]+a[i][1];
		prex[1][i]%=mod;
		
		prey[1][i]=prey[1][i-1]+a[i][2];
		prey[1][i]%=mod;
		
		if(a[i][1]==sx&&a[i][2]==sy)
		{
			cout<<f[i];
			return 0;
		}
	}
}