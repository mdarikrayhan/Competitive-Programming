#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MASK(x) (1LL << (x))
#define BIT(x, i) (((x) >> (i)) & 1)
#define sz(x) (int) (x).size()
#define all(a) (a).begin(), (a).end()
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, n) for (int i = 0; i < (n); i++)

template <class X, class Y>
    bool maximize(X &x, Y y) {
        if (x < y) return x = y, true;
        else return false;
    }

template <class X, class Y>
    bool minimize(X &x, Y y) {
        if (x > y) return x = y, true;
        else return false;
    }

const int maxn = (int) 2e5 + 2;

pair <int, int> a[maxn + 2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        FOR(i, 1, n) cin >> a[i].first;
        FOR(i, 1, n) cin >> a[i].second;

        sort(a + 1, a + 1 + n);

        int SQRT = (int) sqrt(2 * n);

        vector <vector <int>> cnt(SQRT + 2, vector <int> (n + 2, 0));

        ll ans = 0;
        FOR(i, 1, n) {
            FOR(d, 1, SQRT) {
                int x = a[i].first * d - a[i].second;
                if (x > 0 && x <= n) {
                    ans += (ll) cnt[d][x];
                }
            }
            if (a[i].first <= SQRT) cnt[a[i].first][a[i].second]++;
        }

        cout << ans << "\n";
    }

    return 0;
}

/** Discipline will take you to places where motivation can't **/
