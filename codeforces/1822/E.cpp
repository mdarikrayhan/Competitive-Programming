#include <bits/stdc++.h> 
#define int long long
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define SORT(c) sort(all(c))
#define rSORT(c) sort(rall(c))
#define f first
#define s second
#define pb push_back
#define endl "\n"
using namespace std;
void solve();
int32_t main(){ios::sync_with_stdio(false);cin.tie(0);int t = 1;int i = 1;
    cin >> t;
    while(t--){//cout<<"_________________________________\n";cout<<"Test case Number: "<<i++<<endl<<endl;
        solve();
    }
}
void solve(){
    int n;cin >> n;
    string s;cin >> s;
    if(n % 2 == 1){cout << -1 << endl;return;}
    vector<int> f(26,0);
    vector<int> ff(26,0);
    int sum = 0;
    for(int i = 0;i<n;i++){
        f[s[i] - 'a']++;
        if(f[s[i] - 'a'] > n/2){cout << -1 << endl;return;}
        if(i < n/2 and s[i] == s[n-i-1]){ff[s[i] - 'a']++;sum++;}
    }
    if(sum == 0){cout << 0 << endl;return;}
    int ans = 0;
    for(int i = 0;i<26;i++){
        if(ff[i] > sum/2){
            int left = (sum - ff[i]);
            ans += ff[i] - left;
            ans += left;
            cout << ans << endl;
            return;
        }
    }
    cout << (sum + 1)/2  << endl;
}