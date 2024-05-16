#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
   ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin>>t;
    while(t--){
        ll x,y;
        cin>>x>>y;
        if(x==y)cout<<x<<"\n";
        else if(x>y){
            cout<<x+y<<"\n";
        }
        else cout<<y-(y%x)/2<<"\n";
    }
}
