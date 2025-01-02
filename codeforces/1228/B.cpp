#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define vl vector<ll>
#define pb push_back
#define all(v) v.begin(), v.end()
using namespace std;

const ll sz = 2e5 + 5 , inf = 1e18, mod = 1e9 + 7;

ll a[1005][1005];

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    memset(a, -1, sizeof(a));
    for(int i = 0; i < n; i ++){
        ll tm; cin >> tm;
        for(int j = 0; j < tm; j ++){
            a[i][j] = 1;
        }
        a[i][tm] = 0;
    }
    for(int i = 0; i < m; i ++){
        ll tm; cin >> tm;
        for(int j = 0; j < tm; j ++){
            if(a[j][i] == 0){cout << 0; return ;}
            a[j][i] = 1;
        }
        if(a[tm][i] == 1){cout << 0; return ;}
        a[tm][i] = 0;
    }
    ll res = 0;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            if(a[i][j] == -1){
                res ++;
            }
        }
    }
    cout << binpow(2, res, mod);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test = 1;
    //cin >> test;
    for(int tst = 1; tst <= test; tst++) {
        solve();
        cout << endl;
    }
    return 0;
}
