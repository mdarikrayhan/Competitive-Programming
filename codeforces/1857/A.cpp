#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n; 
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    int cnt = 0;
    for(auto it: v) if(it&1) cnt++;

    if(cnt&1) cout << "no" << endl;
    else cout << "yes" << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r",stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}