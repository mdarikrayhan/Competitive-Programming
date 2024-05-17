#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;

bool f(ll k, vector<ll>a, ll n){
    vector<ll> v=a;
    for(ll i=n-1;i>=2;i--){
       if(a[i]<k) return false;
       ll temp=a[i]-k;
       ll d=min(temp/3, v[i]/3);
       if(d>0){
        a[i]-=3*d;
        a[i-1]+=d;
        a[i-2]+=2*d;
       }
    }
    return a[0]>=k && a[1]>=k;
}
void solve(){
   ll n;
   cin>>n;
   vector<ll>a(n);
   ll low=0, high=1e9;
   ll ans=low;
   for(ll i=0;i<n;i++) cin>>a[i];
   while(low<=high){
    ll mid=low+(high-low)/2;
    if(f(mid,a,n)){
        ans=mid;
        low=mid+1;
    }else high=mid-1;
   }
   cout<<ans<<endl;
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}