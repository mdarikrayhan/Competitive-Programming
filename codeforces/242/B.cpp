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
    ios_base::sync_with_stdio(false);
    DEBUG_FILE; // Open debug.txt only in debug mode
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    if (n == 0) {
        cout << "-1\n";
        return 0;
    }
    vector<vector<int>> a(n, {0, 0});
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i][0] = x;
        a[i][1] = y;
    }
    stack<vector<int>> s;
    if (!a.empty()) {
        s.push(a[0]);
    }
    for (int i = 1; i < n; i++) {
        // if s.top covers a[i]
        if (s.top()[0] <= a[i][0] && s.top()[1] >= a[i][1]) {
            continue;
        }
        // if a[i] covers s.top
        if (a[i][0] <= s.top()[0] && a[i][1] >= s.top()[1]) {
            s.pop();
            if(!s.empty()){
                while(!s.empty() && s.top()[0] >= a[i][0] && s.top()[1] <= a[i][1]){
                    s.pop();
                }
            }
            s.push(a[i]);
            i--;
        }
        else {
            s.push(a[i]);
        }
    }
    if (s.size() == 1) {
        // printing the index of s.top in a
        for (int i = 0; i < n; i++) {
            if (a[i][0] == s.top()[0] && a[i][1] == s.top()[1]) {
                cout << i + 1;
                break;
            }
        }
    } else {
        cout << "-1";
    }

    return 0;
}
