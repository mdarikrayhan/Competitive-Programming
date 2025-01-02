#include <algorithm>
#include <iostream>
#include <optional>
#include <vector>

using namespace std;

using ll = long long;

template <ll M>
struct modular {
    ll val;

    modular() : val(0) {}

    // n >= 0
    modular(const ll n) {
        if (n < M)
            val = n;
        else if (n < 2 * M)
            val = n - M;
        else
            val = n % M;
    }

    [[nodiscard]] modular operator +(const modular& rhs) const {
        return val + rhs.val;
    }

    [[nodiscard]] modular operator -(const modular& rhs) const {
        return val + M - rhs.val;
    }

    [[nodiscard]] modular operator *(const modular& rhs) const {
        return val * rhs.val;
    }

    // p >= 0
    [[nodiscard]] modular pow(const ll& p) const {
        if (p == 0)
            return 1;

        if (p % 2 == 0)
            return (*this * *this).pow(p / 2);
        else
            return *this * pow(p - 1);
    }

    [[nodiscard]] modular inv() const {
        return pow(M - 2);
    }

    [[nodiscard]] modular operator /(const modular& rhs) const {
        return *this * rhs.inv();
    }

    modular& operator +=(const modular& rhs) {
        return *this = *this + rhs;
    }

    modular& operator -=(const modular& rhs) {
        return *this = *this - rhs;
    }

    modular& operator *=(const modular& rhs) {
        return *this = *this * rhs;
    }

    modular& operator /=(const modular& rhs) {
        return *this = *this / rhs;
    }

    explicit operator ll() const {
        return val;
    }

    [[nodiscard]] bool operator ==(const modular& rhs) const = default;
};

template <ll M>
ostream& operator<<(ostream& os, const modular<M>& modular) {
    cout << modular.val;
    return os;
}

using mod = modular<1'000'000'007>;

mod const P = 137;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s, t;
	cin >> s >> t;

    vector<mod> t_pref(t.size() + 1);

    for (int i = 1; i <= t.size(); i++) {
        t_pref[i] = t_pref[i - 1] + P.pow(i - 1) * t[i - 1];
    }

    auto const substrs_equal = [&](int const i1, int const i2, int const len) -> bool {
        return (t_pref[i1 + len] - t_pref[i1]) * P.pow(i2) == (t_pref[i2 + len] - t_pref[i2]) * P.pow(i1);
    };

    int const r0_cnt = count(s.begin(), s.end(), '0');
    int const r1_cnt = s.size() - r0_cnt;

    int ans = 0;

    for (int r0_len = 1; r0_len * r0_cnt <= t.size(); r0_len++) {
        int const r1_len = (t.size() - r0_len * r0_cnt) / r1_cnt;

        if (r1_len == 0)
            continue;

        if (r0_cnt * r0_len + r1_cnt * r1_len != t.size())
            continue;

        vector<int> const r_cnt = { r0_cnt, r1_cnt };
        vector<int> const r_len = { r0_len, r1_len };
        vector<optional<int>> last_occurrence(2);

        int ti = 0;

        for (char const& c : s) {
            int const x = c - '0';

            if (last_occurrence[x] && !substrs_equal(ti, *last_occurrence[x], r_len[x])) {
                goto next;
            }

            last_occurrence[x] = ti;
            ti += r_len[x];
        }

        if (r0_len == r1_len && substrs_equal(*last_occurrence[0], *last_occurrence[1], r0_len))
            continue;

        ans++;

    next:;
    }

    cout << ans << "\n";
}
