#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll xornacci(ll a, ll b, ll n){
    if(n%3==2){
        return (a^b);
    }
    if(n%3==1){
        return b;
    }
    return a;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll a,b,n;
        cin>>a>>b>>n;
        ll ans=xornacci(a,b,n);
        cout<<ans<<endl;
    }
    return 0;
}