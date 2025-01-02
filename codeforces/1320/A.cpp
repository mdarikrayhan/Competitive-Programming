#include <bits/stdc++.h>
#define forn(i, n, k) for (int i = k; i < n + k; i++)
#define all(v) v.begin(), v.end()
#define take(n) ll n; cin >> n;
#define takean(a, n, k) ll a[n + k]; forn(i, n, k) cin >> a[i];
#define ll long long int
#define vi vector<long long int>
#define vvi vector<vector<long long int>>
#define sort(v) sort(v.begin(),v.end())
#define sortrev(v) sort(v.rbegin(),v.rend())
//modulo of negative number - (x%p+p)%p
using namespace std;
int main(){
    
    int t=1;
    // cin >> t;
    while(t--)
    {
        ll n;
        cin>>n;
        vi v(n+1);
        for(ll i=1;i<=n;i++){
            cin>>v[i];
        }
        map<ll,ll>m;
        for(ll i=1;i<=n;i++){
            m[(i-v[i])] += v[i];
        }
        ll ans=INT_MIN;
        for(auto i:m){
            if(i.second > ans){
                ans=i.second;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}