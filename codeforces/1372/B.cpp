#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve() {
    ll n;
    cin>>n;
    if(n%2==0) {
        cout<<n/2<<" "<<n/2<<endl;
    }
    else {
        vector<ll>div;
        for(ll i=2;i*i<=n;i++) {
            if(n%i==0) {
                div.push_back(n/i);
            }
        }
        if(div.size()==0) {
            cout<<1<<" "<<n-1<<endl;
        }
        else {
            cout<<div[0]<<" "<<n-div[0]<<endl;
        }
    }  
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}