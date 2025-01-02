#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define vvi vector<vector<int>>
const int mod = 1e9+7;
void solve(){
    int n;
    cin >> n;
    vector<int> arr(2*n);
    for (int i = 1; i <= n; i++) arr[i-1] = i;
    int p = 0,d;
    for (int i = 2; i <= n; i++){
        d = -1;
        for (int j = 0; j < n; j += i)
            swap(d,arr[j+p]);
        arr[p+n] = d;
        p++;
    }
    for (int i = p; i < n+p; i++)
        cout << arr[i] << " ";
    cout << endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--){
        // cout << "Case #1:"
        solve();
    }
    return 0;
}