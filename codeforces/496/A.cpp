#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int>v(n);
    int m = INT_MAX;
    for(int i = 0; i<n; i++){
        cin >> v[i];
    }
    if(n==3){
        cout << v[2]-v[0] << '\n';
    }
    else{
        int idx1 = 0;
        int idx2=0;
        for(int i = 0; i<n-2; i++){
            if(v[i+2]-v[i]<m){
                m = v[i+2]-v[i];
                idx1=i;
                idx2=i+2;
            }
        }
        auto it = v.begin() + idx1+1;
        v.erase(it);
        int mx = INT_MIN;
        for(int i = 0; i<n-1; i++){
            if(v[i+1]-v[i]>mx){
                mx = v[i+1]-v[i];
            }
        }
        cout << mx << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
