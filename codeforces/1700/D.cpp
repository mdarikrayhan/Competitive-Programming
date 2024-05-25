#include <bits/stdc++.h>
using namespace std;

typedef __int128_t i128;
typedef int64_t i64;

std::ostream& operator<<(std::ostream& os, i128 n) {
    std::string s;
    while (n) {
        s += '0' + n % 10;
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, vector<T>& a) {
    for (T i : a) os << i << " ";
    return os << "\n";
}

template <typename T>
std::istream& operator>>(std::istream& is, vector<T>& a) {
    for (T& i : a) is >> i;
    return is;
}

void print(string s) {
    cout << s << " ";
}

void println(string s) {
    cout << s << "\n";
}

void printno() {
    cout << "NO\n";
}

void printyes() {
    cout << "Yes\n";
}

void solve() {
    i64 n;
    cin >> n;

    vector<i64> a(n);
    cin >> a;

    i64 q;
    cin >> q;

    i64 sum = 0;
    for (int i : a) {
        sum += i;
    }

    int ans = 0;
    i64 l = 1, r = 2e9;

    auto check = [&](i64 x) {
        i64 sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (1LL * (i + 1) * x < sum) return false;
        }
        return true;
        };

    while (l <= r) {
        i64 m = l + (r - l) / 2;
        if (check(m)) {
            ans = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    // cout << "ans: " << ans << "\n";


    while (q--) {
        i64 x;
        cin >> x;

        bool can = true;


        if (x < ans) {
            cout << "-1\n";
            continue;
        }

        cout << (sum + x - 1) / x << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}