
// ki bood ke goft Ghatinga?

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> ppiii;

// vectors and Sets:
#define vc vector
#define pb push_back
#define all(c) (c).begin(), (c).end()

// pairs
#define mp make_pair
#define fr first
#define sc second

// execution time check and Debug
#define StartEX clock_t startExeTime = clock();
#define EndEX clock_t endExeTime = clock();
#define ExTime cerr << "\nTotal Execution Time is: " << double(-double(startExeTime)+double(endExeTime)) / CLOCKS_PER_SEC;
#define debug(x) cerr << #x << " : " << x << '\n'
#define endl "\n"

// time optimization
#define Heh ios::sync_with_stdio(false);cin.tie(0);
#define Bah ios::sync_with_stdio(false);
#pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")

// useful functions
ll pw(ll a,ll b){
  ll ret = 1;
  ll mul = a;
  while(b > 0){
	if(b&1)
	  ret = (ret * mul);
	mul = (mul * mul);
	b >>= 1;
  }
  return ret;
}
ll pw(ll a,ll b,ll mod){
  ll ret = 1;
  ll mul = a;
  while(b > 0){
	if(b&1)
	  ret = (ret * mul) % mod;
	mul = (mul * mul) % mod;
	b >>= 1;
  }
  return ret;
}

ll to_int(string s){
  ll ret = 0;
  for(int i = 0 ; i < (int)s.size() ; i++) ret = 10 * ret + s[i] - '0';
  return ret;
}

bool deq(ld a , ld b){return (abs(a-b) < 0.000001);} // 10 ^ -6

const int MAXN = 256 + 25.6;

int n;

int par[MAXN*MAXN] , rnk[MAXN*MAXN];

int get(int v){return par[v] = (par[v] == v ? v : get(par[v]));}
void uni(int a , int b){
  a = get(a) , b = get(b);
  if(rnk[a] < rnk[b]) swap(a , b);
  par[b] = a;
  rnk[a] += (rnk[a] == rnk[b] ? 1 : 0);
}

int in[MAXN*MAXN] , out[MAXN*MAXN];

vc<int> adj[MAXN*MAXN];

int code(int a , int b){return a * MAXN + b;}

void eulerTour(int v){
  vc<int> path;
  int u = v;
  while(adj[u].size()){
    path.pb(u);
    int tmp = adj[u].back();
    adj[u].pop_back();
    u = tmp;
  }
  path.pb(u);
  for(int i = 0 ; i < (int)path.size()-1 ; i++){
    eulerTour(path[i]);
    cout << char(path[i+1] % MAXN);
  }
}

int main()
{
  for(int i = 0 ; i < MAXN*MAXN ; i++) par[i] = i;
  cin >> n;
  for(int i = 0 ; i < n ; i++){
    string s;
    cin >> s;
    adj[code(s[0] , s[1])].pb(code(s[1] , s[2]));
    out[code(s[0] , s[1])]++ , in[code(s[1] , s[2])]++;
    uni(code(s[0] , s[1]) , code(s[1] , s[2]));
  }
  int cnt = 0;
  for(int i = 0 ; i < MAXN*MAXN ; i++){
    if(par[i] == i and rnk[i] > 0) cnt++;
  }
  int sum = 0 , st = -1;
  for(int i = 0 ; i < MAXN*MAXN ; i++){
    sum += max(0 , in[i] - out[i]);
    if(out[i] - in[i] > 0) st = i;
  }
  if(cnt > 1 or sum > 1) cout << "NO" << endl;
  else{
    cout << "YES" << endl;
    if(st != -1){
      cout << char(st / MAXN) << char(st % MAXN);
      eulerTour(st);
    }
    else{
      for(int i = 0 ; i < MAXN*MAXN ; i++){
	if(in[i] != 0 or out[i] != 0){
	  cout << char(i / MAXN) << char(i % MAXN);
	  eulerTour(i);
	  break;
	}
      }
    }
    cout << endl;
  }
}

// ki seda kard Patinga?
