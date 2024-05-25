#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }
    int cnt = 0, curr;
    vector<bool> vis(n, false);
    for(int i = 0; i < n; i++){
        curr = i;
        if(vis[curr]) continue;
        cnt++;
        while(!vis[curr]){
            vis[curr] = true;
            curr = a[curr];
        }
    }
    if((n - cnt)%2 == (7 * n + 1)%2) cout << "Um_nik";
    else cout << "Petr";
}
