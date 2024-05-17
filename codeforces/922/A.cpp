#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

typedef vector<int> vi;
typedef vector<pair<int, int>> pv;

#define PB push_back
#define FORV(var, from, to) for(int var = from; var < to; var++)
#define FOR(from, to) for(int i = from; i < to; i++)

// https://codeforces.com/blog/entry/11080
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// https://stackoverflow.com/questions/32685540/why-cant-i-compile-an-unordered-map-with-a-pair-as-key
template <class T> inline void hash_combine(size_t &seed, T const &v) {
    seed ^= hash<T>()(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const {
        size_t seed = 0;
        hash_combine(seed, p.first);
        hash_combine(seed, p.second);
        return seed;
    }
};

void solve(){
    int c, o;
    cin >> c >> o;
    if(o == 1 && c == 0){
        cout << "YES" << endl;
        return;
    }
    else if((o == 1 && c != 1) || (o - 1) > c || o == 0){
        cout << "NO" << endl;
        return;
    }
    int cpyCnt = o - 1;
    if(c % 2 == 0 &&  cpyCnt % 2 == 0) cout << "YES" << endl;
    else if(c % 2 && cpyCnt % 2) cout << "YES" << endl;
    else cout << "NO" << endl;
}


int main(){
    solve();
    return EXIT_SUCCESS;
}
