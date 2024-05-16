#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    cout << n - k + (k/2) << endl;
    for(int i=(k+1)/2; i<k; i++){
        cout << i << " ";
    }
    for(int i=k+1; i<=n; i++){
        cout << i << " \n"[i == n];
    }
}

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}