#include<bits/stdc++.h>
using namespace std;

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        set<int> st;
        map<int,int> mp;
        for(int i = 0; i < n; i++ ){
            st.insert(a[i]);
            mp[a[i]]++;
        }

        int r = 0 , mx = -1;
        for(auto it : st ) {
            if( it == r ) r++;
            else {
                mx = r;
                break;
            }
        }
        if( mx == -1 ) mx = *(--st.end()) + 1;

        vector<int> dp(mx + 1 , 1e9);
        dp[mx] = 0;
        for(int i = mx - 1; i >= 0; i-- ) {
            for(int j = i + 1; j <= mx; j++ ) {
                dp[i] = min( dp[i] , dp[j] + j*(mp[i] - 1) + i );
            }
        }
        
        cout << dp[0] << endl;
    }
}