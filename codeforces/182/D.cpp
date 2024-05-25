#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define fi first
#define sec second

const ll MOD = 1e8;
const ll N = 1e6 + 5;
const ll INF = 1e18;

string a,b; 

bool cek(ll a, string x){
  bool valid = 1;
  for(int i=a+1;i<x.size()&&valid;i+=a){
    ll cur = 1;
    for(int j=i;j<=i+a-1;j++){
      if(x[j] != x[cur]){
        valid = 0;
        break;
      }
      cur++;
    }
  }
  return valid;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);
  ll tc = 1;
  // cin >> tc;
  while(tc--){
    cin >> a >> b;
    ll n = a.size(), m = b.size();
    a = '%' + a;
    b = '%' + b;
    set<string>st;
    for(ll i=1;i*i<=n;i++){
      if(n%i) continue;
      if(cek(i,a)){
        string tmp = "";
        for(int j=1;j<=i;j++) tmp += a[j];
        st.insert(tmp);
      }
      if(i != n/i && cek(n/i,a)){
        string tmp = "";
        for(int j=1;j<=n/i;j++) tmp += a[j];
        st.insert(tmp);
      }
    }
    ll cnt = 0;
    for(ll i=1;i*i<=m;i++){
      if(m%i) continue;
      if(cek(i,b)){
        string tmp = "";
        for(int j=1;j<=i;j++){
          tmp += b[j];
        }
        if(st.find(tmp) != st.end()) cnt++;
      }
      if(i != m/i && cek(m/i,b)){
        string tmp = "";
        for(int j=1;j<=m/i;j++){
          tmp += b[j];
        }
        if(st.find(tmp) != st.end()) cnt++;
      }
    }
    cout << cnt << endl;
  }
} 

/*

*/