#include "bits/stdc++.h"
using namespace std;

#define int     long long


void  solve() {
 
int n, m;
cin >> n >>m;

vector<int> w(n), b(m);

for(int i = 0; i < n; i++){
    cin >> w[i];
}
for(int i = 0; i < m; i++){
    cin >> b[i];
    b[i]--;
    
}

int ans = 0;


for(int i = 0; i < m; i++){
    
    set<int> st;
    for(int j = i -1 ; j >= 0; j--){
        if(b[j] == b[i]){
            break;
        }
        st.insert(b[j]);
    }
    
    for(int x : st){
        ans += w[x];
    }
}

cout << ans << endl;




}



signed  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t = 1;
   // cin >> t;
    while (t--)solve();

    return 0;
}

