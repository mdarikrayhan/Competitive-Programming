#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, m; cin >> n >> m;
    if(n == 1 || m == 1){
        cout << max(n,m)- 1;
    }
    else cout << n*(m-1);
}