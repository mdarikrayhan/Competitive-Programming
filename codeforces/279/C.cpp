#include <bits/stdc++.h>

#define suiii ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define co cout<<
//#pragma GCC optimize("O3,Ofast,unroll-loops")
//#pragma GCC target("avx2,sse3,sse4,avx")
using namespace std;
//stuff
ll n,q;
ll arr[1000001];
ll l[1000001];
ll r[1000001];
void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    ll cnt;
    cnt=r[1]=0;
    for(int i=2;i<=n;i++){
        if(arr[i]<=arr[i-1]) cnt++;
        else cnt=0;
        r[i]=cnt;
    }
    cnt=l[n]=0;
    for(int i=n-1;i>=1;i--){
        if(arr[i]<=arr[i+1]) cnt++;
        else cnt=0;
        l[i]=cnt;
    }
    // co l[1]<<'\n';
    while(q--){
        ll a,b;
        cin>>a>>b;
        if(b-a<=1){
            co "Yes\n";
        }
        else if(r[b]+l[a]+1<=b-a){
            co "No\n";
        }
        else{
            co "Yes\n";
        }
    }
}

int main()
{
    suiii
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}