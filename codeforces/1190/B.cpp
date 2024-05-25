#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sz(x) static_cast<int>((x).size())
#define all(x) begin(x), end(x)
const int mod = 1e9 + 7;


bool solve(){

    int n; cin >> n;
    
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    sort(all(a));

    vector<int> un = a;
    un.erase(unique(all(un)), end(un));

    if ((int)un.size() + 1 < n){
        return false;
    }

    if (n > 1 and a[1] == 0){
        return false;
    }

    for (int i = 2; i < n; i++){
        if (a[i] == a[i - 1] && a[i] - 1 == a[i - 2]){
            return false;
        }
    }

    int res = accumulate(all(a), 0LL) - (n) * (n - 1) / 2;

    return res & 1;
}


signed main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) cout << (solve() ? "sjfnb" : "cslnb") << '\n';
}