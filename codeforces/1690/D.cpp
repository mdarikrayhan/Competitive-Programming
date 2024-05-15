#include<bits/stdc++.h>
#include<vector>
#define ll long long int
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<ll> preSum(n + 1);
        for(int i = 1; i <= n; i++) {
            ll curr = 0;
            if(s[i - 1] == 'W') {
                curr = 1;
            }
            preSum[i] = preSum[i - 1] + curr;
        }
        ll min_diff = INT_MAX;
        for(int i = k; i <= n; i++) {
            ll curr = preSum[i] - preSum[i - k];
            min_diff = min(min_diff, curr);
        }
        cout << min_diff << endl;
    }
}