#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i=0; i<n; i++){
        a[i] = n - i;
    }

    if(k >= (n + 1) / 2){
        cout << -1 << endl;
        return;
    }

    int b = 0;
    while(k--){
        swap(a[b], a[b + 1]);
        b += 2;
    }

    for(int i=0; i<n; i++){
        cout << a[i] << " \n"[i == n - 1];
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