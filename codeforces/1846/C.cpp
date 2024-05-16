#include<bits/stdc++.h>
#include<cstdio>
#include<queue>
#define pb emplace_back
#define MAXN 200010
#define int long long
#define ull unsigned long long
#define eps =1e-10
using namespace std;
using ll = __int128;
const int INF=0x3f3f3f3f;
int ans=1;
void solve()	
{
	int n,m,h;
	int res=0,sum=0,ans=1;
	cin>>n>>m>>h;
	int a[m+5];memset(a,0,sizeof(a));
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+m);
	int t1=h,tt=0;
	for(int i=1;i<=m;i++)
	{
		 if(t1>=a[i])
		 {
		 	t1-=a[i];tt+=a[i];
		 	res++;sum+=tt;
		 }
	}
	for(int i=1;i<=n-1;i++)
	{
		t1=h;
		for(int j=1;j<=m;j++)
		{
			cin>>a[j];
		}sort(a+1,a+1+m);
		
		int sum1=0,res1=0,tt=0;
		for(int j=1;j<=m;j++)
		{
		 	if(t1>=a[j])
		 	{
		 		t1-=a[j];tt+=a[j];
		 		res1++;sum1=sum1+tt;
		 	}else break;
		}
		if(res1>res)ans++;
		if(res1==res&&sum1<sum)ans++;
	}
	cout<<ans<<endl; 
}
signed main()
{
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
}
