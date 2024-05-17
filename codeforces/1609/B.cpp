#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n'
using namespace std;
typedef long long ll;

void Approach(){
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    int ans = 0;
    for(int ii = 0; ii + 2 < n; ii++){
        if(s.substr(ii, 3) == "abc"){
            ans++;
        }
    }

    while(q--){
        int pos;
        cin >> pos;
        char ch;
        cin >> ch;

        pos -= 1;

        int index = pos - 2;

        if(index < 0)
            index = 0;

        for(int ii = index; ii <= pos; ii++){
            if(s.substr(ii, 3) == "abc")
                ans--;
        }

        s[pos] = ch;
        for(int ii = index; ii <= pos; ii++){
            if(s.substr(ii, 3) == "abc")
                ans++;
        }

        cout << ans << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    int T = 1;
    // cin >> T;
    for(int C = 1; C <= T; C++){
        Approach();
    }
    return 0;
}