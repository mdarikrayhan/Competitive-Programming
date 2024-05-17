#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long
#define lld long double
#define fi first
#define se second
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define mii map<int,int>
#define mci map<char,int>
#define umci unordered_map<char,int>
#define umii unordered_map<int,int>
#define pii pair<int,int>
#define pqmax priority_queue<int>
#define pqmin priority_queue <int, vector<int>, greater<int>> 
#define sqrt sqrtl
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define notpos cout<<-1<<endl
#define setbits(a) __builtin_popcountll(a) 
#define ctz(a) __builtin_ctzll(a)
#define clz(a) __builtin_clzll(a)
#define f(n) for (int i = 0; i < n;i++)
#define fj(n) for (int j = 0; j < n;j++)
#define fk(n) for (int k = 0; k < n;k++)
#define f1(n) for (int i = 1; i <= n;i++)
#define fj1(n) for (int j = 1; j <= n;j++)
#define fk1(n) for (int k = 1; k <= n; k++)
#define newl cout << "\n"
#define in(x) insert(x)
#define rev(v) reverse(v.begin(), v.end())
#define vin(v,n) int n; cin>>n; vector<int> v(n); for(int i=0;i<n;i++) cin>>v[i];
#define out(v) for(auto x: v) cout<<x<<" "; cout<<"\n";
#define test int t; cin>>t; while(t--)
#define sz(a) (int)a.size()
#define sortf(a) sort(a.begin(),a.end())
#define sortr(a) sort(a.rbegin(),a.rend())
#define unq(v) v.resize(distance(v.begin(), unique(all(v))));
#define all(a) a.begin(),a.end()
#define gsum(a) accumulate(a.begin(),a.end(),0LL)
#define gmax(a) *max_element(a.begin(),a.end())
#define gmin(a) *min_element(a.begin(),a.end())
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define d1(x) cout<<#x<<" "<<x<<endl;
#define d2(x, y) cout << #x << " " << x << " " << #y << " " << y << endl;
#define d3(x, y, z) cout << #x << " " << x << " " << #y << " " << y << " " << #z << " " << z << endl;
#define d4(x, y, z, w) cout << #x << " " << x << " " << #y << " " << y << " " << #z << " " << z " " << #w << " " << w << endl;

const int mod = 1000000007;
// const int mod = 998244353;
const int inf = LLONG_MAX;
const lld eps = 1e-7;
const int N = 200005;

int fact[N + 1];
int inv[N + 1];
int spf[N + 1];
bool isprime[N + 1];

int power(int x, int n)
{
    int res = 1;
    while (n)
    {
        if (n % 2 == 1)
        {
            res *= x;
            res %= mod;
        }
        n /= 2;
        x *= x;
        x %= mod;
    }
    return res;
}

int ncr(int n, int r)
{
    return (((fact[n] * inv[n - r]) % mod) * inv[r]) % mod;
}

int gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a / (__gcd(a, b))) * b;
}

void sieve()
{
    spf[0] = 1;
    spf[1] = 1;
    for (int i = 2; i < N; i++)
        spf[i] = i;
    for (int i = 2; i * i < N; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < N; j += i)
            {
                spf[j] = i;
            }
        }
    }
}

void calallprime()
{
    for (int i = 0; i <= N; i++)
        isprime[i] = true;
    isprime[1] = false;
    for (int i = 2; i < N + 1; i++)
    {
        if (isprime[i])
        {
            for (int j = i * i; j < N + 1; j += i)
                isprime[j] = false;
        }
    }
}

void precompute()
{
    fact[0] = 1;
    inv[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        fact[i] = fact[i - 1] * i;
        fact[i] %= mod;
        inv[i] = power(fact[i], mod - 2);
    }
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vi a(n), b(m);
  f(n) cin >> a[i];
  f(m) cin >> b[i];
  map<int, int> mp;
  f(n){
    mp[a[i]] = i;
  }
  set<int> val;
  int ans = 0;
  int lst = 0;
  f(m){
    if(val.find(b[i])!=val.end()){
      ans++;
    }
    else{
      for (int j = lst; j < n;j++){
        if(a[j]==b[i]){
          ans++;
          lst = j + 1;
          ans += (j-i)* 2;
          break;
        }
        else{
          val.in(a[j]);
        }
      }
    }
    // d1(ans);
  }
  cout << ans << endl;
}

int32_t main()
{
    fastio;
    // precompute();
    // sieve();
    // calallprime();
    test
    {
        solve();
    }
    return 0;
}
