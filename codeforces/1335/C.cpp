#include<bits/stdc++.h>
using namespace std;
#define EL_NEMR ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
int main() {
    EL_NEMR
    int t; cin >> t;
    while(t--){
        int n, mx_freq = -1; cin >> n;
        map<int, int>mp;
        for(long long i = 0, num; i<n; ++i)
            cin >> num, ++mp[num], mx_freq = max(mx_freq, mp[num]);
        int ans = mx_freq-1; // mp.size() == mx_freq
        if(mx_freq>mp.size())
            ans = mp.size();
        else if(mp.size() >= mx_freq+1)
            ans = mx_freq;
        cout << ans << '\n';
    }
}