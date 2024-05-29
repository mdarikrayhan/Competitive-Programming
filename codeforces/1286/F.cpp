// LUOGU_RID: 121447272
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,f[1201001],a[100100],b[100100];
int sl[1201001],sr[1201001];
void get(long long *s,int l,int r)
{
	int m=1;s[1]=0;
	static long long pos[1201001],neg[1201001];
	for  (int i=l;i<=r;i++,m<<=1)
	{
		for (int j=1;j<=m;j++)pos[j]=s[j]+b[i],neg[j]=s[j]-b[i];
		for (int x=1,y=1,k=1;k<=(m<<1);k++)
		if (x>m) s[k]=neg[y++];
		else if (y>m) s[k]=pos[x++];
		else if (pos[x]>=neg[y]) s[k]=neg[y++];
		else s[k]=pos[x++];
	}
}
bool check(int x)
{
	int sum=0,m=0;
	for (int i=1;i<=n;i++)
	if (x>>i-1&1)sum+=a[i],b[++m]=a[i];
	if (sum-(m-1)&1) return 0;
	get(sl,1,m/2),get(sr,m/2+1,m);
	int ll=1<<(m/2),rr=(1<<(m-m/2)),cnt=1+(abs(sum)<m)*2;
	for (int i=rr,j=1;i>=1;i--)
	{
		while(j<=ll&&sl[j]+sr[i]<=-m)j++;
		for (int k=j;k<=ll&&cnt&&sl[k]+sr[i]<m;k++) cnt--;
	}
	return !cnt;
}
signed main()
{
	cin>>n;
	int nn=0;
	for (int i=1;i<=n;i++)
		cin>>a[i],a[i]&&(a[++nn]=a[i]);
	n=nn;
	nn=(1<<n)-1;
	for (int i=1;i<=nn;i++)
	if(!f[i]&&check(i)){
		f[i]=1;int t=nn^i;
		for (int j=t;j;--j&=t) f[i|j]=max(f[i|j],f[j]+1);
	}
	cout<<n-f[nn]<<endl;
}