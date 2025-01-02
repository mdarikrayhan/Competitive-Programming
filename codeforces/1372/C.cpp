#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve() {
    ll n;
    cin>>n;
    vector<ll>v(n+1);
    ll pos[n+1];
    bool exist=true;;
    for(ll i=1;i<=n;i++) {
        cin>>v[i];
        if(v[i]!=i) {
            exist=false;
        }
        pos[v[i]]=i;
    }
    if(exist) {
        cout<<0<<endl;
        return;
    }
    ll pos1=0;
    ll pos2=0;
    for(ll i=1;i<=n;i++) {
        if(v[i]!=i) {
            pos1=i;
            break;
        }
    }
    for(ll i=n;i>=1;i--) {
        if(v[i]!=i) {
            pos2=i;
            break;
        }
    }
    for(ll i=pos1+1;i<pos2;i++) {
        if(v[i]==i) {
            cout<<2<<endl;
            return;
        }
    }
    cout<<1<<endl;
    return;

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