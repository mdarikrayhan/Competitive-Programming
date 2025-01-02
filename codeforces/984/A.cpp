#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
 
 
void solve (){
    int a;
    cin >> a;
    int d[a];
    for(int i = 0;i<a;i++){
        cin >> d[i];
    }
    sort(d,d+a);
    if(a%2){
        cout << d[a/2];
    }else{
        cout << d[a/2-1];
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