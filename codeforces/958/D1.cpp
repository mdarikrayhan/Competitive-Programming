#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
    int n; cin >> n;
    map<double, int>m;
    vector<double>vec;
    for(int i = 0; i < n; i++){
        char c; cin >> c;
        double a; cin >> a;
        cin >> c;
        double b; cin >> b;
        cin >> c;
        cin >> c;
        double d; cin >> d;
        double val = (a+b)/d;
        vec.push_back(val);
        if(!m.count(val)){
            m[val] = 1;
        }else m[val]++;
        //cout << "i = " << i << " val = " << val << '\n';
    }

    for(auto i:vec){
        cout << m[i] << " ";
    }
    cout << '\n';
}
 
int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int tc = 1;
    //cin >> tc;
 
    while(tc--) solve();
    return 0;
}