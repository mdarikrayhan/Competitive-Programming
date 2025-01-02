#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;

bool test(ll cand, ll len, ll wid) {

}

void solve() {
    ll w, l; cin >> w >> l;
    set<int> vals;
    

    for (ll i = 1; i * i <= l; ++i) {
        if (l % i == 0) {
            if ((w - 2) % i == 0)
                vals.insert(i);

            if ((l-2) % (i) == 0) {
                // inverse
                if (w % i == 1) {
                    vals.insert(i);
                }
            }
            
            ll div = l / i;
            if ((w - 2) % div == 0)
                vals.insert(div);
            
            if ((l-2) % (div) == 0) {
                // inverse
                if (w % div == 1) {
                    vals.insert(div);
                }
            }
        }
    }


    for (ll i = 1; i * i <= (l-1); ++i) {
        if ((l-1) % i == 0) {
            if ((w - 1) % i == 0)
                vals.insert(i);

            if (w % i == 0 && (w - 2) % i == 0) {
                vals.insert(i);
            }
            
            ll div = (l-1) / i;
            if ((w - 1) % div == 0)
                vals.insert(div);
            

            if (w % div == 0 && (w - 2) % div == 0) {
                vals.insert(div);
            }
        }
    }


    for (ll i = 1; i * i <= (l-2); ++i) {
        if ((l-2) % i == 0) {
            if ((w) % i == 0)
                vals.insert(i);
            
            ll div = (l-2) / i;
            if ((w) % div == 0)
                vals.insert(div);
        }
    }

    cout << vals.size() << " ";
    for (auto x : vals)
        cout << x << " ";
    cout << endl;
    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}