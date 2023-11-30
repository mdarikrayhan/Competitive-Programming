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
const int MAXN = 1000005;
//Used: 265 ms, 41764 KB 10^6
//Used: 2822 ms, 424072 KB 10^7
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
    sievefactor();
    fastio
        multicase
    {
        ll n,maxi=INT_MIN,matrix[1005][1005],ans[1005];
        cin >> n;
        rep(i, 0, n)
        {
            rep(j, 0, n)
            {
                cin >> matrix[i][j];
                ckmax(maxi,matrix[i][j]);
            }
        }
        rep(i, 0, n)
        {
            int val = INT_MAX;
            rep(j, 0, n)
            {
                if (i != j)
                {
                    val &= matrix[i][j];
                }
            }
            ans[i] = val;
        }

        bool flag = true;
        rep(i, 0, n)
        {
            rep(j, 0, n)
            {
                if (i != j && (ans[i] | ans[j]) != matrix[i][j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag==false)
                break;
        }

        if (flag)
        {
            cout<<"YES"<<nl;
            rep(i, 0, n)
            {
                if (ans[i] == INT_MAX)
                {
                    ans[i] = 7;
                }
                cout << ans[i] << " ";
            }
            cout<<nl;
        }
        else
        {
            cout<<"NO"<<nl;
        }
    }
    return 0;
}