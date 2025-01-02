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

#define YES cout << "YES" << nl;
#define NO cout << "NO" << nl;

#define rep(i, a, b) for (int i = a; i < (b); i++)
#define per(i, a, b) for (int i = (b)-1; i >= a; i--)

#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define deb4(a, b, c, d) cout << #a << "=" << a << "," << #b << "=" << b << "," << #c << "=" << c << "," << #d << "=" << d << endl
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
const int MAXN = 1000005;
int spf[MAXN];
vector<int> factor[MAXN];
inline vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
void sievefactor()
{
    spf[1] = 1;
    for (int i = 2; i <= MAXN; i++)
    {
        spf[i] = i;
    }
    for (int i = 4; i <= MAXN; i += 2)
    {
        spf[i] = 2;
    }
    for (int i = 3; i * i < MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
        }
    }
    for (int i = 1; i <= MAXN; i++)
    {
        factor[i] = getFactorization(i);
    }
}
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
unsigned long long int rangesum(long long int L, long long int R) { return ((L + R) * (abs(R - L) + 1)) / 2; }
#define start_time                            \
    using std::chrono::duration;              \
    using std::chrono::duration_cast;         \
    using std::chrono::high_resolution_clock; \
    using std::chrono::milliseconds;          \
    auto t1111 = high_resolution_clock::now();

void solve()
{
    int n;
    cin >> n;
    vector<ll> vec(n), temp(n), psum(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i];
    }
    temp = vec;
    sort(all(temp));
    psum[0] = temp[0];

    for (int i = 1; i < n; ++i)
    {
        psum[i] = temp[i] + psum[i - 1];
    }
    for (auto it : vec)
    {
        auto test = upper_bound(begin(temp), end(temp), it);
        if (test == temp.end())
        {
            cout << n - 1 << " ";
            continue;
        }
        else
        {
            int ans = test - begin(temp) - 1;
            ll sum = psum[ans];
            bool flag = true;
            while (flag)
            {
                ll value = 2 * sum;
                auto iterator1 = upper_bound(begin(psum), end(psum), value) - begin(psum) - 1;
                if (iterator1 == ans)
                    flag = false;
                sum += psum[iterator1] - psum[ans];
                ans = iterator1;
            }
            cout << ans << " ";
        }
    }
    cout << nl;
}

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

#define fastio                        \
    goodluck                          \
    sievefactor();                    \
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
        solve();
    }
    return 0;
}