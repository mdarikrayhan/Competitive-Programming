#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;


#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
 

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
 
 
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
 
//uniform_int_distribution<int> uid(1,111);
const double pi = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
const string pi_string = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

#define ll long long
using ld = long double;
const int INF = 1e9+7;

template <typename T>
vector<int> manacher(int n, const T &s) {
  if (n == 0) {
    return vector<int>();
  }
  vector<int> res(2 * n - 1, 0);
  int l = -1, r = -1;
  for (int z = 0; z < 2 * n - 1; z++) {
    int i = (z + 1) >> 1;
    int j = z >> 1;
    int p = (i >= r ? 0 : min(r - i, res[2 * (l + r) - z]));
    while (j + p + 1 < n && i - p - 1 >= 0) {
      if (!(s[j + p + 1] == s[i - p - 1])) {
        break;
      }
      p++;
    }
    if (j + p > r) {
      l = i - p;
      r = j + p;
    }
    res[z] = p;
  }
  return res;
}
 
template <typename T>
vector<int> manacher(const T &s) {
  return manacher((int) s.size(), s);
}

const ll MOD = 1e9+7;

ll modpow(ll a, ll b) {
	ll result = 1LL;
	while (b) {
		if (b&1)
			result = (result * a)%MOD;
		b = b>>1;
		a = (a*a)%MOD;
	}
	return result;
}

const int N = 3e5+6;
int counter= 0;
int ans[N];

long long fact[N+1];
long long inv_fact[N+1];

ll inverse(ll a) {
	return modpow(a, MOD-2);
}

ll comb(ll n, ll c) {
	if (c == 0) return 1;
	if (c == 1) return n;
	if (n == c) return 1;

	ll result = fact[n];
	result = (result * inv_fact[n-c])%MOD;
	result = (result * inv_fact[c])%MOD;
	return result;
}

struct Compare {
	public:
	bool operator()(int a, int b) {
		return a > b;
	}
};

struct Node {
	public:
	array<int, 2> nxt;
	int cnt = 0;

	Node() {
		nxt[0] = -1;
		nxt[1] = -1;
		cnt = 0;
	}
};



class Segment {
	public:
	vector<int> seg;
	vector<int> lazy;
	int n;

	Segment(int _n) {
		n = _n;
		seg.resize(4*n);
		lazy.resize(4*n);
	}

	void relax(int idx, int l, int r) {
		seg[idx] += lazy[idx];
		if (left != right) {
			lazy[idx*2+1] += lazy[idx];
			lazy[idx*2+2] += lazy[idx];
		}
		lazy[idx] = 0;	
	}

	int getMax(int idx, int l, int r, int left, int right) {
		if (r < left || l > right)
			return 0;
		if (left >= l && right <= r)
			return seg[idx];

		if (lazy[idx]) {
			relax(idx, left, right);
		}



		int m = (left + right)>>1;
		int lleft = 0, rright = 0;
		if (m <= r)
			lleft = getMax(idx*2+1, l, r, left, m);

		if (right >= l)
			rright = getMax(idx*2+2, l, r, m+1, right);
		return max(lleft, rright);
	}

	void addone(int idx, int l, int r, int left, int right) {
		if (r < left || l > right)
			return;

		if (lazy[idx]) {
			relax(idx, left, right);
		}

		if (left >= l && right <= r) {
			lazy[idx]+=1;
			relax(idx, left, right);
			return;
		}

		int m = (left + right)>>1;
		if (m <= r)
			addone(idx*2+1, l, r, left, m);
		if (right >= l)
			addone(idx*2+2, l, r, m+1, right);
		seg[idx] = max(seg[idx*2+1], seg[idx*2+2]);
		return;
	}
	
	void reset() {
		for (int i = 0; i<4*n; ++i) {
			seg[i] = 0;
			lazy[i] = 0;
		}
	}

};


void buildKMP(vector<int>& kmp, string s, int n) {
	
	int j = 1;
	int i = 0;

	while (j < n) {
		if (s[j] == s[i]) {
			i++;
			kmp[j] = i;
			j++;
		} else {
			if (i == 0)
				j++;
			else {
				i = kmp[i-1];
			}
		}
	}

}

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	int count = 0;
	for (int i= 0; i<n; ++i) {
		cin >> v[i];
		count += v[i] == 2;
	}

	if (count%2 == 1) {
		cout << -1 << endl; return;
	}
	int c = 0;
	for (int i = 0; i<n; ++i) {
		c += v[i]==2;
		if (c == count/2) {
			cout << i + 1 << endl;
			return;
		}
	}
	
	

	 
}/***What if input == 0 ? check for extremes low/highs
Don't overcomplicate
Check if you the number turned negative anywhere
Check n==1, edges.
Check for the endl or the lack of it.
Be explicit on X>0 instead of if (X) - This errors sometimes why ?? 

Sometimes you have to hypothesize the end product in mind, just a guess. Then try to look for ways to reach it. Either by start -> end or end -> start.
N % 2 == 1 WONT WORK IF IT IS NEGATIVE :D COMPLEMENT + 1.
**/

void setup() {
	fact[0] = 1;
	for (int i = 1; i<=N; ++i)
		fact[i] = (fact[i-1]*i)%MOD;
	inv_fact[N] = inverse(fact[N]);
	for (int i = N-1; i>=1; --i)
		inv_fact[i] = (inv_fact[i+1] * (i+1))%MOD;
	assert(inv_fact[1] == 1);
}

int main() {
	IOS;
	//setup();
	int TC;
	cin >> TC;

	while (TC--) {
		solve();
	}
}
 


