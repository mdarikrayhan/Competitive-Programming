#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define fi first
#define se second
#define pp push_back
#define all(x) (x).begin(), (x).end()
#define Ones(n) __builtin_popcount(n)
#define endl '\n'
#define mem(arrr, xx) memset(arrr,xx,sizeof arrr)
//#define int long long
#define debug(x) cout << (#x) << " = " << x << endl

void Gamal() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef Clion
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}

int dx[] = {+0, +0, -1, +1, +1, +1, -1, -1};
int dy[] = {-1, +1, +0, +0, +1, -1, +1, -1};

const double EPS = 1e-9;
const ll OO = 0X3F3F3F3F3F3F3F3F;
const int N = 2e5 + 5, INF = INT_MAX, MOD = 1e9 + 7, LOG = 20;


vector<array<int, 4>> transform(int n, int m, vector<vector<deque<char>>> &base) {
    vector<array<int, 4>> ops;
    for (int i = 1; i < n; ++i) {
        while (!base[i][0].empty()) {
            base[0][0].push_front(base[i][0].back());
            base[i][0].pop_back();
            ops.push_back({i, 0, 0, 0});
        }
    }
    for (int i = 1; i < m; ++i) {
        while (!base[0][i].empty()) {
            base[0][0].push_front(base[0][i].back());
            base[0][i].pop_back();
            ops.push_back({0, i, 0, 0});
        }
    }
    while (!base[0][0].empty()) {
        int nx = 0, ny = m - 1;
        if (base[0][0].back() == '0') {
            nx = n - 1;
            ny = 0;
        }
        base[nx][ny].push_front(base[0][0].back());
        base[0][0].pop_back();
        ops.push_back({0, 0, nx, ny});
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!i || !j)continue;
            while (!base[i][j].empty()) {
                if (base[i][j].back() == '1') {
                    base[0][m - 1].push_front(base[i][j].back());
                    base[i][j].pop_back();
                    ops.push_back({i, j, 0, j});
                    if (j != m - 1)ops.push_back({0, j, 0, m - 1});
                } else {
                    base[n - 1][0].push_front(base[i][j].back());
                    base[i][j].pop_back();
                    ops.push_back({i, j, i, 0});
                    if (i != n - 1)ops.push_back({i, 0, n - 1, 0});
                }
            }
        }
    }
    return ops;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<deque<char>>> base(n, vector<deque<char>>(m));
    vector<vector<deque<char>>> target(n, vector<deque<char>>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            string s;
            cin >> s;
            base[i][j] = deque<char>(all(s));
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            string s;
            cin >> s;
            reverse(all(s));
            target[i][j] = deque<char>(all(s));
        }
    }

    vector<array<int, 4>> ops = transform(n, m, base);
    vector<array<int, 4>> ops2 = transform(n, m, target);
    reverse(all(ops2));
    cout << ops.size() + ops2.size() << endl;
    for (auto &op: ops) {
        cout << op[0] + 1 << ' ' << op[1] + 1 << ' ' << op[2] + 1 << ' ' << op[3] + 1 << endl;
    }
    for (auto &op: ops2) {
        swap(op[0], op[2]);
        swap(op[1], op[3]);
        cout << op[0] + 1 << ' ' << op[1] + 1 << ' ' << op[2] + 1 << ' ' << op[3] + 1 << endl;
    }
}


signed main() {
    Gamal();
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}
	  	  	     			 	 		 		 			  		