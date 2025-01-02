#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    string s;
    cin >> s;

    char temp = s[0];
    int ans = temp == '0' ? 1 : 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] != temp){
            s[i] == '0' ? ans++ : ans;
        }
        temp = s[i];
    }

    cout << min(ans, 2ll) << endl;
}

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}