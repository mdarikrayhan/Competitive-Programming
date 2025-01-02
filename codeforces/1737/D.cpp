#include <bits/stdc++.h>
#define ll long long
#define db long double
#define ull unsigned long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

#define pper(a) cerr << #a << " = " << a << endl;

void per() { cerr << endl; }
template<typename Head, typename... Tail> void per(Head H, Tail... T) { cerr << H << ' '; per(T...); }

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

template<class U, class V> 
ostream& operator<<(ostream& out, const pair<U, V>& a) {
  return out << "(" << a.x << ", " << a.y << ")";
}

template<class U, class V> 
istream& operator>>(istream& in, pair<U, V>& a) {
  return in >> a.x >> a.y;
}

template<typename W, typename T = typename enable_if<!is_same<W, string>::value, typename W::value_type>::type>
ostream& operator<<(ostream& out, const W& v) { out << "{ "; for (const auto& x : v) out << x << ", "; return out << '}'; }

template<class T>
void readArr(T from, T to) {
  for (auto i = from; i != to; ++i) cin >> *i;
}

mt19937 mrand(1337); 
unsigned int myRand32() {
  return mrand() & (unsigned int)(-1);
}
 
unsigned ll myRand64() {
  return ((ull)myRand32() << 32) ^ myRand32();
}

const int mod = 1000000007;

void add(int& a, int b) {
  a += b; if (a >= mod) a -= mod;
}

void dec(int &a, int b) {
  a -= b; if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

const int N = 507;

ll f[N][N];

int main(){
#ifdef LOCAL
	freopen("N_input.txt", "r", stdin);
	//freopen("N_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int a = 0; a < t; ++a) {

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        f[i][j] = 1e18;
      }
      f[i][i] = 0;
    }

    vector<tuple<int, int, int> > ed;

    for (int i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      ed.pb(make_tuple(u - 1, v - 1, w));
      f[u - 1][v - 1] = 1;
      f[v - 1][u - 1] = 1;
    }

    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
        }
      }
    }

    ll ans = 1e18;
    for (auto x : ed) {
      int u = get<0>(x);
      int v = get<1>(x);
      int w = get<2>(x);

//      per(ans, u, v, w);

      ans = min(ans, (ll) w * (f[0][u] + f[n - 1][v] + 1));
      ans = min(ans, (ll) w * (f[0][v] + f[n - 1][u] + 1));

  //    per(ans, u, v, w);

      for (int i = 0; i < n; ++i) {
        ans = min(ans, (ll) w * (f[v][i] + 1 + f[i][0] + f[i][n-1] + 1));
        ans = min(ans, (ll) w * (f[u][i] + 1 + f[i][0] + f[i][n-1] + 1));
      }

    }

    cout << ans << '\n';

  }
}