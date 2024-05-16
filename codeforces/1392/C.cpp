#include<bits/stdc++.h>
using namespace std;
#define  int       long long
void solve(){
    int n; cin >> n;
    vector < int > v(n);
    for(int i = 0; i < n; i++)
    cin >> v[i];
    int pos = -1 , flag = 0;
    int ans = 0;
    for(int i = 0; i < n - 1; i++){
        int val = v[i] - v[i + 1];
        ans += max((int)0 , val);
    }
    cout << ans << endl;
}
int32_t main(){
    int t; cin >> t;
    while(t--)
    solve();
}