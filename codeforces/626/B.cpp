#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define vs vector<string>
#define vc vector<char>
#define vp vector<pair<ll,ll>>
#define mll unordered_map<long long,long long>
#define pb push_back
#define fs(i, a, b) for (ll i = a; i < b; i++)
#define print(v) for (auto x:v) cout<<x<<" "
#define endl '\n'
const int mod=1e9+7;

void solve(){
  ll n;cin>>n;
  string s;cin>>s;
  if(s==string(n,s[0]))cout<<s[0];
  else {
    for(auto x:{'B','G','R'}){
      if(count(s.begin(),s.end(),x)!=n-1)cout<<x;
    }
  }
}

int main() {
    ios::sync_with_stdio(false);
    ll T=1;
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
