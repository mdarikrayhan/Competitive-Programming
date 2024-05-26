/* Author: izhang
 * Time: 05-25-2024 21:08:04
**/
#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    string s, t;
    cin >> s >> t;
    int n = int(s.size()), m = int(t.size());
    int cur = 0, first = n;
    for (int i = 0; i < m; ++i) {
        if (t[i] == s[cur]) {
            ++cur;
        }
        if (cur == n) {
            first = i;
            break;
        }
    }
    dbg() << cur;
    int last = -1;
    cur = n - 1;
    for (int i = m - 1; i >= 0; --i) {
        if (t[i] == s[cur]) {
            --cur;
        }
        if (cur == -1) {
            last = i;
            break;
        }
    }
    dbg() << first << " " << last;
    cout << max(0, last - first) << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
