// LUOGU_RID: 158408720
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,j,a[114],b[114],v[112][114],k,ex[114][114];
void wrong()
{
	puts("NO");exit(0);
}
signed main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	cin>>v[i][j],b[j]=v[1][j];
	a[1]=0;
	for(i=2;i<=n;i++)
	{
		int plus=-1,minus=1;
		for(j=1;j<=m;j++)
		{
			if(v[i][j]>=v[1][j]) if(plus!=-1&&plus!=v[i][j]-v[1][j]) wrong(); else plus=v[i][j]-v[1][j];
			else if(minus!=1&&minus!=v[i][j]-v[1][j]) wrong(); else minus=v[i][j]-v[1][j];
			if(minus!=1) a[i]=minus;
			if(plus!=-1) a[i]=plus;
			if(plus!=-1&&minus!=1) k=plus-minus;
		}
	}
	if(!k) k=1145141919810;
	for(i=1;i<=n;i++) a[i]=(a[i]+k)%k;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			ex[i][j]=(a[i]+b[j])%k;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(ex[i][j]!=v[i][j]) wrong();
	puts("YES");
	cout<<k<<endl;
	for(i=1;i<=n;i++) cout<<a[i]<<" ";cout<<endl;
	for(j=1;j<=m;j++) cout<<b[j]<<" ";
	return 0;
}