#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
#define ull unsigned long long
#define vl vector<long long>
#define go(a) for(auto &x:a) cin>>x
#define fr(i,a,b) for(ll i=a;i<b;i++)
void yes(){cout<<"YES"<<endl;}
void no(){cout<<"NO"<<endl;}
ll powmod(ll a , ll b , ll mod) { ll ans = 1; a %= mod; while (b) { if (b % 2) ans = (a * ans) % mod; a = (a * a) % mod; b /= 2; } return ans; }
ll factmod(ll n , ll mod) { ll ans = 1; while (n) { ans = (ans * (n--)) % mod; } return ans; }
ll ncrmod(ll n , ll r , ll mod) { return (((factmod(n , mod) * powmod(factmod(r , mod) , mod - 2 , mod)) % mod) * powmod(factmod(n - r , mod) , mod - 2 , mod)) % mod; }
bool is_square(ll n) { ll l = 1 , r = 3037000500 , mid; while (r - l > 1) { mid = (l + r) / 2; ll x = mid * mid; if (x <= n) { l = mid; } else { r = mid; } } return (l * l == n); }
ll power(ll a , ll b) { ll ans = 1; while (b) { if (b % 2) ans *= a; a *= a; b /= 2; } return ans; }


void solve(){
    ll n,x;cin>>n>>x;
    vector<pair<ll,ll>> zero,one;
    fr(i,0,n){
        ll tt,h,m;
        cin>>tt>>h>>m;
        if(tt==0){
            zero.push_back({m,h});
        }else{
            one.push_back({m,h});
        }
    }
    sort(zero.rbegin(),zero.rend());
    sort(one.rbegin(),one.rend());

    // for(ll i=0;i<zero.size();i++){
    //     cout<<zero[i].first<<" "<<zero[i].second<<endl;
    // }
    // cout<<endl;
    // for(ll i=0;i<one.size();i++){
    //     cout<<one[i].first<<" "<<one[i].second<<endl;
    // }

    vector<pair<ll,ll>> zero_d,one_d;
    zero_d = zero; one_d = one;
    ll ans_0 = 0;
    ll h = x;
    bool pick=true;
    while(pick){
        if(pick){
            bool p = false;
            for(ll i=0;i<zero.size();i++){
                if(zero[i].second!=0 && zero[i].second <= h){
                    // cout<<"#"<<zero[i].second<<endl;
                    ans_0++;
                    h += zero[i].first;
                    zero[i].second = 0;
                    p = true;
                    break;
                }
            }
            pick = p;
            // cout<<"h: "<<h<<endl;
        }
        if(pick){
            bool p =false;
            for(ll i=0;i<one.size();i++){
                if(one[i].second!=0 && one[i].second<=h){
                    // cout<<"$"<<one[i].second<<endl;
                    ans_0++;
                    h += one[i].first;
                    one[i].second = 0;
                    p = true;
                    break;
                }
            }
            pick = p;
        }
    }
    h = x;
    pick = true;
    ll ans_1 = 0;
    while(pick){
        if(pick){
            bool p = false;
            for(ll i=0;i<one_d.size();i++){
                if(one_d[i].second!=0 && one_d[i].second <= h){
                    ans_1++;
                    h += one_d[i].first;
                    one_d[i].second = 0;
                    p = true;
                    break;
                }
            }
            pick = p;
        }
        if(pick){
            bool p =false;
            for(ll i=0;i<zero_d.size();i++){
                if(zero_d[i].second!=0 && zero_d[i].second<=h){
                    ans_1++;
                    h += zero_d[i].first;
                    zero_d[i].second = 0;
                    p = true;
                    break;
                }
            }
            pick = p;
        }
    }
    cout<<max(ans_0,ans_1)<<endl;
}  

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
ios::sync_with_stdio(0);
cin.tie(0);

    // ll t; cin>>t;    
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}