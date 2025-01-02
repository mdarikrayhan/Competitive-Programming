#include <bits/stdc++.h>
#ifdef SHARAELONG
#include "../../cpp-header/debug.hpp"
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n-1; ++j) {
            cout << (1 << (__builtin_ctz(j+1)*2 + 1)) << ' ';
        }
        cout << '\n';
    }
    for (int i=0; i<n-1; ++i) {
        for (int j=0; j<n; ++j) {
            cout << (1 << (__builtin_ctz(i+1)*2)) << ' ';
        }
        cout << '\n';
    }
    cout.flush();

    auto f = [n](int r, int x) {
        for (int i=0; i<r; ++i) {
            int tmp = 0;
            for (int j=i; j<r; ++j) tmp ^= (1 << (__builtin_ctz(j+1)*2));
            if (tmp == x) return i;
        }
        for (int i=r; i<n; ++i) {
            int tmp = 0;
            for (int j=r; j<i; ++j) tmp ^= (1 << (__builtin_ctz(j+1)*2));
            if (tmp == x) return i;
        }
        assert(false);
    };
    
    int r = 0, c = 0;
    for (int i=0; i<k; ++i) {
        int x;
        cin >> x;
        int rx = 0, cx = 0;
        for (int j=0; j<10; j+=2) {
            if (x & (1 << j)) rx ^= (1 << j);
        }
        for (int j=1; j<10; j+=2) {
            if (x & (1 << j)) cx ^= (1 << (j-1));
        }

        r = f(r, rx); c = f(c, cx);
        cout << r+1 << ' ' << c+1 << '\n';
        cout.flush();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
