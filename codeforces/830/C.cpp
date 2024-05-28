#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
// typedef __int128 lll;
// typedef __float128 lld;
using namespace std;

ll ceil_div(ll a, ll b){
    return (a + b - 1) / b;
}

bool is_valid(vector<ll>& a, ll k, ll d) {
    ll sum = 0;
    for(int i = 0; i < a.size(); i++){
        sum += d * ceil_div(a[i], d) - a[i];
    }
    return sum <= k;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> b(0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        for(int j = 1; j * j <= a[i]; j++){
            b.push_back(j);
            b.push_back(ceil_div(a[i], j));
        }
        k += a[i];
    }
    sort(b.begin(), b.end());
    ll ans = 1;
    for(int i = 0; i < b.size(); i++){
        if(i != 0 && b[i] == b[i - 1]){
            continue;
        }
        ll d = b[i];
        ll divsum = 0;
        for(int j = 0; j < n; j++){
            divsum += ceil_div(a[j], d);
        }
        if(k / divsum >= d){
            ans = max(ans, k / divsum);
        }
    }
    cout << ans << "\n";
    
    return 0;
}