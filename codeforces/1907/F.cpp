#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define forn(n) for (ll i = 0; i < ll(n); i++)
ll M = 1e9 + 7;
ll mod = 998244353;

ll solve(vector<ll>& a, ll n,ll ind){
    bool ok = true;
    ll x = ind - 1;
    if(x < 0) x += n;
    if(a[x] < a[(ind + 1)%n]){
        for(int i = 1; i<n;i++){
            x = ind - i;
            ll y = ind - i + 1;
            if(x < 0) x+=n;
            if(y < 0) y+=n;
            if(a[x] < a[y]){
                ok = false;
                break;
            }
        }
        if(!ok) return -1;
        else{
            return min(n-ind,1+ (1+ind)%n);
        }
    }
    else{
         for(int i = 1; i < n; i++){
            if(a[(ind + i)%n] < a[(ind + i - 1)%n]){
                ok = false;
                break;
            }
        }
        if(!ok) return -1;
        else{
            return min(2 + ind,(n-ind)%n);
        }
    }
}
int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t;
   cin>>t;
   while(t--){
    ll n;
    cin>>n;
    vector<ll> a(n);
    map<ll,ll> mp;
    forn(n){
        cin>>a[i];
        mp[a[i]]++;
    }
    ll ind = 0;
    forn(n) if(a[i] < a[ind]) ind = i;
    if(mp[a[ind]] == n) cout<<"0\n";
    else if(mp[a[ind]] == 1) cout<<solve(a,n,ind)<<"\n";
    else{
        ll count = 0;
        ll mx = -1;
        for(int i=0;i<n;i++){
            ll y = i - 1;
            if(y<0) y += n;
            if(a[i] == a[ind] && (a[y] != a[ind] || a[(i+1)%n] != a[ind])){
                count++;
                ll x = solve(a,n,i);
                if(mx == -1) mx = x;
                else if(x != -1) mx = min(mx,x);
            }
            if(count == 2) break;
        }
        cout<<mx<<"\n";
    }
   }
 return 0;
}