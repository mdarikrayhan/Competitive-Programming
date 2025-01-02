#include<bits/stdc++.h>
 
using namespace std;
using ll = long long int;
const ll MOD = 1e9+7;

ll power(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b&1){
            res = res*a;
        }
        a = a*a;
        b >>=1;
    }
    return res;
}

void solve()
{   
    ll n; cin >> n;
    vector<ll> kek(n);
    ll zeros = 0;
    ll sum = 0;
    for(ll i = 0; i< n; i++){
        cin >> kek[i];
    }
    ll need = 0;
    for(ll i = 0; i< n; i++){
        sum+= kek[i];
        need+= i;
        if(need > sum){
            cout << "NO";
            return;
        }
    }
    cout << "YES";
    return;
}
 
 
int main()
{   
    ios_base :: sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}