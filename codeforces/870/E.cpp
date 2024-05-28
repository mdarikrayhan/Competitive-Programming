// RADHASOAMI , WITH THE GRACE OF HUZUR I PROMISE TO FIGHT TILL THE LAST SECOND OF EVERY CONTEST AND CODE TO MY FULL POTENTIAL ......

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

#define ll long long int
#define mod 1000000007

using namespace std;

// ====================  FUNCTIONS FOR INPUT AND OUTPUT OF VECTORS =======================================================

void input(vector < ll > &arr) {
  for(int i = 0;i < arr.size();i++)
    cin >> arr[i];
}

void output(vector < ll > &arr) {
  for(int i = 0;i < arr.size();i++)
    cout << arr[i] << " ";

  cout << "\n";
}

void input(vector < int > &arr) {
  for(int i = 0;i < arr.size();i++)
    cin >> arr[i];
}

void output(vector < int > &arr) {
  for(int i = 0;i < arr.size();i++)
    cout << arr[i] << " ";

  cout << "\n";
}

// ==============================  FOR MATHEMATICAL FUNCTIONS =============================================================

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

ll power(ll a, ll b) {
  if(b == 0) return 1;
  if(b == 1) return a;

  ll smallans = power(a, b / 2);
  ll myans = (smallans * smallans) % mod;

  if((b&1)) {
    myans = (myans * a) % mod;
  }

  return myans;
}

ll multiply(ll a, ll b) {
  return ((a % mod)*(b % mod)) % mod;
}

ll divide(ll a, ll b) {
  return multiply(a, power(b, mod - 2));
}

// ============================ SEGMENT TREE FOR DEFAULT MINIMUM QUERY ==================================================

void manageLazy(vector <ll> &tree, vector <ll> &lazy, ll idx) {
  tree[2 * idx + 1] += lazy[idx];
  lazy[2 * idx + 1] += lazy[idx];

  tree[2 * idx + 2] += lazy[idx]; 
  lazy[2 * idx + 2] += lazy[idx];

  lazy[idx] = 0;
}

void build(vector <ll> &tree, vector <ll> &arr, ll left, ll right, ll idx) {
  if(left == right) {
    tree[idx] = arr[left];
    return;
  }

  ll mid = (left + right) / 2;
  build(tree, arr, left, mid, 2 * idx + 1);
  build(tree, arr, mid + 1, right, 2 * idx + 2);

  tree[idx] = min(tree[2 * idx + 1], tree[2 * idx + 2]);
}

void update(vector <ll> &tree, vector <ll> &lazy, ll tl, ll tr, ll l, ll r, ll idx, ll val) {
  if(l > r)
    return;

  if(l == tl && tr == r) {
    tree[idx] += val;
    lazy[idx] += val;
    return;
  }

  manageLazy(tree, lazy, idx);
  ll mid = (tl + tr) / 2;

  update(tree, lazy, tl, mid, l, min(r, mid), 2 * idx + 1, val);
  update(tree, lazy, mid + 1, tr, max(l, mid + 1), r, 2 * idx + 2, val);

  tree[idx] = min(tree[2 * idx + 1], tree[2 * idx + 2]);
}

ll query(vector <ll> &tree, vector<ll> & lazy, ll tl, ll tr, ll l, ll r, ll idx) {
  if(l > r)
    return 1e18;

  if(l <= tl && tr <= r)
    return tree[idx];

  manageLazy(tree, lazy, idx);
  ll mid = (tl + tr) / 2;

  ll a = query(tree, lazy, tl, mid, l, min(r, mid), 2 * idx + 1);
  ll b = query(tree, lazy, mid + 1, tr, max(l, mid + 1), r, 2 * idx + 2);

  return min(a, b);
}

// ==================================  SPARSE TABLE FOR DEFAULT MINIMUM QUERY ==================================================

void precompute_min(vector < vector < ll > > &sparsetable , vector < ll > &a) {
  int n = sparsetable.size();
  int p = sparsetable[0].size();

  for(int i = 0;i < n;i++)  
    sparsetable[i][0] = a[i];

  for(int j = 1;j < p;j++) {
    for(int i = 0;i + (1 << j) <= n;i++)
      sparsetable[i][j] = min(sparsetable[i][j - 1], sparsetable[i + (1 << (j - 1))][j - 1]);
  }
}

ll minquery(vector < vector < ll > > &sparsetable, vector < ll > &log, ll l, ll r) {
  ll range = r - l + 1;
  if(range == 0)  return sparsetable[l][0];
  ll j = log[range];
  return min(sparsetable[l][j], sparsetable[r - (1 << j) + 1][j]);
}

//========================== BINARY INDEX TREE =========================================================================

void update(vector<ll> &tree, ll index, ll val) {
  index++;
  while(index < tree.size()) {
    tree[index] = (tree[index] + val) % mod;
    index +=index&(-index);
  }
}
 
ll calculate(vector<ll> &tree, ll index) {
  ll sum = 0;
  index++;
  while(index > 0) {
    sum=(sum + tree[index]) % mod;
    index-=index&(-index);
  }

  return sum;
}

//=========================== FOR DISJOINT SET UNION ====================================================================

ll findpar(ll p, vector<ll> &parent) {
  if(parent[p] == p)
    return p;

  parent[p] = findpar(parent[p], parent);
  return parent[p];
}

void merge(ll a, ll b, vector<ll> &parent, vector<ll> &size_) {
  a = findpar(a, parent);
  b = findpar(b, parent);
  
  if (a != b) {
    if (size_[a] < size_[b])
          swap(a, b);
          
    parent[b] = a;
    size_[a] += size_[b];
  }
}

//   ====================================== FOR STORING AND COUNTING THE PRIMES USING SIEVE ============================

void sieve(vector<bool> &primes,vector<ll> &count) {
  for(int i = 2;i < primes.size();i++) {
    if(primes[i]) {
      count.push_back(i);
      for(int j = i*i;j < primes.size();j +=i)
        primes[j] = false;
    }
  }
}

// =====================================================================================================================
const int N = 1e5 + 10;
map < int, int > ind_x, ind_y;
vector < int > G[N];
int s_x[N], s_y[N], cyc = 0;
map < int, int > x, y;
bool vis[N];

void dfs(int v, int fa = -1) {
  vis[v] = true;
  x[s_x[v]]++, y[s_y[v]]++;
  for(int ele: G[v]) {
    if(ele != fa) {
      if(vis[ele]) cyc = 1;
      else dfs(ele, v);
    }
  }
}

void solve() {
  ll n;
  cin >> n;

  for(int i = 1;i <= n;i++) {
    int c_x, c_y;
    cin >> c_x >> c_y;

    if(ind_x[c_x]) {
      G[i].push_back(ind_x[c_x]);
      G[ind_x[c_x]].push_back(i);
    }

    if(ind_y[c_y]) {
      G[i].push_back(ind_y[c_y]);
      G[ind_y[c_y]].push_back(i);
    }

    ind_x[c_x] = i, ind_y[c_y] = i;
    s_x[i] = c_x, s_y[i] = c_y;
  }

  ll ans = 1;
  for(int i = 1;i <= n;i++) {
    if(!vis[i]) {
      cyc = 0;
      x.clear(), y.clear();
      dfs(i);

      ans = (ans * ((power(2, x.size() + y.size()) - (1 - cyc) + mod) % mod)) % mod;
    }
  }

  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.tie(NULL);
  #ifndef ONLINE_JUDGE
    freopen("input2.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int t = 1;
  // cin >> t;

  while(t--) {

    solve();
    
  }

  return 0;
}