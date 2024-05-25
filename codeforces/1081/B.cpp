#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pl;

const ll N = 1e5 + 10;
vector<ll> oc[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    for(ll i = 0; i < n; i++) {
        ll a; cin >> a;
        oc[a].push_back(i);
    }
    bool ok = true;
    for(ll i = 0; i < n; i++) {
        if(oc[i].size() > 0 && oc[i].size() % (n - i) != 0) ok = false;
    }
    if(!ok) { cout << "Impossible\n"; exit(0); }
    cout << "Possible\n";
    vector<ll> ans(n);
    ll col = 0;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < oc[i].size(); j++) {
            if(j % (n - i) == 0) col++;
            ans[oc[i][j]] = col;
        }
    }
    for(ll i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";
}