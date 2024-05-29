// LUOGU_RID: 155671745
#include <bits/stdc++.h>
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
const int N = 105,mod = 1e6+3;
int n,h,w;
struct node{
	int a[N][N];
	inline void init(int x = 0)
	{
		for(int i = 0;i<N;i++)
			for(int j = 0;j<N;j++)
				a[i][j] = x; 
	}
	inline friend node operator * (node x,node y)
	{
		node res;res.init();
		for(int i = 0;i<=w;i++)
			for(int j = 0;j<=w;j++)
				for(int k = 0;k<=w;k++)
					(res.a[i][j]+=1ll*x.a[i][k]*y.a[k][j]%mod)%=mod;
		return res;
	}
}f,base;
inline node qpow(node x,int y)
{
	node res = x;y--;
//	cout<<y<<'\n';
	while(y)
	{
		if(y&1) res = res*x;
		y>>=1;
		x = x*x; 
	}
	return res;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	read(n),read(w),read(h);
	f.init(),base.init();
	for(int i = 1;i<=w;i++)
		base.a[i-1][i] = h;
//	cout<<"ok\n";
	for(int i = 0;i<=w;i++)
		base.a[i][0] = 1;
	base = qpow(base,n);
	f.a[0][0] = 1;
	f = f*base;
	int ans = 0;
	for(int i = 0;i<=w;i++)
		ans = (ans+f.a[0][i])%mod;
	write(ans);
	return 0;
}
