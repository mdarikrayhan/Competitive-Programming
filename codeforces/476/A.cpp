#include<bits/stdc++.h>
#define ll long long int
#define lld long long double
#define N (ll)1e5
#define ct (ll)1000000007
using namespace std;
void solve(){
    ll n,m;
    cin>>n>>m;
    for(int i=(n+1)/2;i<=n;i++){
        if(i%m==0){
            cout<<i<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}