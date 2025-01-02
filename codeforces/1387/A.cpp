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
pair<int, double> out[100001];;
vector<int> onstack;
vector<int> values;
bool vis[100001];
double eps = 1e-8;
int hasset = -1;
bool dfs(int v, vector<map<int, int>> &adj){
    //cout << "dfs " << v << '\n';
    onstack.push_back(v);
    vis[v] = true;

    for(auto [u, c] : adj[v]){
        int othera = -out[v].F;
        double val = c-out[v].S;
        if(hasset != -1)
            return false;
        if(vis[u]){
            if(out[u].F == othera && abs(val-out[u].S) <= eps)
                continue;
            if(out[u].F == othera)
                return false;

            // otherwise the values have to be set
            hasset = u;
            double cc = val-out[u].S;
            int diff = out[u].F - othera;
            cc /= diff;
            out[u].S = out[u].F*cc + out[u].S;
            out[u].F = 0;
            //cout << "found set value " << v << ' ' << u << '\n';;
            return false;
        }else{
            out[u].F = othera;
            out[u].S = val;
            values.push_back(val*othera);
            if(!dfs(u, adj) || hasset != -1)
                return false;
        }
    }
    return true;
}
bool mark(int v, vector<map<int, int>> &adj){
    //cout << "mark " << v << '\n';
    vis[v] = true;
    for(auto [u, c] : adj[v]){
        //cout << v << ' ' << u << ' ' << c << ' ' << vis[u] << '\n';
        double ne = c-out[v].S;
        int tt = out[u].F;
        if(vis[u]){
            if(abs(out[u].S - ne) > eps){
                return false;
            }
        }else{
            if(tt == 0){
                if(abs(out[u].S - ne) > eps){
                    return false;
                }
            }
            out[u].S = ne;
            out[u].F = 0;
            if(!mark(u, adj))
                return false;
        }
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<map<int, int>> adj(n);
    bool bad = false;
    set<int> s;
    for(int i{}; i < n; ++i)
        out[i].F = 1;
    for(int i{}; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        if(adj[u].count(v)){
            if(adj[u][v] != w){
                bad = true;
            }
            continue;
        }
        if(u == v){
            s.insert(u);
            out[u].F = 0;
            out[u].S = w/2.0;
        }

        adj[u][v] = w;
        adj[v][u] = w;
    }
    if(bad){
        cout << "NO\n";
        return;
    }

    for(auto &t : s){
        if(vis[t])
            continue;
        if(!mark(t, adj)){
            cout << "NO\n";
            return;
        }
    }

    for(int i{}; i < n; ++i){
        if(!vis[i]){
            hasset = -1;
            out[i].F = 1, out[i].S = 0;
            if(!dfs(i, adj) && hasset == -1){
                cout << "NO\n";
                return;
            }

            if(hasset != -1){
                for(int i : onstack)
                    vis[i] = false;
                onstack.clear();
                values.clear();
                if(!mark(hasset, adj)){
                    cout << "NO\n";
                    return;
                }
            }else{
                for(int i : onstack)
                    vis[i] = false;
                values.push_back(out[i].F*out[i].S);
                sort(values.begin(), values.end());
                int m = values.size()/2;
                m = -values[m];
                onstack.clear();
                values.clear();
                out[i].S = out[i].F*m+out[i].S;
                out[i].F = 0;
                if(!mark(i, adj)){
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
    cout << setprecision(10) << fixed;
    for(int i{}; i < n; ++i)
        cout << out[i].S << ' ';
    cout << '\n';
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
