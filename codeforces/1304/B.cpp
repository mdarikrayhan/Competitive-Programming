#include <bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
#define ull unsigned long long
#define int long long
#define pb push_back
#define pf push_front
#define inp freopen("input.txt", "r", stdin)
#define outp freopen("output.txt", "w", stdout)
#define MOD 1000000007
#define EPS 1e-18
 
int dx[8] = {0,  0, 1, -1, 1,  1, -1, -1};
int dy[8] = {1, -1, 0,  0, 1, -1,  1, -1};
 
const int N = 1e5 + 1, INF = 0x3f3f3f3f;
const double PI = 3.141592653;

bool palin(string s) {
    int l = 0, r = s.length() - 1;
    while(l < r) {
        if(s[l] != s[r]) return false;
        l++, r--;
    }

    return true;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m; cin >> n >> m;
    vector<string> v(n), ans;
    map<string, int> freq;

    string mid = "";
    for(int i = 0; i < n; i++) {
        cin >> v[i];

        string tmp = v[i];
        bool found = 0;
        reverse(tmp.begin(), tmp.end());
        if(freq[tmp]) {
            freq[tmp]--;
            ans.pb(v[i]);
            found = 1;
        }

        if(!found && palin(v[i])) mid = v[i];
        else if(!found) freq[v[i]]++;
    }

    int len = ans.size() * 2 * m + mid.length();
    cout << len << endl;
    
    for(int i = 0; i < ans.size(); i++) cout << ans[i];
    cout << mid;
    for(int i = ans.size() - 1; i >= 0; i--) {
        reverse(ans[i].begin(), ans[i].end());
        cout << ans[i];
    }
    
    cout << endl;
}