#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long LL;

void solve(){  
    int n,res = 0;
    cin >> n;
    while(n){
        res = max(n % 10,res);
        n /= 10;
    }
    cout << res << endl;



} 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}