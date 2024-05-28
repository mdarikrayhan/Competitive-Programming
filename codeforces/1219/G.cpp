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

int sumbig(vector<int> &vals, int amt){
    vector<int> out(amt);
    for(int i : vals){
        for(int j{}; j < amt; ++j)
            if(out[j] <= i)
                swap(out[j], i);
    }

    return accumulate(out.begin(), out.end(), 0ll);
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for(int i{}; i < n; ++i)
        for(int j{}; j < m; ++j)
            cin >> a[i][j];

    // first take all rows or columns

    vector<int> r(n);
    vector<int> c(m);
    for(int i{}; i < n; ++i){
        for(int j{}; j < m; ++j){
            r[i] += a[i][j];
            c[j] += a[i][j];
        }
    }

    int best = max(sumbig(r, 4), sumbig(c, 4));

    for(int i{}; i < n; ++i){
        int tot = r[i];
        for(int j{}; j < m; ++j){
            c[j] -= a[i][j];
        }

        tot += sumbig(c, 3);

        best = max(best, tot);
        for(int j{}; j < m; ++j){
            c[j] += a[i][j];
        }
    }

    for(int j{}; j < m; ++j){
        int tot = c[j];
        for(int i{}; i < n; ++i)
            r[i] -= a[i][j];
        tot += sumbig(r, 3);
        best = max(best, tot);
        for(int i{}; i < n; ++i)
            r[i] += a[i][j];
    }

    if(n < m){
        for(int i{}; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                int tot = r[i] + r[j];
                for(int k{}; k < m; ++k){
                    c[k] -= a[i][k];
                    c[k] -= a[j][k];
                }
                tot += sumbig(c, 2);
                best = max(best, tot);
                for(int k{}; k < m; ++k){
                    c[k] += a[i][k];
                    c[k] += a[j][k];
                }
            }
        }
    }else{
        for(int j{}; j < m; ++j){
            for(int k = j+1; k < m; ++k){
                int tot = c[j] + c[k];
                for(int i{}; i < n; ++i){
                    r[i] -= a[i][j];
                    r[i] -= a[i][k];
                }
                tot += sumbig(r, 2);
                best = max(best, tot);
                for(int i{}; i < n; ++i){
                    r[i] += a[i][j];
                    r[i] += a[i][k];
                }

            }
        }
    }
    cout << best << '\n';
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
