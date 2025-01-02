#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    if (m == 3 && n > 4) {
        cout << "-1\n";
        return;;
    }
    if (m == 4 && n > 6) {
        cout << "0 0\n6 0\n0 6\n6 6\n4 1\n1 2\n2 5" << (n > 7 ? "\n5 4\n" : "\n");
        return;
    }
    int r = 27625;
    vector<int> x, y;
    for (int j = 1; j < r; ++j) {
        int v = r * r - j * j, sq = sqrt(v);
        if (sq * sq == v) x.push_back(j), y.push_back(sq);
    }
    int t = m, dx = 1, dy = 1, id = 1;
    for (int i = 0; i < 2 * x.size() && t; ++i) {
        cout << x[i / 2] * dx << ' ' << y[i / 2] * dy << '\n', --t;
        swap(dx, dy), dy = -dy;
    }
    t = n - m, dx = 1, dy = 1;
    for (int i = 0; i < 2 * x.size() && t; ++i) {
        cout << x[i / 2] * dx * 3000 << ' ' << y[i / 2] * dy * 3000 << '\n', --t;
        swap(dx, dy), dy = -dy;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
//    cin >> tc;
    for (int i = 1; i <= tc; ++i) {
        solve();
    }
}
    	 	 	   	  	 	 	  		 			 	