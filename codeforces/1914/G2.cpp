#include<bits/stdc++.h>
using namespace std;
 
const int MOD = 998244353;
 
int add(int x, int y)
{
	return (((x + y) % MOD) + MOD) % MOD;
}
 
int mul(int x, int y)
{
	return (x * 1ll * y) % MOD;
}
 
mt19937_64 rnd(98275314);
 
long long gen()
{
	long long x = 0;
	while(x == 0)
		x = rnd();
	return x;
}
 
vector<int> c;
vector<int> g;
 
int process_block(int l, int r)
{
	int ans = 0;
	while(l < r)
	{
		if(g[l] != -1 && g[l] < r)
			l = g[l];
		else
		{
			ans++;
			l++;
		}
	}
	return ans;
}
 
void solve()
{
	int n;
	scanf("%d", &n);
	int size = 0, cnt = 1;
	c.resize(n * 2);
	g.resize(n * 2, -1);
	for(int i = 0; i < 2 * n; i++)
	{
		scanf("%d", &c[i]);
		--c[i];
	}
	
	vector<long long> val(n);
	for(int i = 0; i < n; i++) val[i] = gen();
	
	map<long long, int> last;
	long long cur = 0;
	last[0] = 0;
	for(int i = 0; i < n * 2; i++)
	{
		cur ^= val[c[i]];
		if(cur == 0)
		{
			size++;
			cnt = mul(cnt, process_block(last[0], i + 1));
			last.clear();
		}
		else if(last.count(cur))
		{
			g[last[cur]] = i + 1;
		}
		last[cur] = i + 1;
	}
	
	printf("%d %d\n", size, cnt);
	c.clear();
	g.clear();
}
 
int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) solve();
}