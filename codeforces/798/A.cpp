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
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a*(b/gcd(a,b))

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
bool PrimeCheck(int n)
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

template <class T>
bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

int main()
{
    fastio
        string s,
        s4;
    cin >> s;
    s4 = s;
    reverse(s4.begin(), s4.end());
    if (s == s4 && (s.size()&1)==1)
    {
        cout << "YES" << nl;
        return 0;
    }
    if (s == s4)
    {
        cout << "NO" << nl;
        return 0;
    }
    rep(i, 0, s.size())
    {
        string s1;
        rep(j, 0, s.size())
        {
            if (i != j)
            {
                s1 = s1 + s[j];
            }
            else
            {
                s1 = s1 + s[s.size() - i - 1];
            }
        }
        string s2 = s1;

        reverse(s2.begin(), s2.end());
        if (s1 == s2)
        {
            cout << "YES" << nl;
            return 0;
        }
    }
    cout << "NO" << nl;
    return 0;
}