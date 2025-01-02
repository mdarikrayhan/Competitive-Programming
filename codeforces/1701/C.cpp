#include <bits/stdc++.h>
using namespace std;
#define ll long long
int check(map<ll,ll>& m1,ll n,ll mid){
    ll sum=0,c=0,k=mid/2,t,num=0;
    for (auto i:m1){
        i.second = i.second-mid;
        sum+=max(0ll,i.second);
        if (i.second<0) num+=(abs(i.second)/2);
    }
    n = n-m1.size();
    t = max(0ll,sum-(n*k+num));
    // cout<<sum-n*k<<" "<<n<<" "<<mid<<"\n";
    if (t) return 1;
    return 0;
}
int main(){
    ll t;
    cin>>t;
    while (t--){
        ll n,m;
        cin>>n>>m;
        map<ll,ll> m1;
        for (int i=0; i<m; i++){
            ll x;
            cin>>x;
            m1[x]++;
        }
        ll r=0,l=1,ans=1e9;
        for (auto i:m1) {
            r = max(r,i.second);
            // cout<<i.first<<" "<<i.second<<"\n";
        }
        while (l<=r){
            ll mid = (l+r)/2;
            if (check(m1,n,mid)>0){
                l=mid+1;
            }
            else{
                ans=min(ans,mid);
                r=mid-1;
            }
        }
        cout<<ans<<"\n";
    }
}