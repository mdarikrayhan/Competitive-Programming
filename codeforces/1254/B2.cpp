#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ld long double
#define pb push_back
#define endl '\n'
#define all(v) v.begin(), v.end()
#define all1(v) v.begin() + 1, v.end()
#define rall(v) v.rbegin(), v.rend()
#define rall1(v) v.rbegin(), v.rend()-1
#define fr(m,n,k) for(int m=n;m<=k;m++)
#define frr(m,n,k) for(int m=n;m>=k;m--)
#define yes cout << "YES"
#define no cout << "NO"
#define yesm cout << "Yes"
#define nom cout << "No"
#define inf 1e18
#define ext {cout << -1; return;}
#define zxt {cout << 0; return;}
#define noxt {no;return;}
#define yesxt {yes;return;}
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define fill(x,s) memset(x, s, sizeof(x));
#define lb lower_bound
#define ub upper_bound
#define pi pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define vpi vector<pi>
#define mii map<int,int>
#define si set<int>
#define fi first
#define se second
#define sz size()
#define el cout<<endl

int mod = 1e9 + 7;
// int mod = 998244353;

int ft(int n) {int ans = 1; for (int i = 1; i <= n; ++i) {ans = ans * i;} return ans;}
int binpow(int x, int y) {if (y == 0) return 1; int z = 1; while (y) {  if (y & 1) z = z * x % mod; x = x * x % mod; y >>= 1;} return z;}
int inv(int x) {return binpow(x, mod - 2);}
int bintoint(string s) {reverse(all(s)); int xx = 0; int m = 1; int z = s.sz; fr(j, 0, z) {xx += (s[j] == '1' ? m : 0); m <<= 1;} return xx;}
string inttobin(int x) {if (x == 0) return "0"; string s; while (x) {s += (x & 1) + '0'; x >>= 1;} reverse(all(s)); return s;}
string ads(string s, string p) {if (s.sz > p.sz) swap(s, p); int n = s.sz, m = p.sz; reverse(all(s)); reverse(all(p)); int tm = 0; string st; fr(i, 0, n - 1) {tm = s[i] - '0' + p[i] - '0' + tm; st += '0' + tm % 10; tm /= 10;} fr(i, n, m - 1) {tm = p[i] - '0' + tm; st += '0' + tm % 10; tm /= 10;} if (tm != 0) {st += '0' + tm % 10;} reverse(all(st)); return st;}

bool id, id1, id2;
int n, m, k, l, r, a, b, c, d, e, x, y, z, i, j, q, t, o;
int mi = inf, ma, sum, ans, num, cnt;
string s, p;

const int N = 1e5 + 5;
void solve() {
	cin >> n; vi v(n + 1), pre(n + 1);
	fr(i, 1, n) cin >> v[i], pre[i] = pre[i - 1] + v[i];

	mi = inf; sum = pre[n];
	auto ch = [&](int i) {
		int need = 0;
		fr(z, 1, n) {
			l = pre[z] / i * i; // lower
			r = l + i;
			need += min(abs(pre[z] - l), abs(r - pre[z]));
		}
		// cout << i << " " << need; el;
		mi = min(mi, need);
	};


	int p = 2; x = sum;
	while (p * p <= x) {
		if (x % p == 0) {
			ch(p);
			while (x % p == 0) x /= p;
		}
		p++;
	}
	if (x != 1) ch(x);
	cout << (mi == inf ? -1 : mi);
}
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
	int T = 1;
	// cin >> T;
	for (; T--;) {
		cout << fixed << setprecision(5); solve();
		if (T) cout << endl;
	} return 0;
}
// Tc, angka kecil), No Overthink(trivial tp modified),
// Check Kasus Khusus(1,2,1e18), ganti jd bentuk lain (2 case or etc)
// bedah 1 1 variable yg bisa dicari, cari dari jwbn ke ques

// Sorting : Iterate Greedy (pake data struct) / dp / binser
// Graphs / Tree : DFS / adj / dis[a][b] != dis[a][c] + dis[c][b] / indegree
// Yang keliatan kyk dp : bisa jd brute force doang
// Data Structure : BIT / DSU / Segtree, SparseT / dequeue
// Compression, Line Sweep
// Parity (2 or 3, mod 4..) klo dilakuin 2 kali jadi sama aja -> parity mod 2

/*
brute force, greedy, pref sum, 2pointer, gcd/lcm, even/odd
min/max, binser, bfs/dfs, iterate, multiple/divisor

bipartite graph,bitmasking, sliding window, konstanta
divconquer, djikstra, stack(prev and next smaller)
prefix difference
*/

// tools :
//__lg(x),__builtinpopcount,nextpermutation(), is_sorted / alpha / digit,