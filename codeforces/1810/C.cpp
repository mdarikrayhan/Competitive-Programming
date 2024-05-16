#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define all(a) a.begin(),a.end()
#define endl '\n'
using namespace std;

bool compare(const pair<ll, ll>& a, const pair<ll, ll>& b) {
    return a.second < b.second;
}

void solve() {
    ll n,c,d,cnt=0,v=0;
    cin >> n >> c >> d;
    bool flag = 0;
    vector<ll>a(n);
    vector<ll>temp;
    set<ll>st;

    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    sort(all(a));

    temp.pb(a[0]);
    for(ll i=1;i<n;i++){
        if(a[i] != a[i-1]){
            temp.pb(a[i]);
        }
        else{
            v++;
        }
    }

    // for(auto it:temp){
    //     cout << it << " ";
    // }
    // cout << endl;

    ll ans=(c*n)+d;
    ll m = temp.size();

    for(ll i=m-1;i>=0;i--){
        ll h = (temp[i] - (i+1))*d;
        ll g = (m - (i+1) + v)*c;
        // cout << h << " " << g << endl;
        ans = min(ans,h+g);
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while(tc-- > 0){
        solve();
    }   
    return 0;
}
