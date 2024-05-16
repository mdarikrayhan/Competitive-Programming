///  जय सिया राम

#include <bits/stdc++.h>
using namespace std;

int mod;

int add(int x, int y){
    return (1ll * x + 1ll * y + 1ll * mod) % mod;
}

int mul(int x, int y){
    return (1ll * x * y) % mod;
}

int binExp(int a, int e){
    int res = 1;
    while(e){
        if(e & 1) res = mul(res, a);
        a = mul(a, a);
        e >>= 1;
    }
    return res;
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    for(int i = 0; i < n - 1; i++){
        if(s[i] == 'R' and s[i + 1] == 'L'){
            cout << "0\n"; return;
        }
        if(s[i] == 'L' and s[i + 1] == 'R'){
            cout << i + 1 << "\n"; return;
        }
    }
    cout << "-1\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int32_t tc = 1;
    cin >> tc;
    while(tc--) solve();
    return 0;
}
