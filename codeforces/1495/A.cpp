#include <bits/stdc++.h>
using namespace std;

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

template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a*(b/gcd(a,b))

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template <class T>
bool ckmin(T &a, const T &b)
{
    return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
const char nl = '\n';
void solve()
{

    long long i, j, k, l, m, n, x, y, z;
    string s;
    cin >> n;
    long long a[n], b[n];
    k = 0;
    j = 0;
    double p;
    p = 0;
    for (i = 0; i < 2 * n; i++)
    {
        cin >> x >> y;
        x = abs(x);
        y = abs(y);
        if (x == 0)
        {
            a[j] = y;
            j++;
        }
        else
        {
            b[k] = x;
            k++;
        }
    }
    sort(a, a + n);
    sort(b, b + n);
    for (i = 0; i < n; i++)
    {
        j = a[i] * a[i];
        k = b[i] * b[i];
        k = k + j;
        p = p + sqrt(k);
    }
    cout << setprecision(20) << p << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}