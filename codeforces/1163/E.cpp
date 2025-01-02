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
int basis[20];

int add(int mask){
    for(int i{}; i < 20; ++i){
        if((mask&(1<<i)) == 0)
            continue;
        if(basis[i] == 0){
            basis[i] = mask;
            return 1;
        }

        mask ^= basis[i];
    }
    return 0;
}

int gray(int n){
    return n^(n>>1);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i{}; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());

    int ind{};
    int best = 0;
    int added{};
    vector<int> vals;
    for(int i{1}; i < 20; ++i){
        while(ind < n && a[ind] < (1<<i)){
            if(add(a[ind])){
                vals.push_back(a[ind]);
                added++;
            }
            ind++;
        }

        if(added == i){
            best = i;
        }
    }

    if(best == 0){
        cout << 0 << '\n';
        cout << 0 << '\n';
    }else{
        vector<int> xx{0};
        int prev{};
        for(int i{1}; i < (1<<best); ++i){
            int g = gray(i);
            prev ^= g;
            int val{};
            for(int j{}; j < vals.size(); ++j){
                if((1<<j)&prev)
                    val ^= vals[j];
            }
            prev = g;
            xx.push_back(xx.back()^val);
        }

        cout << best << '\n';
        for(int i : xx)
            cout << i << ' ';
        cout << '\n';
    }
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
