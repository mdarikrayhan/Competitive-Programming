// Gagandeep Singh

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define inputVector(v, n) for(int i = 0; i < n; i++) cin >> v[i]
#define input2dArray(arr, n, m) for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> arr[i][j]
#define printVector(v, n) for(int i = 0; i < n; i++) cout << v[i] << " "; cout << endl
const int MOD = 1e9 + 7;

void solve() {
    map<string, pair<string, bool>> mp;
    mp["purple"] = {"Power", false};
    mp["green"] = {"Time", false};
    mp["blue"] = {"Space", false};
    mp["orange"] = {"Soul", false};
    mp["red"] = {"Reality", false};
    mp["yellow"] = {"Mind", false};
    
    int n; cin >> n;
    while(n--) {
        string s; cin >> s;
        mp[s].second = true;
    }
    
    int count = 0;
    for(auto it : mp) {
        if(it.second.second == false) {
            count++;
        }
    }
    cout << count << endl;
    
    for(auto it : mp) {
        if(it.second.second == false) {
            cout << it.second.first << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}