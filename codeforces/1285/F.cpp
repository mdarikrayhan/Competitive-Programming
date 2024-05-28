// LUOGU_RID: 160168406
#include <bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;

template<typename T> inline void read(T &x)
{
	x = 0;
	T f = 1;char ch = getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		{
			f = -1,ch = getchar();
			break;
		}
		ch = getchar();
	}
	while(ch>='0'&&ch<='9')
		x = (x<<3)+(x<<1)+ch-48,ch = getchar();
	x*=f;
}
template<typename T = int> inline T read()
{
	T x;read(x);return x;
}
template<typename T> void write(T x)
{
    if(x<0) x = -x,putchar('-');
    if(x>9) write(x/10);
    putchar(x%10+48);
}
template<typename T> inline void writen(T x)
{
    write(x);
    putchar(10);
}
const int N = 1e5+5;
int n,a[N],w[N],id[N];
inline bool cmp(int x,int y){return w[x]>w[y];}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	read(n);
	for(int i = 1;i<=n;i++)
		read(a[i]),id[i] = i;
	vector<int> p;
	mt19937 rnd(19260817);
	while(p.size()<=50) p.push_back(rnd()%n+1);
	for(int i = 1;i<=n;i++)
	{
		w[i] = 0;
		for(auto j:p) w[i] = max(w[i],a[i]*a[j]/gcd(a[i],a[j]));
	}
	sort(id+1,id+n+1,cmp);
	int ans = 0;
	for(int i = 1;i<=min(n,2000ll);i++)
		for(int j = 1;j<=min(n,2000ll);j++)
			ans = max(ans,a[id[i]]*a[id[j]]/gcd(a[id[i]],a[id[j]]));
	for(int i = 1;i<=min(n,20ll);i++)
		for(int j = 1;j<=n;j++)
			ans = max(ans,a[id[i]]*a[id[j]]/gcd(a[id[i]],a[id[j]]));
	write(ans);
	return 0;
}
