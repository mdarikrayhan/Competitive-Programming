#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define un unsigned long long
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define pb push_back
#define ppb pop_back
#define sz(x) ((int)(x).size())
#define ff first
#define ss second

const ll M = 1e9 + 7;


#ifndef ONLINE_JUDGE
#include "Jhbd.h"
#else
#define debug(x...)
#define debugArr(arr, n)
#endif

void solve()
{
    ll n,x,y;
    cin>>n>>x>>y;
    string s;
    cin>>s;
    ll cnt=0;
    ll ans=0;
    debug(n,x,y,s);
    for(ll i=n-1;i>=n-x;i--) {
        cnt++;
        if(cnt==y+1) {
            ans+=(s[i]=='0');
        }
        else {
            ans+=(s[i]=='1');
        } 
    }
    cout<<ans<<"\n";

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
     #ifdef Abhinay
        freopen("Error.txt", "w", stderr);
    #endif
    // int t;
    // cin>>t;
    // while(t--) {
    //     solve();
    // }
    solve();
}