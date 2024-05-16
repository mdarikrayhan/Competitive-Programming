#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
void primeFactors(int ele, unordered_map<ll,ll>&mp){
    for(int i=2;i*i<=ele;i++){
        while(ele%i==0){
            mp[i]++;
            ele/=i;
        }
    }
    if(ele>1){
        mp[ele]++;
    }
}
bool f(ll k, vector<ll>&a, ll n){
    ll j=n-1;
    for(ll i=k-1;i>=0;i--){
        if(a[i]>=a[j] || a[i]>=a[j-1]) return false;
        j--;
    }
    return true;
}
void solve(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    ll low=1, high=(n+1)/2-1;
    ll ans=0;
    while(low<=high){
        ll mid=low+(high-low)/2;
        if(f(mid,a,n)){
            ans=mid;
            low=mid+1;
        }else high=mid-1;
    }
    // if(!ans){
    //     cout<<0<<endl;
    //     for(auto it:a) cout<<it<<" ";
    //     cout<<endl;
    //     return;
    // }
    cout<<ans<<endl;
    ll i=n-1, j=ans-1;
    for(ll k=0;k<n;k++){
        if(k%2==0||j==-1) cout<<a[i--]<<" ";
        else cout<<a[j--]<<" ";
    }
    cout<<endl;
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}