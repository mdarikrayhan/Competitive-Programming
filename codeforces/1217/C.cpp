#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define all(x) x.begin(), x.end()
 
#ifndef ONLINE_JUDGE
#include "dbg.cpp"
#else
#define debug(...)
#endif

// only take subarray of number 18
void solve(){
    string s; cin >> s;
    int n = s.size();
    vector<int>prefix(n, 0);
    for(int i = 0; i < n; i++){
        int cnt = 0;
        while(i < n and s[i] == '0') cnt++, i++;
        if(i < n) prefix[i] = cnt;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            for(int j = i; j < min(n, i + 18); j++){
                int num = 0;
                for(int k = j; k >= i; k--){
                    if(s[k] == '1') num += (1LL << (j - k));
                }
                if(num - (j - i + 1) <= prefix[i]) ans++;
            }
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
    while(t--){
        solve();
    }
    return 0;
}