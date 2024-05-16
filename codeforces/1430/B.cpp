/*
* JAY SHREE RAM
* JAY SHREE GANESH
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define nline "\n"
#define MOD 1000000007
void joyshreeram() {
    ll n,k;
    cin>>n>>k;
    vector<ll>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr.begin(),arr.end());
    for(int i=n-2;i>=0;i--){
        if(k==0) break;
        arr[n-1]+=arr[i];
        arr[i]=0;
        k-=1;
    }
    sort(arr.begin(),arr.end());
    ll ans=arr[n-1]-arr[0];
    cout<<ans<<nline;
}
int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
        ll testcases;
        cin>>testcases;
        while(testcases--){
            joyshreeram();
        }
return 0;
}