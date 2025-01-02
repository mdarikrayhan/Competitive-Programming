#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<ll>
#define vvi vector<vi>
#define pb push_back
#define pi pair<ll, ll>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define abs std::abs
#define fi first
#define se second
#define sq(a) ((a) * (a))
#define sz(a) (ll) a.size()

void solve() {

    ll n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto &x : v)
        cin >> x;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (i != j && v[i][j] == v[j][i]) {
                cout << "YES" << endl;
                for (ll k = 0; k <= m; k++) {
                    cout << i + 1 << " ";
                    k++;
                    if (k <= m)
                        cout << j + 1 << " ";
                }
                cout << endl;
                return;
            }
        }
    }
    if (m & 1) {
        cout << "YES" << endl;
        for (ll k = 0; k <= m; k++) {
            cout << 1 << " ";
            k++;
            if (k <= m)
                cout << 2 << " ";
        }
        cout << endl;
        return;
    }
    ll ai  = -1, bi = -1, ao = -1, bo = -1;
    ll x = -1, y = -1, z = -1;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (i == j)
                continue;
            if (v[j][i] == 'a')
                ai = j;
            else 
                bi = j;
            if (v[i][j] == 'a')
                ao = j;
            else
                bo = j;
        }
        if (ai != -1 && ao != -1) {
            x = ai, y = i, z = ao;
            break;
        }
        else if (bi != -1 && bo != -1) {
            x = bi, y = i, z = bo;
            break;
        }
        else {
            ai = -1, ao = -1, bi = -1, bo = -1;
        }
    }
    if (z == -1) {
        cout << "NO" << endl;
        return;
    }
    swap(y, z);
    cout << "YES" << endl;
    if (m / 2 % 2) {
        for (ll k = 0; k < m + 1; k++) {
            if (k % 4 == 0)
                cout << x + 1 << " ";
            else if (k % 4 == 2)
                cout << y + 1 << " ";
            else
                cout << z + 1 << " ";
        }
        cout << endl;
        return;
    }
    cout << z + 1 << " ";
    for (ll k = 0; k < m / 2; k++) {
        if (k % 2)
            cout << z + 1 << " ";
        else 
            cout << y + 1 << " ";
    }
    for (ll k = 0; k < m / 2; k++) {
        if (k % 2)
            cout << z + 1 << " ";
        else 
            cout << x + 1 << " ";
    }
    cout << endl;

}

signed main() {
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("io/input.txt", "r", stdin);
        freopen("io/output.txt", "w", stdout);
        freopen("io/error.txt", "w", stderr);
    #endif
    ll T;
    cin >> T;
    while (T--)
        solve();
    cerr << "Time:" << 1000 * ((double) clock()) / (double) CLOCKS_PER_SEC << "ms\n";
    return 0;
}