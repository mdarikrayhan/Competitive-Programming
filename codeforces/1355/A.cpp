#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define soot(v) sort(v.begin(),v.end())
#define pb push_back
#define vtoe v.begin(),v.end()
#define endl '\n'
#define fmin *min_element(v.begin(),v.end())
#define fmax *max_element(v.begin(),v.end())
#define mpsort(mp) sort(mp.begin(),mp.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
 
ll digit(ll n){
    ll boro = 10;
    ll big = 0;
    while(n > 0){
        ll d = n % 10;
        n = n / 10;
        boro = min(boro,d);
        big = max(big,d);
    }
    return big * boro;
}
 
void solve(){
    ll n,k;
    cin >> n >> k;
    k--;
    while(k--){
        ll y = digit(n);
        if(y == 0){
            break;
        }
        n += y;
    }
    cout << n << endl;
 
   
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
   //solve();
    return 0;
}