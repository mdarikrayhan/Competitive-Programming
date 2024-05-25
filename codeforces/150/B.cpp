#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()


class Shadow {
public:
    static void Files() {
#ifndef ONLINE_JUDGE
        freopen("../INPUT.txt", "r", stdin);
        freopen("../OUTPUT.txt", "w", stdout);
        freopen("../BacKDooR.txt", "w", stderr);
#endif
    }

    static void Fast() {
        ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    }
};


//-----------------------------------------------------`|||`-----------------------------------------------------\\
\\-----------------------------------------------------`\|/`-----------------------------------------------------//
const int N = 3e5 + 3, F = 1e6 + 3, mod = 1e9 + 7, inf = 1e8;

ll fastPower(ll a, ll b, ll M = mod) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans *= a, ans %= M;
        a *= a, a %= M;
        b >>= 1;
    }
    return ans;
}

class dsu {
private:
    vector<int> parent, sz;
    int n;

public:
    dsu() = default;

    dsu(int n) : n(n), parent(n), sz(n, 1) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (sz[y] > sz[x]) swap(x, y);
        parent[y] = x;
        sz[x] += sz[y];
        --n;
    }

    int sets() const { return n; }

    bool connected(int x, int y) { return find(x) == find(y); }
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    dsu s(n);
    for (int i = 0; i < n - k + 1; ++i) {
        int l = i, r = k + i - 1;
        while (l < r) {
            s.unite(l, r);
            ++l, --r;
        }
    }
    cout << fastPower(m, s.sets()) << '\n';
}


int main() {
    Shadow::Fast();
    Shadow::Files();
    int T = 1;
//    cin >> T;
    while (T--) solve();
    return 0;
}
	 	  	            	 	  			  	