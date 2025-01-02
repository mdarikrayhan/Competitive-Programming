// LUOGU_RID: 160508728
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e5+5,B=635;
int n,a[N],lst[B+5],nxt[N],p[B+5];
ll f[N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--) if(a[i]<=B) nxt[i]=p[a[i]],p[a[i]]=i;
	memset(f,0x3f,sizeof(f)),f[1]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=max(i-B,1);j<i;j++) f[i]=min(f[i],f[j]+1ll*min(a[i],a[j])*(i-j)*(i-j));
		for(int k=1,j;k<=B;k++) if(j=lst[k]) f[i]=min(f[i],f[j]+1ll*min(k,a[i])*(i-j)*(i-j));
		for(int k=1,j;k<=B;k++) if(j=p[k]) f[j]=min(f[j],f[i]+1ll*min(k,a[i])*(j-i)*(j-i));
		if(a[i]<=B) p[a[i]]=nxt[i],lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++) cout<<f[i]<<" ";
	return 0;
}