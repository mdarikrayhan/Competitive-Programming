#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod1 998244353
#define mod2 1000000007


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll l,r,x,y,k; cin >> l >> r >> x >> y >> k;
    bool is_yes = false;
    for(ll i = l; i <= r; i ++){
        if((i%k == 0) && x <= i/k && i/k <= y){
            is_yes = true;
            break;
        }
    }
    if(is_yes == true){
        cout << "yes";
    }
    else{
        cout << "no";
    }
}