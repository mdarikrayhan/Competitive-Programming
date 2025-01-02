#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define double long double
#define all(x) x.begin(), x.end()

using ll = long long int;

#ifndef ONLINE_JUDGE
#include "dbg.cpp"
#else
#define debug(...)
#endif

const int MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int plus = 0, minus = 0, cnt = 0, ovminus = 0;
        for(int j = i; j < n; j++){
            if(s[j] == '+') plus++, minus = 0;
            else ovminus++, minus++;
            cnt += (minus != 0 and minus % 2 == 0);
            if(plus <= ovminus and (ovminus - plus) % 3 == 0 and (ovminus - plus) / 3 <= cnt) ans++;
        }
    }
    cout << ans << endl;
}   

signed main(){
    #ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    #endif
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1; 
    cin >> t;
    while(t--) solve();
    return 0;
}