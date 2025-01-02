#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long


void solve (){
    int q;
    cin >> q;
    if(q==1){
        cout << 1;
    }else{
        for (int i = 2; i <= q+1; i++)
        {
            cout << i << " ";
        }
    }
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
    return 0;
}
