/***************************************************/
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/

//#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

typedef long long ll;
typedef unsigned long long ull;
typedef __uint128_t u128;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

#define YES cout << "YES" << nl;
#define NO cout << "NO" << nl;

#define ins insert
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

#define rep(i, a, b) for (int i = a; i < (b); i++)
#define per(i, a, b) for (int i = (b)-1; i >= a; i--)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * (b / gcd(a, b)))

#define start_time using std::chrono::duration;using std::chrono::duration_cast; using std::chrono::high_resolution_clock; using std::chrono::milliseconds; auto t1111 = high_resolution_clock::now();
#define end_time auto t2222 = high_resolution_clock::now(); duration<double, std::milli> ms_double = t2222 - t1111;std::cout << ms_double.count() << 'm' << 's' << nl;
#define spring for (int num = 0; num < 9185319; num++){string a = "Arik";a.pop_back();a.pop_back();a.pop_back();a.pop_back();}
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define fastIO spring sievefactor(); fastio
#define multicase int NoOfTestCase = 1;cin >> NoOfTestCase;for (int testcaseno = 1; testcaseno <= NoOfTestCase; testcaseno++)

#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define deb4(a, b, c, d) cout << #a << "=" << a << "," << #b << "=" << b << "," << #c << "=" << c << "," << #d << "=" << d << endl

/****************** Debug.h Files **********************/
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

//Bitwise Sieve
//const int pmxsz = 100000000;
//int status[(pmxsz / 32) + 2];
//int prime[5761455 + 5], noofprime = 0;
//inline bool Bit_Check(int N, int pos) { return (bool)(N & (1 << pos)); }
//inline int Bit_Set(int N, int pos) { return N = N | (1 << pos); }
//inline bool PrimeCheck(int i) { return 1 ^ (bool)(Bit_Check(status[i >> 5], i & 31)); }
//inline void PrimeSet(int i) { status[i >> 5] = Bit_Set(status[i >> 5], i & 31); }
//inline void Mark(int i, int N) { for (int j = i * i; j <= N; j += (i << 1)) PrimeSet(j); }
//void sieve(int N) { int i, j, sqrtN; sqrtN = int(sqrt(N)); for (i = 5; i <= sqrtN; i += 6) { if (PrimeCheck(i)) { Mark(i, N); } if (PrimeCheck(i + 2)) { Mark(i + 2, N); } } prime[noofprime++] = 2; prime[noofprime++] = 3; for (i = 5; i <= N; i += 6) { if (PrimeCheck(i)) { prime[noofprime++] = i; } if (PrimeCheck(i + 2)) { prime[noofprime++] = i + 2; } } }

//Single Prime Check using Miller Rabin
ull binpower(ull base, ull e, ull mod) { ull result = 1; base %= mod; while (e) { if (e & 1) result = (u128)result * base % mod; base = (u128)base * base % mod; e >>= 1; } return result; }
bool check_composite(ull n, ull a, ull d, int s) { ull x = binpower(a, d, n); if (x == 1 || x == n - 1) return false; for (int r = 1; r < s; r++) { x = (u128)x * x % n; if (x == n - 1) return false; } return true; };
bool MillerRabin(ull n) { if (n < 2) return false; int r = 0; ull d = n - 1; while ((d & 1) == 0) { d >>= 1; r++; } for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) { if (n == a) return true; if (check_composite(n, a, d, r)) return false; } return true; }

//Prime Factorization using SPFs and Sieve
//const int MAXN = 10e6+5; int spf[MAXN]; vector<int> factor[MAXN]; inline vector<int> getFactorization(int x) { vector<int> ret; while (x != 1) { ret.push_back(spf[x]); x = x / spf[x]; } return ret; }
//void sievefactor() { spf[1] = 1; for (int i = 2; i <= MAXN; i++) { spf[i] = i; } for (int i = 4; i <= MAXN; i += 2) { spf[i] = 2; } for (int i = 3; i * i < MAXN; i++) { if (spf[i] == i) { for (int j = i * i; j < MAXN; j += i) if (spf[j] == j) { spf[j] = i; } } } for (int i = 1; i <= MAXN; i++) { factor[i] = getFactorization(i); } }

ull rangesum(ll L, ll R) { return ((L + R) * (abs(R - L) + 1)) / 2; }
bool isPalindrome(string S) { string P = S; reverse(P.begin(), P.end()); return S == P ? true : false; }
bool isPowerof(ll num, ll base) { return (num > 0 && num % base == 0) ? isPowerof(num / base, base) : num == 1; }
bool isPowerofTwo(ll num) { return (num > 0 && (num & (num - 1)) == 0) ? true : false; }

template <class T>
bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

void solve()
{
        unordered_map<int, int> mp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    if(mp.size()==1){
        cout<<"YES"<<nl;
        return;
    }
    if (mp.size() > 2)
    {
        cout << "NO" << nl;
        return;
    }
    else
    {
        auto it = mp.begin();
        int a = it->second;
        it++;
        int b = it->second;
        //cout<<a<<" "<<b<<nl;
        if (a == b || abs(a - b) == 1)
        {
            cout << "YES" << nl;
            return;
        }
        else
        {
            cout << "NO" << nl;
            return;
        }
    }
}

int32_t main()
{
    fastio
        multicase
    {
        solve();
    }
    return 0;
}