#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long


void solve (){
    int q;
    cin >> q;
    if(q%3==0){
        cout << 1 << " " << 1 << " " << q-2;
    }else{
        cout << 1 << " " << 2 << " " << q-3;
    }
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
    return 0;
}
