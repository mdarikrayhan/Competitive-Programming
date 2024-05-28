#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int const MODULO = 998244353;

int n, inv_n;

struct Node {
  int start;
  int stop;
};

int const NMAX = 150000;
vector <int> g[1 + NMAX];
int subSize[1 + NMAX];
ll val[1 + NMAX];

struct Aib {
  ll aib[1 + NMAX];

  Aib () {
    for(int i = 0;i <= NMAX;i++) {
      aib[i] = 0;
    }
  }

  void update(int pos, ll add) {
    add = add % MODULO;
    for(int i = pos;i <= n;i = 2 * i - (i & (i-1))) {
      aib[i] += add;
      if(aib[i] >= MODULO) {
        aib[i] -= MODULO;
      }
      //cerr << i << ' ';
    }
    //cerr << '\n';
  }

  ll query(int pos) {
    ll ans = 0;
    for(int i = pos;i > 0;i = (i & (i-1))) {
      ans += aib[i];
      if(ans >= MODULO) {
        ans -= MODULO;
      }
    }
    return ans;
  }
};

int tourSize = 0;
Node tour[1 + NMAX];
Aib tourAib;
int jump[1 + NMAX];

int heavySize = 0;
int top[1 + NMAX];
int heavyPos[1 + NMAX];
int drop[1 + NMAX];
Aib heavyAib;

void DFS(int node, int parent) {
  jump[node] = parent;
  subSize[node] = 1;
  tourSize++;
  tour[node].start = tourSize;
  for(int i = 0;i < g[node].size();i++) {
    int to = g[node][i];
    if(parent != to) {
      DFS(to, node);
      subSize[node] += subSize[to];
    }
  }
  tour[node].stop = tourSize;
}

void buildHeavy(int node, int parent) {
  int heavyChild = 0;
  for(int i = 0;i < g[node].size();i++) {
    int to = g[node][i];
    if(parent != to) {
      if(subSize[heavyChild] < subSize[to]) {
        heavyChild = to;
      }
    }
  }
  if(heavyChild != 0) {
    drop[node] = heavyChild;
    heavySize++;
    heavyPos[heavyChild] = heavySize;
    top[heavyChild] = top[node];
    buildHeavy(heavyChild, node);
    for(int i = 0;i < g[node].size();i++) {
      int to = g[node][i];
      if(parent != to && heavyChild != to) {
        heavySize++;
        heavyPos[to] = heavySize;
        top[to] = to;
        buildHeavy(to, node);
      }
    }
  }
}

ll computeQuery(int node) {
  ll ans = (val[node] * n) % MODULO;
  ans += tourAib.query(tour[node].start);
  if(ans >= MODULO) {
    ans -= MODULO;
  }
  while(node != 1) {
    ans += (MODULO + heavyAib.query(heavyPos[node]) - heavyAib.query(heavyPos[top[node]]-1)) % MODULO;
    if(ans >= MODULO) {
      ans -= MODULO;
    }
    node = top[node];
    if(node != 1) {
      ans += (val[jump[node]] * (n - subSize[node])) % MODULO;
      if(ans >= MODULO) {
        ans -= MODULO ;
      }
      node = jump[node];
    }
  }
  //cerr << ans << ' ';
  ans = ans % MODULO;
  return (1LL * ans * inv_n) % MODULO;
}

int logPow(int a, int b) {
  ll ans = 1, mult = a;
  for(int i = 0;i < 30;i++) {
    if(b & (1 << i)) {
      ans = (ans * mult) % MODULO;
    }
    mult = (mult * mult) % MODULO;
  }
  //cerr << "  " << (ans * a) % MODULO << '\n';
  return ans;
}

int main() {

  int t;
  cin >> n >> t;
  for(int i = 1;i < n;i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  DFS(1, 1);
  top[1] = 1;
  heavySize++;
  heavyPos[1] = heavySize;
  //cerr << "Heavy problem\n";
  buildHeavy(1, 1);
  inv_n = logPow(n, MODULO-2);
  for(int q = 1;q <= t;q++) {
    int cer;
    cin >> cer;
    if(cer == 1) {
      int a, b;
      cin >> a >> b;
      tourAib.update(1, (1LL * b * subSize[a]) % MODULO);
      tourAib.update(tour[a].start, (MODULO - ((1LL * b * subSize[a]) % MODULO)) % MODULO);
      tourAib.update(tour[a].stop+1, (1LL * b * subSize[a]) % MODULO);
      if(drop[a] != 0) {
        heavyAib.update(heavyPos[drop[a]], (1LL * b * (n - subSize[drop[a]])) % MODULO);
      }
      val[a] += b;
      if(val[a] >= MODULO) {
        val[a] -= MODULO;
      }
    }else {
      int a;
      cin >> a;
      cout << computeQuery(a) << '\n';
    }
  }
  return 0;
}
