#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define maxn 200100
#define Hamim ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
    ll a,b;cin>>a>>b;
    if(a==1)cout<<0<<endl;
    else if(a==2)cout<<b<<endl;
    else cout<<b*2<<endl;
}
int main(){
    Hamim
    int tc;cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}

