#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mod 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mii map<int, int>
#define mci map<char, int>
#define mll map<ll, ll>
#define usi unordered_set<int>
#define usll unordered_set<ll>
#define umii unordered_map<int, int>
#define umll unordered_map<ll, ll>
#define c(x) cout << x;
#define cn(x) cout << x << endl;
#define ci(x) cin >> x;
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define wh_t while (t--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mp make_pair
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define mem(a, b) memset(a, b, sizeof(a))
#define prec(n) fixed << setprecision(n)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define endl "\n"

#ifndef ONLINE_JUDGE
#define DEBUG
#define DEBUG_FILE freopen("debug.txt", "w", stderr)
#define d(x) cerr << #x << " = " << x << endl;
#define dvec(v)           \
    cerr << #v << " = ";  \
    for (auto i : v)      \
        cerr << i << ' '; \
    cerr << endl;
#define dset(s)           \
    cerr << #s << " = ";  \
    for (auto i : s)      \
        cerr << i << ' '; \
    cerr << endl;
#define dmap(m)                                              \
    cerr << #m << " = ";                                     \
    for (auto it : m)                                        \
        cerr << "(" << it.first << ":" << it.second << ") "; \
    cerr << endl;
#define dqueue(q)                 \
    cerr << #q << " = ";          \
    while (!q.empty())            \
    {                             \
        cerr << q.front() << ' '; \
        q.pop();                  \
    }                             \
    cerr << endl;

#else
#define DEBUG_FILE
#define d(x)
#define dvec(v)
#define dset(s)
#define dmap(m)
#define dqueue(q)
#endif

int main()
{
    fastio;
    DEBUG_FILE;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int N;
    cin >> N;
    int count = 0;

    // Generate all Pythagorean triplets where c <= N
    for (int m = 2; m * m <= N; ++m) {
        for (int k = 1; k < m; ++k) {
            // Ensure m and k are coprime and not both odd
            if (__gcd(m, k) == 1 && (m - k) % 2 == 1) {
                int a = m * m - k * k;
                int b = 2 * m * k;
                int c = m * m + k * k;

                // Ensure a <= b
                if (a > b) swap(a, b);

                // Check if c <= N and count all multiples
                if (c <= N) {
                    for (int j = 1; j * c <= N; ++j) {
                        int ja = j * a;
                        int jb = j * b;
                        int jc = j * c;
                        if (ja <= jb && jb <= jc && jc <= N) {
                            count++;
                        }
                    }
                }
            }
        }
    }

    cout << count << endl;
    return 0;
}