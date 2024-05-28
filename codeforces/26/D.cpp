/// ITNOG
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define F first
#define S second
#define pb push_back
#define ppb pop_back
#define fast_io ios::sync_with_stdio(false);cin.tie(NULL);
#define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define FOR(i,k,n) for(int i = k; i < n; ++ i)
#define debf cout<<"(0-0)\n";
#define all(x) x.begin(), x.end()
#define dec(x) cout << fixed << setprecision(x);
#define pf push_front
#define ppf pop_front
#define dash " ------- "
#define what(x) cerr << #x << " is " << x << endl;
#define eb emplace_back
//#define int short int
#define int long long
#define sz(s) (int) (s.size())
#define fl cout.flush()

using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <int, pii> pip;
typedef pair <pii, int> ppi;
typedef pair <ll, ll> pll;
typedef unsigned long long ull;
typedef long double ld;

template <class T> using max_heap = priority_queue <T, vector <T>, less <T> >;
template <class T> using min_heap = priority_queue <T, vector <T>, greater <T> >;
//template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int MOD = 1e9 + 7, N = 1e6 + 8, M = 4e6 + 8, SQ = 110, INF = 8e9 + 8, LGN = 20, mod = 998244353, P = 131113;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m, k;

int32_t main(){
  fast_io;
  cin >> n >> m >> k;
  if (n + k < m){
    cout << 0;
    return 0;
  }
  ld ans = 1;
  for (int i = 1; i < k + 2; ++ i){
    ans *= (ld
            )(i + m - k - 1) / (n + i);
  }
  dec (13);
  ld x = 1.0 - ans;
  cout << x;
  return 0;
}

// Yesterday is history
// Tomorrow is a mystery
// but today is a gift
// That is why it is called the present
