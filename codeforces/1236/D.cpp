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


void solve(){
  ll N, M, K;
  cin >> N >> M >> K;
  set<int> init = {-INF, INF};
  vector<set<int>> tate(M+1, init); //上下方向にみる
  vector<set<int>> yoko(N+1, init); //左右方向にみる
  
  rep(i,0,K){
    int x, y;
    cin >> x >> y;
    tate[y].insert(x);
    yoko[x].insert(y);
  }
  
  int U = 1;
  int D = N;
  int L = 1;
  int R = M;
  int nx = 1;
  int ny = 1;
  
  string S = "RDLU";
  ll cnt = 1;
  rep(i,0,max(N,M)*4 + 10){
    //cout << nx << " " << ny << endl;
    int savex = nx;
    int savey = ny;
    if(S[i%4] == 'R'){
      auto itr = yoko[nx].lower_bound(ny);
      int to = min(R, (*itr) - 1);
      U = nx + 1;
      cnt += to - ny;
      ny = to;
    }
    if(S[i%4] == 'D'){
      auto itr = tate[ny].lower_bound(nx);
      int to = min(D, (*itr) - 1);
      R = ny - 1;
      cnt += to - nx;
      nx = to;
    }
    if(S[i%4] == 'L'){
      auto itr = yoko[nx].lower_bound(ny);
      if(itr != yoko[nx].begin()){
        itr--;
      }
      int to = max(L, (*itr) + 1);
      D = nx - 1;
      cnt += ny - to;
      ny = to;
    }
    if(S[i%4] == 'U'){
      auto itr = tate[ny].lower_bound(nx);
      if(itr != tate[ny].begin()){
        itr--;
      }
      int to = max(U, (*itr) + 1);
      L = ny + 1;
      cnt += nx - to;
      nx = to;
    }
    if(savex == nx && savey == ny && i != 0){
      break;
    }
  }
  if(cnt == N*M - K){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
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