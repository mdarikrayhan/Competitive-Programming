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
const int N = 12;
int n, t;
string from[N], to[N];
int can_reach[N][N][N][N];
bool vis[N][N][N][N];
vector < int > G[2 * N * N + 10];
int cap[2 * N * N][2 * N * N];
int par[2 * N * N];
int cx[] = {0, 1, 0, -1};
int cy[] = {1, 0, -1, 0};

int find_flow() {
  for(int i = 0;i < 2 * N * N;i++) {
    par[i] = -1;
  }
  par[0] = -2;

  queue < pair < int, int > > que;
  que.push({0, 10000});

  while(que.size()) {
    int vtx = que.front().first, mini = que.front().second;
    que.pop();

    for(int vtxes: G[vtx]) {
      if(par[vtxes] == -1 && cap[vtx][vtxes]) {
        par[vtxes] = vtx;
        int new_flow = min(mini, cap[vtx][vtxes]);

        if(vtxes == 2 * n * n + 1) {
          return new_flow;
        }

        que.push({vtxes, new_flow});
      }
    }
  }

  return 0;
}

void solve() {
  cin >> n >> t;

  for(int i = 0;i < n;i++) {
    cin >> from[i];
  }

  for(int i = 0;i < n;i++) {
    cin >> to[i];
  }

  memset(can_reach, -1, sizeof(can_reach));
  queue < vector < int > > que;
  int dx = -1, dy = -1;
  for(int i = 0;i < n;i++) {
    for(int j = 0;j < n;j++) {
      if(from[i][j] == 'Z') {
        dx = i, dy = j, vis[i][j][i][j] = true, can_reach[dx][dy][dx][dy] = 0;
        que.push({0, dx, dy, dx, dy});
        break;
      }
    }
  }

  for(int i = 0;i < n;i++) {
    for(int j = 0;j < n;j++) {
      if(from[i][j] != 'Y' && from[i][j] != 'Z') {
        que.push({0, i, j, i, j}),  vis[i][j][i][j] = true, can_reach[i][j][i][j] = 0;
      }
    }
  }

  while(que.size()) {
    vector < int > tmp = que.front();
    que.pop();
    int sx = tmp[1], sy = tmp[2], tx = tmp[3], ty = tmp[4], t_cov = tmp[0];
    if(tmp[0] == t) {
      continue;
    }

    for(int i = 0;i < 4;i++) {
      int nx = tx + cx[i], ny = ty + cy[i];
      if(nx < 0 || ny < 0 || nx >= n || ny >= n || vis[sx][sy][nx][ny] || from[nx][ny] == 'Y' || from[nx][ny] == 'Z') continue;
      vis[sx][sy][nx][ny] = true;
      if(can_reach[dx][dy][nx][ny] != -1 && (can_reach[dx][dy][nx][ny] < t_cov + 1 || to[nx][ny] == '0')) continue;
      if(can_reach[dx][dy][nx][ny] == t_cov + 1) {
        can_reach[sx][sy][nx][ny] = t_cov + 1;
        continue;
      }
      can_reach[sx][sy][nx][ny] = t_cov + 1;
      que.push({t_cov + 1, sx, sy, nx, ny});
    }
  }

  int cnt_1 = 0, cnt_2 = 0, cnt_3 = 0;

  for(int i = 0;i < n;i++) {
    for(int j = 0;j < n;j++) {
      if(from[i][j] != 'Y' && from[i][j] != 'Z') {
        cnt_1++;
        G[0].push_back(i * n + j + 1);
        G[i * n + j + 1].push_back(0);
        cap[0][i * n + j + 1] = from[i][j] - '0';
      }
    }
  }

  for(int i = 0;i < n;i++) {
    for(int j = 0;j < n;j++) {
      for(int k = 0;k < n;k++) {
        for(int m = 0;m < n;m++) {
          if(can_reach[i][j][k][m] != -1) {
            cnt_2++;
            G[1 + i * n + j].push_back(n * n + k * n + m + 1);
            G[n * n + k * n + m + 1].push_back(1 + i * n + j);
            cap[1 + i * n + j][n * n + k * n + m + 1] = 10000;
          }
        }
      }
    }
  }

  for(int i = 0;i < n;i++) {
    for(int j = 0;j < n;j++) {
      if(to[i][j] != 'Y' && to[i][j] != 'Z') {
        cnt_3++;
        G[n * n + i * n + j + 1].push_back(2 * n * n + 1);
        G[2 * n * n + 1].push_back(n * n + i * n + j + 1);
        cap[n * n + i * n + j + 1][2 * n * n + 1] = to[i][j] - '0';
      }
    }
  }

  int total_flow = 0;
  int new_flow = 0;

  while((new_flow = find_flow())) {
    total_flow += new_flow;
    int cur = 2 * n * n + 1;
    while(cur) {
      int prev = par[cur];
      cap[prev][cur] -= new_flow;
      cap[cur][prev] += new_flow;
      cur = prev;
    }
  }

  cout << total_flow << "\n";
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