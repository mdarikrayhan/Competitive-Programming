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
template <typename T = ll>
class BIT
{
  int n;
  vector<T> v;

public:
  BIT(int n) : n(n)
  {
    v.resize(n + 1, 0);
  }

  void inc(int pos, T delta = 1)
  {
    for (int i = pos; i <= n; i += i & (-i))
      v[i] += delta;
  }

  void dec(int pos, T delta = 1)
  {
    inc(pos, -delta);
  }

  T qry(int r)
  {
    T ret = 0;
    for (int i = r; i; i = i & (i - 1))
      ret += v[i];
    return ret;
  }

  T rangeQry(int l, int r)
  {
    return qry(r) - qry(l - 1);
  }

  void upd(int pos, T val)
  {
    inc(pos, val - pointQry(pos));
  }

  T pointQry(int pos)
  {
    return qry(pos) - qry(pos - 1);
  }
};

using bit = BIT<int>;
void solve()
{
  int n;
  cin >> n;
  bit end(2 * n);
  vi a(n + 1), b(n + 1), c(n + 1);
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    if (a[i] > i)
    {
      b[i] = a[i];
      end.inc(b[i] + n);
    }
    else if (a[i] < i)
      b[i] = a[i] + n;
    else
    {
      b[i] = a[i];
      end.inc(i);
      end.inc(n + i);
    }
  }
  for (int i = n; i; i--)
  {
    if (i == b[i])
    {
      c[a[i]] = 0;
      continue;
    }
    c[a[i]] = b[i] - i - end.rangeQry(i, b[i]);
    debug(i, a[i], b[i], c[a[i]]);
    end.inc(b[i]);
  }
  for (int i = 1; i <= n; i++)
    cout << c[i] << " ";
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