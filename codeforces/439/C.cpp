//------------------Mukul457-----------------------------------

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
template <typename PB>
#define ll long long int
#define be begin()
#define en end()
#define pb push_back
#define pyes cout << "YES\n"
#define pno cout << "NO\n"
#define ce cout << '\n'
#define endl '\n'
#define pie 3.141592653589793238462643383279502884197169399
#define print(x) cout<<x<<endl
#define printb(x) cout<<x<<" "
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end())
#define all(v) v.begin(), v.end()
#define mnv(v) *min_element(v.begin(), v.end())
#define mxv(v) *max_element(v.begin(), v.end())
#define fi first
#define se second
#define vll vector<ll>
#define vp vector<pair<ll,ll>>
#define seev(v,n) for(ll i=0;i<n;i++){ll x; cin>>x; v.push_back(x);}
//typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

ll mod = 1e9 + 7;
const ll inf= 1e18;
ll gcd(ll a, ll b){
  if (b == 0) return a;
  return gcd(b, a%b);
}

ll binary(const std::vector<ll>& arr, ll target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Prevents potential overflow

         if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return left;
}

bool is_prime[1000005];
void sieve_of_eratosthenes(int n)
{
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }
}
ll ciel(ll a,ll b){
    if(a%b){return a/b+1;}
    else{return a/b;}
}

void solve(){
    ll n,k,p;
    cin>>n>>k>>p;
    vll v(n),odd,even;
    vll ans[k];
    for(ll i=0;i<n;i++){
        cin>>v[i];
        if(v[i]%2==0) even.pb(v[i]);
        else odd.pb(v[i]);
    }
    if(even.size()>=p){
        if(odd.size()>=k-p && odd.size()%2==(k-p)%2){
                pyes;
                ll z=0;
                for(ll i=0;i<p;i++){
                    if(i!=p-1) ans[i].pb(even[z]);
                    else{
                        while(z<even.size()){
                            ans[i].pb(even[z]);
                            z++;
                        }
                    }
                    z++;
                }
                z=0;
                for(ll i=p;i<k;i++){
                    if(i!=k-1) ans[i].pb(odd[z]);
                    else{
                        while(z<odd.size()){
                            ans[i].pb(odd[z]);
                            z++;
                        }
                    }
                    z++;
                }
                while(z<odd.size()){
                    ans[0].pb(odd[z]);
                    z++;
                }
        }
        else{
            pno;
            return;
        }
    }
    else if(odd.size()>=2*(p-even.size())){
        if(odd.size()-2*(p-even.size())>=k-p && odd.size()%2==(k-p)%2){
            pyes;
            for(ll i=0;i<even.size();i++) ans[i].pb(even[i]);
            ll z=0;
            for(ll i=even.size();i<p;i++){
                ans[i].pb(odd[z]);
                ans[i].pb(odd[z+1]);
                z+=2;
            }
            for(ll i=p;i<k;i++){
                if(i!=k-1) ans[i].pb(odd[z]);
                else{
                    while(z<odd.size()){
                            ans[i].pb(odd[z]);
                            z++;
                    }
                }
                z++;
            }
            while(z<odd.size()){
                ans[k-1].pb(odd[z]);
                z++;
            }
        }
        else{
            pno;
            return;
        }
    }
    else{
        pno;
        return;
    }
    if(p==0){
        ll z=0;
        while(z<even.size()){
            ans[0].pb(even[z]);
            z++;
        }
    }
    for(auto x:ans){
        printb(x.size());
        for(ll j=0;j<x.size();j++){
            printb(x[j]);
        }
    ce;
    }
}

int main(){
    int t=1;
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cin>>t;
    while(t--){
        solve();
    }
}