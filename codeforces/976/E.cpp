#include <bits/stdc++.h>

#define fi first
#define se second
using namespace std;
using ll = long long;

int main() {
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll n, a, b;
    cin >> n >> a >> b;
    vector <pair <ll, ll> > s(n);

    for(int i = 0; i < n; ++i) {
        cin >> s[i].first >> s[i].second;
    }

    sort(s.begin(), s.end(), [](const pair <ll, ll> l, const pair <ll, ll> r) {
        return l.fi - l.se > r.fi - r.se;
    });
    ll ans = 0;

    b = min(n, b);
    for(int i = 0; i < n; ++i) {
        if(i < b) {
            if(s[i].first < s[i].second) {
                ans += s[i].second;
            } else {
                ans += s[i].first;
            }
        } else {
            ans += s[i].second;
        }        
    }

    if(!a || !b) {
        cout << ans << "\n";
        return 0;
    }   
    //cout << ans << "\n";

    ll mx = ans;
    for(int i = 0; i < n; ++i) {
        if((s[i].first << a) <= s[i].second) {
            continue;
        }

        if(i < b) {
            ll p = max(s[i].first, s[i].second);
 
            mx = max(mx, ans - p + (s[i].first << a));
        } else {
            ll p = max(s[b - 1].first, s[b - 1].second);
 
            mx = max(mx, ans - p + s[b - 1].second + (s[i].first << a) - s[i].second);  
        }
    }

    cout << mx << "\n";
    return 0;
}
