// LUOGU_RID: 160539171
#include<bits/stdc++.h>
#define ll long long
//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
using namespace std;
const int maxn=1001;
int n,S,f[maxn][maxn],g[maxn];
struct node{int l,r,w,s,v;}a[maxn];
bool cmp(node X,node Y){return (X.r!=Y.r)?(X.r<Y.r):(X.l>Y.l);}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%d%d",&n,&S);
	for(int i=1;i<=n;i++)
	{
		int l,r;
		scanf("%d%d%d%d%d",&a[i].l,&a[i].r,&a[i].w,&a[i].s,&a[i].v);
	}
	sort(a+1,a+n+1,cmp);
	n++,a[n].l=0,a[n].r=(n<<1)-1,a[n].w=0,a[n].s=S,a[n].v=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i].w;j<=S;j++)
		{
			memset(g,0,sizeof(g[0])*(a[i].r+1));
			int loc=0;
			for(int k=1;k<i;k++)
			{
				while(a[k].r>loc) g[loc+1]=g[loc],loc++;
				if(a[k].l>=a[i].l) g[a[k].r]=max(g[a[k].r],g[a[k].l]+f[k][min(a[i].s,j-a[i].w)]);
			}
			f[i][j]=g[loc]+a[i].v;
		}
	}
	printf("%d",f[n][S]);
	return 0;
}