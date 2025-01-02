#include<bits/stdc++.h>
#define f(i,x,y) for(int i=x;i<=y;i++)
#define pb push_back
#define ll long long
using namespace std;
const int N=5e5+9;
int n,x,y,fa[N],c,si[N];
ll s;
vector<int>b[N];
struct d
{
	int mn;ll c0,c1;
	d operator+(d u){return mn==u.mn?(d){mn,c0+u.c0,c1+u.c1}:mn<u.mn?*this:u;}
}f[N];
void D(int e)
{
	si[e]=1;
	for(int u:b[e])if(u!=fa[e])fa[u]=e,D(u),si[e]+=si[u];
	c+=si[e]&1;
}
void D1(int e)
{
	f[e]={0,1,0};
	for(int u:b[e])if(u!=fa[e])
	{
		if(si[u]&1^1&&c==n/2)s+=1ll*(n-si[u])*si[u];
		D1(u);
		if(f[e].mn+f[u].mn+c+1==n/2)s+=1ll*f[e].c0*f[u].c1+1ll*f[e].c1*f[u].c0;
		f[e]=f[e]+f[u];
	}
	if(si[e]&1)f[e].c1+=f[e].c0;
	f[e].mn+=si[e]&1?-1:1;
}
signed main()
{
	scanf("%d",&n);
	if(n&1)return puts("0"),0;
	f(i,1,n-1)scanf("%d%d",&x,&y),b[x].pb(y),b[y].pb(x);
	D(1);D1(1);
	cout<<s;
	return 0;
}