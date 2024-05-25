#include <bits/stdc++.h>
using namespace std;

#define MULTIINPUT 0

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#define int long long
#define mkp make_pair
#define pii pair<int, int>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define pll pair<long long, long long>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define rep(name, base, limit) for(int name = base; name <= limit; ++name)
#define per(name, base, limit) for(int name = base; name >= limit; --name)
#define lowbit(x) ((x) & -(x))
#define ls(p) ((p) << 1)
#define rs(p) ((p) << 1 | 1)
const int INF = 0x3f3f3f3f;
const long long LNF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

inline long long read()
{
    long long x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
}

int qpow(int x, int y)
{
	int ret = 1;
	while (y)
	{
		if (y & 1) ret = 1ll * ret * x % MOD;
		y >>= 1;
		x = 1ll * x * x % MOD;
	}
	return ret % MOD;
}
int cal(int x)
{
	int ret = 0;
	while (x)
	{
		ret += x & 1;
		x >>= 1;
	}
	return ret;
}
void solve()
{
	int n = read();
	vector<int> a(n + 1);
	vector<int> f(1ll << 20ll), g(1ll << 20ll);
	rep(i, 1, n) a[i] = read(), ++f[a[i]];
	for(int i=0;i<20ll;i++)
		for(int j=(1<<20)-1;j>=0;j--)
			if(!(j&(1<<i))) f[j]=(f[j]+f[j|(1<<i)]) % MOD;
	rep(i, 0, (1ll << 20ll) - 1)
	{
		g[i] = (qpow(2, f[i]) - 1 + MOD) % MOD;
	}
	int ans = 0;
	rep(i, 0, (1ll << 20ll) - 1) ans = (ans + ((((cal(i) & 1) * -2 + 1ll) * g[i] + MOD) % MOD) + MOD) % MOD;
	cout << ans;
}

//left: mid = l + r, pass: r = mid, else: l = mid + 1
//right: mid = l + r + 1, pass: l = mid, else: r = mid - 1

signed main()
{
    //std::ios::sync_with_stdio(false);
    #if MULTIINPUT
    int _t = read();
    while (_t--)
    {
        #endif
        solve();
        #if MULTIINPUT
        putchar('\n');
    }
    #endif
    return 0;
}