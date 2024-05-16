#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;



void solve(){
    int n,m;
    cin>>n>>m;
    char arr[n][m];
    for(int i =0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    int ans = 0;
    for(int i =0; i<n; i++){
        for(int j=0; j<m; j++){
            if((j == m-1 && arr[i][j] == 'R') || (i == n-1 && arr[i][j] == 'D')){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}


signed main(){
    IOS
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}