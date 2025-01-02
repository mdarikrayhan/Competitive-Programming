#include <bits/stdc++.h>

using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array

#define ll long long
#define pb push_back
#define ld long double
#define sza(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define vi(v,n) for(int i = 0;i<n;i++) cin>>v[i];
#define vout(v) for(auto it:v) cout<<it<<" ";
#define tt endl;
//__builtin_popcount(n) return no of 1s in binary representation of n
//__builtin_clz(n) return no of leading zeors;
//__builtin_ctz(n) no of trailing zeros;

const int MAX_N = 1e5 + 5;
const ll MOD = 998244353;
const ll INF = 1e9;
const ld EPS = 1e-9;
typedef vector<int> vint;




    

void solve() {

  ll n; cin>>n;
  ll arr[n];
  ll brr[n];
  ll mex = 0;
  map<ll,ll>mp;
  for(int i = 0;i<n;i++) {
      cin>>arr[i];
      brr[i] = arr[i];
      mp[arr[i]]++;
  }
  // vector<ll>final;
  // final.push_back(arr[0]);
  // ll prev = arr[0];
  // for(int i = 0;i<n;i++){
  //   if(arr[i] != prev){
  //       final.push_back(arr[i]);
  //       prev = arr[i];
  //   }
  // }
  // sort(final.begin(),final.end());
  sort(arr,arr + n);
  for(auto it:arr){
    if(it == mex) mex++;
  }
  if(mex == 0) {
    cout<<"YES"<<endl;
    return;
  }
  if(mex == n) {
    cout<<"NO"<<endl;
    return;
  }
  ll start = -1;
  ll end = -1;
  for(int i = 0;i<n;i++){
     if(brr[i] == (mex + 1)){
        if(start == -1){
            start = i;
            end  = i;
        }
        else end = i;
     } 
  }

  if(start == end) {
      cout<<"YES"<<endl;
      return;
  }
  for(int i = start;i<=end;i++){
    mp[brr[i]]--;
  }
  bool has = true;
  for(int i = 0;i<mex;i++){
    if(mp[i] <= 0) {
        has = false;
        break;
    }
  }
  if(has) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;


}
int main() {
    optimize();
    int tc = 1;
   cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}