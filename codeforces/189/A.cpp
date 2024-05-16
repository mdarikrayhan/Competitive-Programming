//Ctrl + Shift + B to run.
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define pb push_back 

string yes="YES", no="NO";

void solve(){
    int n, res = 1;
    int a[3];
    cin>>n>>a[0]>>a[1]>>a[2];
    sort (a, a+3, greater <int>());
    for (int i=0; i<=4000; i++){
        for (int j=0; j<=4000; j++){
            int k, tmp = (n-a[0]*i-a[1]*j);
            if (tmp>=0 && tmp%a[2]==0){ 
                k = tmp/a[2];
                res = max(res, i+j+k);
                // cout << i << " "<< j << " " << k << endl;
            }
        }
    }
    cout << res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int t; 
    // cin>>t;
    // while (t--) 
    solve();
    return 0;
}