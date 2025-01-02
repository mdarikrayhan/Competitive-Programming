#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define inf 1e18L+5
bool check(vector<ll> &a, ll n){
    for(ll i=0; i<n; i++){
            if(a[i] != a[n-1-i]){
                return false;
            }
        }
        return true;
}
void solve()
{
   ll n; cin>>n;
   vector<ll> a(n);
   vector<ll> cnt(n+1,0);
   for(auto &x: a){
        cin>>x;
        cnt[x]++;
   }
   if(n==1 || n==2){
        cout<<"YES\n";
        return;
   }
   
        ll i1 = -1,i2=-1;
        for(ll i=0; i<n; i++){
            if(a[i] != a[n-1-i]){
                i1=a[i];
                i2=a[n-1-i];
                break;
            }
        }
        if(i1==-1 || i2==-1){
            cout<<"YES\n";
            return;
        }
        vector<ll> p1,p2;
        for(auto x: a){
            if(x != i1){
                p1.push_back(x);
            }
            if(x != i2){
                p2.push_back(x);
            }
        }
        bool z1 = check(p1,p1.size());
        bool z2 = check(p2,p2.size());
        if(z1||z2){
            cout<<"YES\n";
            return;
        }
        else{
            cout<<"NO\n";
            return;
        }
   
}
signed main()
{
std::ios::sync_with_stdio(false);
std::cin.tie(nullptr);
ll tes = 1;
cin >> tes;
while (tes--)
solve();
return 0;
}