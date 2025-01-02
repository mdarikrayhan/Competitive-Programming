#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MIN = LONG_LONG_MIN;
void func(){
    int n, p, k;
    ll x, y;
    string s;
    cin >> n >> p >> k >> s >> x >> y;
    int suff[n];
    for(int i = n - 1; i >= 0; i--){
        suff[i] = (s[i] == '1' ? 0 : x) + (i + k < n ? suff[i + k] : 0);
    }
    ll res = 1e15;
    for(int i = 0; i + p - 1 < n; i++){
        res = min(res, i * y + suff[i + p - 1]);
    }
    cout << res << endl;
}   
int main(){
    int t = 1;
    cin >> t;
    while (t--){
        func();
    }
    return 0;
}

// 1 + 3 + 1