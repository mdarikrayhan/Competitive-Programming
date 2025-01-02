#include<bits/stdc++.h>
//----------------------<><><><><><><nacool><><><><><><>-----------------------------//
using namespace std;

#define ONLINE_JUDGE nacool2004
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef nacool2004
#define debug(x) std::cerr << #x <<" "; _print(x); std::cerr << std::endl;
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T> bool isPrime(T n) {
    if (n <= 1) return false;
    for (T i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

template <class T>
T binpow(T base, T exp, T mod) {
    T result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

template <class T> T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

template <class T> T lcm(T a, T b) {
    return (a / gcd(a, b)) * b;
}

template <class T> T pow(T a, T b, T m) {
    T ans=1;
    while(b) {
        if(b & 1)
            ans=(ans*a)%m;
        b/=2;
        a=(a*a)%m;
    }
    return ans;
}

template <class T> T binarySearch(vector<T> arr, T l, T r, T x) {
    while (l <= r) {
        T m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
vector<ll> spf(1000006);

void spfsieve() {
    for (int i = 2; i < 1000006; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            for (ll j = (ll)i * i; j < 1000006; j += i) {
                if (spf[j] == 0) {
                    spf[j] = i;
                }
            }
        }
    }
}

vector<bool> prime(1e6+5, true);

void sieve() {
    prime[0] = prime[1] = false;
    for(int i = 2; i * i <= 1e6+5; i++) {
        if(prime[i]) {
            for(int j = i * i; j <= 1e6+5; j += i) {
                prime[j] = false;
            }
        }
    }
}

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;}
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}

/*---------------------------------------------------------<><><><><><><><><><><><><><><><><><><><><>--------------------------------------------------------*/
string rotateUntilXFirst(string s) {
    while (s[0] != 'X') {
        rotate(s.begin(), s.begin() + 1, s.end());
    }
    return s;
}

void solve() {
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    swap(s2[0],s2[1]);
     swap(s4[0],s4[1]);

    s1 += s2;
    s3 += s4;
    
    s1.erase(s1.find('X'),1);
    s3.erase(s3.find('X'),1);
    s1+=s1;
    if(s1.find(s3)!=-1) cout<<"YES\n";
    else cout << "NO\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef nacool2004
        //freopen("inputf.in", "r", stdin);
        //freopen("outputf.in", "w", stdout);
        freopen("Errorf.in", "w", stderr);
    #endif

    solve();
    return 0;
}