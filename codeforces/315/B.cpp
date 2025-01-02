/**
*    author:  desparado
*
**/

#include <bits/stdc++.h>

using namespace std;

#define int            long long int
#define double         long double
#define F              first
#define S              second
#define pb             push_back
#define lb             lower_bound
#define ub             upper_bound
#define si             set <int>
#define vi             vector <int>
#define vvi            vector <vi>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(v)          ((int) v.size())
#define all(v)         v.begin(), v.end()
#define rall(v)        v.rbegin(), v.rend()
#define vsum(v)        accumulate(v.begin(), v.end(), 0LL)
#define vmax(v)        *max_element(v.begin(), v.end())
#define vmin(v)        *min_element(v.begin(), v.end())
#define setbits(x)     __builtin_popcountll(x)
#define lstsetbit(x)   __builtin_clzll(x)
#define fstsetbit(x)   __builtin_ctzll(x)
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define form(i, a, b)  for (int i=a; i<(b); i++)
#define forn(i, a)     for (int i=0; i<(a); i++)
#define rofm(i, a, b)  for (int i = (b)-1; i >= (a); --i)
#define rof(i, a)      rofm(i, 0, a)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

const int mod = 1e9 + 7;
const int N = 200005;



void solve() {
    int n, m;
    cin >> n >> m;
    int sum = 0;
    vi v(n);
    forn(i, n)cin >> v[i];
    while (m--) {
        int c;
        cin >> c;
        if (c == 1) {
            int v1, x;
            cin >> v1 >> x;
            v1--;
            v[v1] = x - sum;
        }
        else if (c == 2) {
            int y;
            cin >> y;
            sum += y;
        }
        else {
            int q;
            cin >> q;
            q--;
            cout << v[q] + sum << '\n';
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
#endif

    clock_t z = clock();

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}