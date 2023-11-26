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

#define rep(i, a, b) for (int i = a; i <= (b); i++)
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
ll n = 300005, ans = LONG_MAX;
string stemp;
vector<ll> lefte(n + 1), righte(n + 1), ansv(n + 1);
void clear()
{
    ans = LONG_MAX;
    lefte.clear();
    righte.clear();
    ansv.clear();
    ansv[1] = 0;
}
unsigned long long int rangesum(long long int L, long long int R) { return ((L + R) * (abs(R - L) + 1)) / 2; }
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
#define goodluck                               \
    for (int arik = 0; arik < 9185319; arik++) \
    {                                          \
        string a = "arik";                     \
        a.pop_back();                          \
        a.pop_back();                          \
        a.pop_back();                          \
        a.pop_back();                          \
    }
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
void operation()
{
    cin >> n >> stemp;
    stemp = " " + stemp;
    rep(i, 1, n)
    {
        cin >> lefte[i] >> righte[i];
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
queue<ll> q;
void sol()
{
    clear();
    operation();
    q.empty();
    q.push(1);
    while (q.size())
    {
        auto u = q.front();
        q.pop();
        if (lefte[u] != 0)
        {
            ansv[lefte[u]] = ansv[u] + (stemp[u] != 'L');
            q.push(lefte[u]);
        }
        if (righte[u] != 0)
        {
            ansv[righte[u]] = ansv[u] + (stemp[u] != 'R');
            q.push(righte[u]);
        }
    }
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
        sol();
        rep(i, 1, n)
        {
            if (lefte[i] == 0 && righte[i] == 0)
            {
                ans = min(ans, ansv[i]);
            }
        }
        cout<<ans<<nl;
    }
    return 0;
}