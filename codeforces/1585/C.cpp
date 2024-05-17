#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n'
using namespace std;
typedef long long ll;

void Approach(){
    int n, k;
    cin >> n >> k;

    vector <ll> a(n);
    vector <ll> pos, neg;

    for(int ii = 0; ii < n; ii++){
        cin >> a[ii];
        if(a[ii] > 0){
            pos.push_back(a[ii]);
        }
        else if(a[ii] < 0){
            neg.push_back(-a[ii]);
        }
    } 

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    reverse(pos.begin(), pos.end());
    reverse(neg.begin(), neg.end());

    
    ll ans = 0;

    if(neg.empty()){
        if(!pos.empty()){
            for(int ii = 0; ii < pos.size(); ii += k){
                ans += pos[ii] * 2;
            }
            ans -= pos[0];
        }
    }
    else if(pos.empty()){
        if(!neg.empty()){
            for(int ii = 0; ii < neg.size(); ii += k){
                ans += neg[ii] * 2;
            }
            ans -= neg[0];
        }
    }
    else{
        for(int ii = 0; ii < pos.size(); ii += k){
            ans += pos[ii] * 2;
        }
        for(int ii = 0; ii < neg.size(); ii += k){
            ans += neg[ii] * 2;
        }
        if(pos[0] > neg[0]){
            ans -= pos[0];
        }
        else{
            ans -= neg[0];
        }
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    int T = 1;
    cin >> T;
    for(int C = 1; C <= T; C++){
        Approach();
    }
    return 0;
}