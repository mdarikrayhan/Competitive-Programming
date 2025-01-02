#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

//only for atcoder
//#include<atcoder/all>
//using namespace atcoder;

#define rep(i,l,r) for(ll i=(l); i<(r); i++)
#define rrep(i,l,r) for(ll i=(r)-1; i>=(l); i--)
#define ALL(c) (c).begin(), (c).end()
#define RALL(c) (c).rbegin(), (c).rend()
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(RALL(c))
#define REV(c) reverse(ALL(c))
#define MINV(c) *min_element(ALL(c))
#define MAXV(c) *max_element(ALL(c))

template <typename TYPE>
void print(TYPE vec){
  rep(i,0,vec.size()){
    cout << vec[i];
    if(i == vec.size()-1){
      cout << '\n';
    }
    else{
      cout << " ";
    }
  }
}

using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using VS = vector<string>;
using VVS = vector<VS>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VC = vector<char>;
using VVC = vector<VC>;
using VD = vector<ld>;
using VVD = vector<VD>;
using P = pair<ll,ll>;
using VP = vector<P>;
using VVP = vector<vector<P>>;
const ll LINF = 2e18;
const int INF = 2e9;
const int MOD = 1e9+7;
const int MAX = 1e5+10;

//考察
//iからjに到達できるか？を判定する
//iから到達できる部分は区間をなす
//i < jとなるjでどこまで到達できるか？を考える
//いまの位置がkのものの個数をmapでカウント？
//そのときに止まるものを一つ後ろにずらす

void solve(){
  int N, M;
  cin >> N >> M;
  VI vec(M);
  rep(i,0,M){
    cin >> vec[i];
  }
  
  if(N == 1){
    cout << 0 << endl;
    return;
  }
  
  ll ans = N;
  
  map<int,int> mp;
  rep(i,1,N+1){
    mp[i] = 1;
  }
  
  rep(i,0,M){
    int a = vec[i] - i - 1;
    int x = mp[a];
    mp[a] -= x;
    mp[a-1] += x;
  }
  
  int now = 0;
  for(auto itr = mp.begin(); itr != mp.end(); itr++){
    int K = min(N, itr->first + M + 1);
    while(itr->second){
      now++;
      ans += K - now;
      itr->second--;
    }
  }
  
  mp.clear();
  
  //逆側から操作
  rep(i,1,N+1){
    mp[i] = 1;
  }
  rep(i,0,M){
    vec[i] = N - vec[i] + 1;
  }
  
  rep(i,0,M){
    int a = vec[i] - i - 1;
    int x = mp[a];
    mp[a] -= x;
    mp[a-1] += x;
  }
  
  now = 0;
  for(auto itr = mp.begin(); itr != mp.end(); itr++){
    int K = min(N, itr->first + M + 1);
    while(itr->second){
      now++;
      ans += K - now;
      itr->second--;
    }
  }
  
  cout << ans << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  //cin >> T;
  T = 1;
 
  for(int i=0; i<T; i++){
    solve();
  }
}