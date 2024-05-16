#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1000000007;

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    int ans = 0;
    for(int i=1; i<n; i++){
        ans += abs(a[i] - a[i-1]);
    }
    int mini = min(ans - abs(a[1]-a[0]), ans - abs(a[n-1]-a[n-2]));
    for(int i=1; i<n-1; i++){
        mini = min(mini, ans - abs(a[i]-a[i-1]) - abs(a[i]-a[i+1]) + abs(a[i-1]-a[i+1]));
    }
    cout<<mini<<endl;
} 

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}