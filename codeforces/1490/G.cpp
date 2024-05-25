#include <bits/stdc++.h>
#define ull uint64_t
#define ll long long int
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define vi vector<int>
#define ff first
#define ss second
#define mx5 100005
#define mx52 200005
#define mx6 1000005
#define mod 1000000007
#define smod 998244353
#define nfs                     \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x)
{
  int f = 0;
  cerr << '{';
  for (auto &i : x)
    cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
  __print(t);
  if (sizeof...(v))
    cerr << ", ";
  _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)             \
  cerr << "[" << #x << "] = ["; \
  _print(x)
#else
#define debug(x...)
#endif

template <typename T>
bool MinPlace(T &a, const T &b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}

template <typename T>
bool MaxPlace(T &a, const T &b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}

template <typename S, typename T>
ostream &operator<<(ostream &out, const pair<S, T> &p)
{
  out << "{" << p.ff << ", " << p.ss << "}";
  return out;
}

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v)
{
  out << "[";
  for (int i = 0; i < (int)v.size(); i++)
  {
    out << v[i];
    if (i != (int)v.size() - 1)
      out << ", ";
  }
  out << "]";
  return out;
}

void solve()
{
  int n, m;
  ll maxm = 0;
  cin >> n >> m;
  vector<ll> a(n);
  vector<pair<ll, int>> part;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    if (i)
      a[i] += a[i - 1];
    MaxPlace(maxm, a[i]);
    part.pb({a[i], i});
  }
  sort(part.begin(), part.end());
  for (int i = n - 2; i >= 0; i--)
    MinPlace(part[i].ss, part[i + 1].ss);
  for (int i = 0; i < m; i++)
  {
    ll x;
    cin >> x;
    if (a.back() <= 0 and maxm < x)
    {
      cout << "-1 ";
      continue;
    }
    ll ans = 0;
    if (x > maxm)
    {
      ll rounds = (x - maxm + a.back() - 1) / a.back();
      ans += rounds * n;
      x -= rounds * a.back();
    }
    ans += lower_bound(part.begin(), part.end(), pair<ll, int>(x, -1))->second;
    cout << ans << " ";
  }
  cout << "\n";
}

int main()
{
  nfs;
  int t;
  cin >> t;
  while (t--)
    solve();
}