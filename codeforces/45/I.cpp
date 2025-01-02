/* Author: izhang
 * Time: 05-25-2024 21:02:14
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
    int n;
    cin >> n;
    vector<int> a(n);
    int neg = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < 0) {
            ++neg;
        }
    }
    sort(a.begin(), a.end());
    vector<int> sol;
    for (int i = 0; i < (neg / 2) * 2; ++i) {
        sol.push_back(a[i]);
    }
    dbg() << neg;
    dbg() << a;
    for (auto &i : a) {
        if (i > 0) {
            sol.push_back(i);
        }
    }
    if (sol.empty()) {
        sol.push_back(a.back());
    }
//    cout << sol.size() << "\n";
    for (auto &i : sol) {
        cout << i << " ";
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
