// LUOGU_RID: 159864893
#pragma GCC optimize(3)
#pragma GCC optimize(2, "Ofast", "inline")
#include<bits/stdc++.h>
#define N 5010
#define int long long
using namespace std;
int n,k,x;
int a[N],ans;
int f[N][N];
int q[N];
int head,tail;
signed main()
{
	cin>>n>>k>>x;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	memset(f,-0x3f,sizeof(f));
	if(n/k>x)
	{
		cout<<-1;
		return 0;
	}
	f[0][0]=0;
	for(int j=1;j<=x;j++)
	{
		head=1,tail=0;
		q[++tail]=0;
		for(int i=1;i<=n;i++)
		{
			while(head<=tail&&q[head]+k<i)
				head++;
			f[i][j]=f[q[head]][j-1]+a[i];
			while(head<=tail&&f[i][j-1]>=f[q[tail]][j-1])
				tail--;
			q[++tail]=i;
		}
	}
	for(int i=n-k+1;i<=n;i++)
		ans=max(ans,f[i][x]);
	cout<<ans;
	return 0;
}
