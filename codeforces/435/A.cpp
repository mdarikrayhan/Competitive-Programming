#include <bits/stdc++.h>
using ll = long long int;
using namespace std;

#define fi(l, r) for (ll i = l; i < r; i++)
#define fj(l, r) for (ll j = l; j < r; j++)
#define in(n) ll n; cin >> n
#define inarr(arr,n) for (ll i = 0; i < n; i++) { cin >> arr[i]; }


void how_many(vector<ll> &v, ll &index, ll m){
    ll in_bus =  v[index];

    if(in_bus < m){
        ll tmp = index+1;
        while(in_bus <= m){
            if(v[tmp] + in_bus <= m){
                in_bus += v[tmp];
                tmp++;
                
            }
            else{
                index = tmp;
                return;
            }
        }
    }

    else{
        v[index+1] += v[index] - m;
        index++;
        return;
    }
}

void solve() {
    ll n;
    long double m;
    cin>>n>>m;
    ll index=0;
    ll cnt =0;
    vector<ll> q;
    for(ll i=0;i<n;i++){
        ll t;
        cin>>t;
        q.push_back(t);
    }

    for(;index<n;){
        cnt++;
        how_many(q,index,m);
    }

    cout<<cnt<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
        solve();
    
}