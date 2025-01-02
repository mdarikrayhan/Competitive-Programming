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

template <int p = mod>
class mint
{
  ll val;

public:
  static ll ring(ll value)
  {
    return ((value % p) + p) % p;
  }

  static ll inv(ll value)
  {
    return (mint(value).inv()).val;
  }

  static ll pow(ll value, int exp)
  {
    return (mint(value).pow(exp)).val;
  }

  operator int() const
  {
    return val;
  }

  mint(ll value = 0) : val(ring(value)){};

  template <
      typename T, typename TEnabled = typename std::enable_if_t<std::is_arithmetic<T>::value, T>>
  mint operator+(const T &b)
  {
    return *this + mint(b);
  }

  template <
      typename T, typename TEnabled = typename std::enable_if_t<std::is_arithmetic<T>::value, T>>
  mint operator-(const T &b)
  {
    return *this - mint(b);
  }

  template <
      typename T, typename TEnabled = typename std::enable_if_t<std::is_arithmetic<T>::value, T>>
  mint operator*(const T &b)
  {
    return *this * mint(b);
  }

  template <
      typename T, typename TEnabled = typename std::enable_if_t<std::is_arithmetic<T>::value, T>>
  mint operator/(const T &b)
  {
    return *this / mint(b);
  }

  template <
      typename T, typename TEnabled = typename std::enable_if_t<std::is_arithmetic<T>::value, T>>
  mint operator^(const T &b) const
  {
    return this->pow(b);
  }

  template <
      typename T, typename TEnabled = typename std::enable_if_t<std::is_arithmetic<T>::value, T>>
  friend mint operator+(const T &b, const mint &a)
  {
    return a.operator+(b);
  }

  template <
      typename T, typename TEnabled = typename std::enable_if_t<std::is_arithmetic<T>::value, T>>
  friend mint operator-(const T &b, const mint &a)
  {
    return mint(b).operator-(a);
  }

  template <
      typename T, typename TEnabled = typename std::enable_if_t<std::is_arithmetic<T>::value, T>>
  friend mint operator*(const T &b, const mint &a)
  {
    return a.operator*(b);
  }

  template <
      typename T, typename TEnabled = typename std::enable_if_t<std::is_arithmetic<T>::value, T>>
  friend mint operator/(const T &b, const mint &a)
  {
    return mint(b).operator/(a);
  }

  mint operator+(const mint &b) const
  {
    return mint(val + b.val);
  }

  mint operator-(const mint &b) const
  {
    return mint(val - b.val);
  }

  mint operator*(const mint &b) const
  {
    return mint(val * b.val);
  }

  mint operator/(const mint &b) const
  {
    return *this * b.inv();
  }

  mint &operator+=(const mint &b)
  {
    val = ((*this) + b).val;
    return *this;
  }

  mint &operator-=(const mint &b)
  {
    val = ((*this) - b).val;
    return *this;
  }

  mint &operator*=(const mint &b)
  {
    val = ((*this) * b).val;
    return *this;
  }

  mint &operator/=(const mint &b)
  {
    val = ((*this) / b).val;
    return *this;
  }

  mint inv() const
  {
    return this->pow(-1);
  }

  mint pow(ll exp) const
  {
    exp = (exp % (p - 1) + (p - 1)) % (p - 1);
    mint ans = 1, base = *this;
    while (exp)
    {
      if (exp & 1)
        ans *= base;
      base *= base;
      exp /= 2;
    }
    return ans;
  }

  mint operator-()
  {
    return mint(-val);
  }

  // prefix
  mint operator++()
  {
    val = ring(val + 1);
    return *this;
  }

  mint operator--()
  {
    val = ring(val - 1);
    return *this;
  }

  bool operator!()
  {
    return !val;
  }

  friend ostream &operator<<(ostream &out, const mint &c)
  {
    out << c.val;
    return out;
  }

  friend istream &operator>>(istream &in, mint &c)
  {
    ll input;
    in >> input;
    c.val = mint::ring(input);
    return in;
  }
};

template <int maxm = mx6>
class sieve
{
public:
  bitset<maxm + 10> isnp;
  vector<int> prime, mo, phi, primes;

  sieve(bool doPhi = false, bool doMo = false)
  {
    prime.resize(maxm + 10, 0);
    isnp[1] = true;
    prime[1] = 1;

    primeWork(2);
    primeWork(3);

    for (int i = 5; i <= maxm; i += 6)
    {
      if (!isnp[i])
        primeWork(i);
      if (!isnp[i + 2])
        primeWork(i + 2);
    }

    if (doMo)
      buildMo();

    if (doPhi)
      buildPhi();
  }

  void buildMo()
  {
    mo.resize(maxm + 10);
    mo[1] = 1;

    for (int j = 2; j <= maxm; j++)
    {
      bool rem = (j / prime[j]) % prime[j];
      mo[j] = rem * (-mo[j / prime[j]]);
    }
  }

  void buildPhi()
  {
    phi.resize(maxm + 10);
    phi[1] = 1;

    for (int j = 2; j <= maxm; j++)
    {
      bool rem = (j / prime[j]) % prime[j];
      phi[j] = phi[j / prime[j]] * (prime[j] - rem);
    }
  }

  void primeWork(int pr)
  {
    prime[pr] = pr;
    primes.pb(pr);
    if (1ll * pr * pr > maxm)
      return;
    for (int k = pr * pr; k <= maxm; k += pr)
    {
      if (!isnp[k])
      {
        prime[k] = pr;
        isnp[k] = true;
      }
    }
  }

  bool isprime(int n)
  {
    assert(n <= maxm);
    return !isnp[n];
  }
};

int main()
{
  nfs;
  int t;
  cin >> t;
  using mi = mint<mod>;
  sieve<mx6> s;
  vector<mi> out(mx6, 0);
  for (int i = 4, j = 0; i < mx6; i += 4, j = !j)
    out[i] += j ? -2 : 2;
  for (const int &p : s.primes)
    for (int i = p, j = 0; i < mx6; i += p, j = (j + 1) % p)
      out[i] += (j ? 0 : p) - 1;
  for (int i = 1; i < mx6; i++)
    out[i] += out[i - 1];
  for (int i = 1; i < mx6; i++)
    out[i] += out[i - 1];
  while (t--)
  {
    int n;
    cin >> n;
    cout << out[n] << "\n";
  }
}