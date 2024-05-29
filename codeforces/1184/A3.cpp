// LUOGU_RID: 157480153
#include<bits/stdc++.h>
#define int long long
using namespace std;
int pw(int a,int b,int mod)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int n,m;
int a[100005];
int f[100005];
bool isprime[1000005];
int prime[100005]={0,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293};
int cnt=61;
int V=1e6;
int rand(int l,int r)
{
	return 1ll*rand()*rand()%(r-l+1)+l;
}
int getval(int n,int x,int mod)
{
	int t=1,s=0;
	for(int i=0;i<n;i++)
	{
		(s+=f[i]*t%mod+mod)%=mod;
		t=t*x%mod;
	}
	return s;
}
void work(int d)
{
	for(int i=0;i<d;i++)
		f[i]=0;
	for(int i=0;i<n;i++)
		f[i%d]+=a[i];
	for(int mod=d+1;mod<=V;mod+=d)
	{
		//mod=281;
		if(mod<m||!isprime[mod])
			continue;
		int zs=(mod-1)/d;
		for(;;)
		{
			int r=rand(2,mod-1);
			if(pw(r,zs,mod)==1)
				continue;
			//r=90
			r=pw(r,zs,mod);
			int x=r;
			for(int i=1;i<=d;i++)
			{
				//x=153
//				assert(d!=5||x!=153||mod!=281);
				if(!getval(d,x,mod))
				{
					cout<<mod<<" "<<x<<"\n";
					exit(0);
				}
				x=x*r%mod;
			} 
			break;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	srand(time(0));
	for(int i=2;i<=V;i++)
		isprime[i]=1;
	for(int i=2;i<=V;i++)
		if(isprime[i])
			for(int j=i*2;j<=V;j+=i)
				isprime[j]=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		char x;
		cin>>x;
		a[i]+=x;
	}
	for(int i=0;i<n;i++)
	{
		char x;
		cin>>x;
		a[i]-=x;
	}
	for(int i=1;i<=cnt;i++)
		work(prime[i]);
}