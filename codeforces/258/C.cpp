#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

// typedef tree<pair<int, int>, null_type, greater<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// #pragma GCC optimize("O3,Ofast")
#define all(a) (a).begin(), (a).end()
#define ull unsigned long long
#define ll long long

int ceil_div(int a, int b) {
    if (a % b == 0) return a / b;
    else return a / b + 1;
}

struct pairhash {
public:
    template <typename T, typename U>
    std::size_t operator()(const std::pair<T, U> &x) const {
        int n = std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
        n += 0x9e3779b97f4a7c15;
        n = (n ^ (n >> 30)) * 0xbf58476d1ce4e5b9;
        n = (n ^ (n >> 27)) * 0x94d049bb133111eb;
        return n ^ (n >> 31);
    }
};

#define MOD 1000000007

ll bin_pow(ll a, ll p) {
    vector<ll> powers(25);
    powers[1] = a;
    for (int i = 2; i < 25; i++) {
        powers[i] = (powers[i - 1] * powers[i - 1]) % MOD;
    }
    int s = 0;
    ll res = 1;
    while (p >> s) {
        if ((p >> s) & 1) res = (res * powers[s + 1]) % MOD;
        s++;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    sort(all(a));

    ll res = 0;
    for (int l = a.back(); l > 0; l--) {
        vector<int> opposite_divs;
        int div_cnt = 0, prev_end = -1;
        ll curr_res = 1;
        for (int i = 1; i * i <= l; i++) {
            if (l % i != 0) continue;
            if (l / i != i) opposite_divs.push_back(l / i);
            int last = lower_bound(all(a) - 1, i) - a.begin() - 1;
            curr_res *= bin_pow(div_cnt, last - prev_end);
            curr_res %= MOD;
            // cerr << i << ' ' << last << ' ' << prev_end << ' ' << div_cnt << ' ' << curr_res << endl;
            prev_end = last;
            div_cnt++;
        }
        reverse(all(opposite_divs));
        for (int i : opposite_divs) {
            int last = lower_bound(all(a) - 1, i) - a.begin() - 1;
            curr_res *= bin_pow(div_cnt, last - prev_end);
            curr_res %= MOD;
            // cerr << i << ' ' << last << ' ' << prev_end << ' ' << div_cnt << ' ' << curr_res << endl;
            prev_end = last;
            div_cnt++;
        }
        ll full_options = bin_pow(div_cnt, n - 1 - prev_end);
        ll invalid_options = bin_pow(div_cnt - 1, n - 1 - prev_end);
        // cerr << curr_res << endl;
        curr_res *= (full_options - invalid_options + MOD) % MOD;
        curr_res %= MOD;
        // cerr << l << ' ' << curr_res << endl;
        res += curr_res;
        res %= MOD;
    }
    cout << res << '\n';
}
