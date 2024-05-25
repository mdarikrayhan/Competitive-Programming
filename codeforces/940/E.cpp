#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, c; cin >> n >> c;
    vector<int> arr(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    if(c == 1) {
        cout << 0 << endl;
    }
    else if(c > n){
        cout << sum << endl;
    }
    else{
        vector<int> dp(n);
        //dp[i] --> maximum sum that can be removed in the prefix (0...i)
        multiset<int> st;
        vector<int> mini(n, 0);
        for(int i = 0; i < c; i++){
            st.insert(arr[i]);
        }
        mini[c-1] = *st.begin();
        for(int i = c; i < n; i++){
            st.erase(st.find(arr[i-c]));
            st.insert(arr[i]);
            mini[i] = *st.begin();
        }
        dp[0] = 0; //base case
        for(int i = 1; i < n; i++){
            dp[i] = dp[i-1];
            int pref = 0;
            if((i-c) >= 0) pref = dp[i-c];
            dp[i] = max(dp[i], pref + mini[i]);
        }
        cout << sum - dp[n-1] << endl;
    }
}