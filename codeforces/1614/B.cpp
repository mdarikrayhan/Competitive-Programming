// Written by MiHiR_Kr.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e9 + 7;
#define tt ll t;  cin>>t; while(t--)
#define fi(i,n)  for(ll i=0;i<n;i++)
 
int main()
{
ios_base::sync_with_stdio(0), cin.tie(0);
 tt{ll sum = 0;
    ll n;cin>>n;
    vector<pair<ll,ll>> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i].first;
        v[i].second = i;
    }
      sort(v.begin(), v.end(), greater<pair<ll, ll>>());
    for(ll i=0,j=1;i<n;i+=2){
        sum+=j*2*v[i].first;
        v[i].first=j;
        j++;
    }
    for(ll i=1,j=-1;i<n;i+=2){
        sum+=abs(j)*v[i].first*2;
        v[i].first=j;
        j--;
    }
    sort(v.begin(), v.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
        return a.second < b.second;
    });
    cout<<sum<<endl;
    cout<<"0";
    for(ll i=0;i<n;i++){
        cout<<" "<<v[i].first;
    }
    cout<<endl;
 }
return 0;
}
