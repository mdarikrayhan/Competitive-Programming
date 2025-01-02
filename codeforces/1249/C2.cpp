#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

ll ans = 0;
bool is_valid(ll mid , ll n){
    ll power = 1 , cal = 0;
    for(ll i = 0 ; i < 39 ; i++){
        if(mid & (1LL << i)) cal += power;
        power *= 3;
    }
    
    ans = cal;
    return cal >= n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll testcases;
    cin >> testcases;
    while (testcases--) {

        ll n;
        cin >> n;
        
        ll low = 0 , high = 1e16;
        
        while(high - low > 1){
            ll mid = (high + low) >> 1;
            if(is_valid(mid , n)) high = mid;
            else low = mid;
        }
        
        if(is_valid(low , n)) cout << ans << "\n";
        else{
            is_valid(high , n);
            cout << ans << "\n";
        }



    }
    return 0;
}
// Author : Raj_Singh