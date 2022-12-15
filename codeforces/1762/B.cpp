/***************************************************/
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

typedef long long ll;
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

#define rep(i, a, b) for (int i = a; i < (b); i++)
#define per(i, a, b) for (int i = (b)-1; i >= a; i--)
#define print_map(m)                                                     \
    for (const auto &[key, value] : m)                                   \
    {                                                                    \
        cout << '[' << key << ']' << ' ' << '=' << ' ' << value << '\n'; \
    }
#define print_vector(v)                          \
    int vadnfiv = 0;                             \
    for (const auto &value : v)                  \
    {                                            \
        cout << vadnfiv << ' ' << value << '\n'; \
        vadnfiv++;                               \
    }
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * (b / gcd(a, b)))

#define start_time                            \
    using std::chrono::duration;              \
    using std::chrono::duration_cast;         \
    using std::chrono::high_resolution_clock; \
    using std::chrono::milliseconds;          \
    auto t1111 = high_resolution_clock::now();
#define end_time                                            \
    auto t2222 = high_resolution_clock::now();              \
    duration<double, std::milli> ms_double = t2222 - t1111; \
    std::cout << ms_double.count() << 'm' << 's' << nl;
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define multicase         \
    int NoOfTestCase = 1; \
    cin >> NoOfTestCase;  \
    for (int testcaseno = 1; testcaseno <= NoOfTestCase; testcaseno++)
bool isPrime(int n)
{
    if (n == 2 || n == 3)
    {
        return true;
    }
    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}
bool isPalindrome(string S)
{
    string P = S;
    reverse(P.begin(), P.end());
    if (S == P)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isPowerof(long long num, long long base)
{
    if (num <= 0)
    {
        return false;
    }
    if (num % base == 0)
    {
        return isPowerof(num / base, base);
    }
    if (num == 1)
    {
        return true;
    }
    return false;
}

template <class T>
bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

int main()
{
    fastio
        multicase
    {
        ll n;
        set<long long> s;
        cin >> n;
        ll a[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            s.insert(a[i]);
        }
        vector<ll> v;
        for (auto i : s)
        {
            v.push_back(i);
        }
        map<ll, ll> mp;
        for (ll i = 1; i < v.size(); i++)
        {
            if (v[i] % v[i - 1] != 0)
            {
                ll rem = v[i] % v[i - 1];
                ll ans = v[i] + v[i - 1] - rem;
                mp.insert({v[i], ans});
                v[i] = ans;
            }
        }
        vector<pair<ll, ll>> vp;
        for(int i = 0; i < n; i++)
        {
            if(mp[a[i]]!=0){
                vp.push_back({i+1, mp[a[i]]-a[i]});
            }
        }
        cout << vp.size() << nl;
        for(auto i : vp)
        {
            cout << i.first << ' ' << i.second << nl;
        }
    }
    return 0;
}