#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
typedef int uci;
#define int long long
#define F first
#define S second
typedef complex<double> cd;

seed_seq seq{
    (uint64_t) chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
    (uint64_t) __builtin_ia32_rdtsc(),
    (uint64_t) (uintptr_t) make_unique<char>().get()
};
mt19937 rng(seq);
// mt19937_64 lrng(seq);

struct debugger{
    template <typename T>
    debugger& operator<<(T &a){
        #ifdef DEBUG
            cerr << a;
        #endif
        return *this;
    }
    template <typename T>
    debugger& operator<<(T &&a){
        #ifdef DEBUG
            cerr << a;
        #endif
        return *this;
    }
} deb;

const double PI = acos(-1.0);
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

//! function insert

//THINK FIRST, CODE SECOND
//DON'T GET STUCK ON ONE STRATEGY
//CALM DOWNNN FOR ONCE IN YOUR LIFE
//REDUCE
//COUGH E??!?!?!! O.O
//uwu i see you ryan
ar<int, 2> pl[31];

void place(int v, int p, int x, int y, int step, int direc, vector<vector<int>> &adj){
    int c{};
    pl[v][0] = x;
    pl[v][1] = y;
    for(int i : adj[v]){
        if(i == p)
            continue;
        if(c == direc)
            c++;
        if(c == 0){
            place(i, v, x-step, y, step/2, 3, adj);
        }else if(c == 1){
            place(i, v, x, y-step, step/2, 2, adj);
        }else if(c == 2){
            place(i, v, x, y+step, step/2, 1, adj);
        }else{
            place(i, v, x+step, y, step/2, 0, adj);
        }
        c++;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i{}; i < n-1; ++i){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i{}; i < n; ++i){
        if(adj[i].size() > 4){
            cout << "NO\n";
            return;
        }
    }

    for(int i{}; i < n; ++i){
        if(adj[i].size() == 1){
            place(i, -1, 0, 0, (1ll<<50), -1, adj);
            break;
        }
    }

    cout << "YES\n";
    for(int i{}; i < n; ++i)
        cout << pl[i][0] << ' ' << pl[i][1] << '\n';
}

uci main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

        // cout << "Case #" << t  << ": ";
        solve();
}

/*
    random number generator stuff
    num = rng(); gives integer number
    num = uniform_int_distribution<int>(a, b)(rng); -> bounds [a, b]
    num = uniform_real_distribution<double>(a, b)(rng); -> bounds [a, b)
    can also instantiate distributions and call on generator:
    uniform_int_distribution<int> thing(a, b);
    num = thing(rng);
*/
// struct custom_hash {
//     static uint64_t splitmix64(uint64_t x) {
//         // http://xorshift.di.unimi.it/splitmix64.c
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }
//     size_t operator()(uint64_t x) const {
//         static const uint64_t FIXED_RANDOM = lrng();
//         return splitmix64(x + FIXED_RANDOM);
//     }
// };
