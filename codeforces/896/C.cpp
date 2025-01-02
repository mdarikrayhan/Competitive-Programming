/**
 * Willem, Chtholly, and Seniorious
 * https://codeforces.com/problemset/problem/896/C
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using ll = long long;
using ld = long double;

constexpr int mod = 1e9 + 7;

struct Interval {
    int lb;
    int ub;
    ll val;

    friend bool operator< (const Interval& x, const Interval& y) {
        return x.ub < y.ub;
    }

    friend std::ostream& operator<< (std::ostream& cout, const Interval& x) {
        cout << "{" << x.lb << " " << x.ub << " " << x.val << "}";
        return cout;
    }
};

template<typename T>
T exp(T a, ll b, int m) {
    T res = 1;
    a %= m;
    for (; b > 0; a *= a, a %= m, b >>= 1) {
        if (b & 1) {
            res *= a;
            res %= m;
        }
    }
    return res;
}

void exit(const std::string& s = "error") {
    std::cerr << s;
    std::exit(EXIT_FAILURE);
}

void solve() {
    int n, m, seed, vmax;
    std::cin >> n >> m >> seed >> vmax;

    auto rnd = [&] () {
        int ret = seed;
        seed = (1ll * seed * 7 + 13) % mod;
        return ret;
    };

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = (rnd() % vmax) + 1;
    }

    std::set<Interval> intervals;
    for (int i = 1; i <= n; i++) {
        intervals.insert({.lb = i, .ub = i, .val = a[i]});
    }

    auto find = [&] (int l, int r) {
        std::vector<Interval> contained;
        for (auto it = intervals.lower_bound({.ub = l}); it != intervals.end() && it->lb <= r; it++) {
            contained.push_back(*it);
        }
        return contained;
    };

    auto op1 = [&] (int l, int r, ll x) {
        auto contained = find(l, r);
        for (auto i : contained) {
            intervals.erase(i);
            if (i.lb < l && i.ub > r) {
                intervals.insert({.lb = i.lb, .ub = l - 1, .val = i.val});
                intervals.insert({.lb = r + 1, .ub = i.ub, .val = i.val});
                intervals.insert({.lb = l, .ub = r, .val = i.val + x});
            }
            else if (i.lb < l && i.ub <= r) {
                intervals.insert({.lb = i.lb, .ub = l - 1, .val = i.val});
                intervals.insert({.lb = l, .ub = i.ub, .val = i.val + x});
            }
            else if (i.lb >= l && i.ub > r) {
                intervals.insert({.lb = r + 1, .ub = i.ub, .val = i.val});
                intervals.insert({.lb = i.lb, .ub = r, .val = i.val + x});
            }
            else if (i.lb >= l && i.ub <= r) {
                intervals.insert({.lb = i.lb, .ub = i.ub, .val = i.val + x});
            }
            else {
                exit();
            }
        }
    };

    auto op2 = [&] (int l, int r, ll x) {
        auto contained = find(l, r);
        for (auto i : contained) {
            intervals.erase(i);
            if (i.lb < l) {
                intervals.insert({.lb = i.lb, .ub = l - 1, .val = i.val});
            }
            if (i.ub > r) {
                intervals.insert({.lb = r + 1, .ub = i.ub, .val = i.val});
            }
        }
        intervals.insert({.lb = l, .ub = r, .val = x});
    };

    auto op3 = [&] (int l, int r, int x) {
        auto contained = find(l, r);
        auto cmp = [&] (const Interval& x, const Interval& y) {
            return x.val > y.val; 
        };
        std::sort(contained.begin(), contained.end(), cmp);

        for (;;) {
            auto i = contained.back();
            int len = std::min(i.ub, r) - std::max(i.lb, l) + 1;
            if (x <= len) {
                std::cout << i.val << "\n";
                return;
            }
            x -= len;
            contained.pop_back();
        }
    };

    auto op4 = [&] (int l, int r, int x, int y) {
        auto contained = find(l, r);
        ll res = 0;
        for (auto i : contained) {
            int len = std::min(i.ub, r) - std::max(i.lb, l) + 1;
            res += exp(i.val, x, y) * len;
        }
        std::cout << res % y << "\n";
    };

    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        int op = (rnd() % 4) + 1;

        int l = (rnd() % n) + 1;
        int r = (rnd() % n) + 1;
        if (l > r) {
            std::swap(l, r);
        }
        
        int x = (op == 3) ? (rnd() % (r - l + 1)) + 1 : (rnd() % vmax) + 1;

        int y = 0;
        if (op == 4) {
            y = (rnd() % vmax) + 1;
        }

        if (op == 3 || op == 4) {
            ++cnt;
        }

        switch (op) {
        case 1:
            op1(l, r, x);
            break;
        case 2:
            op2(l, r, x);
            break;
        case 3:
            op3(l, r, x);
            break;
        case 4:
            op4(l, r, x, y);
            break;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
