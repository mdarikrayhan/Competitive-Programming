#include <bits/stdc++.h>
#define rep(i, j, k) for (int i = j; i < (k); ++i)
#define all(i) (i).begin(), (i).end()
#define sz(i) (int)(i).size()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

typedef vector<string> vs;

int r, c;

bool in_bound(int i, int j) { return 0 <= i && i < r && 0 <= j && j < c; }

vs grid, targ;
int mytime;
set<int> art;
vi tin, lo;
vpii dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void dfs(int u, int p) {
  int co = 0;
  int i = u / c;
  int j = u % c;
  tin[u] = lo[u] = ++mytime;

  for (auto [ni, nj] : dirs) {
    ni += i;
    nj += j;
    int v = ni * c + nj;

    if (in_bound(ni, nj) && (grid[ni][nj] == '*' || grid[ni][nj] == 'f')) {
      if (v == p)
        continue;
      if (tin[v] != -1) {
        lo[u] = min(lo[u], tin[v]);
      } else {
        dfs(v, u);
        lo[u] = min(lo[u], lo[v]);
        if (lo[v] >= tin[u] && p != -1) {
          art.insert(u);
        }
        co++;
      }
    }
    if (p == -1 && co > 1)
      art.insert(u);
  }
}

int delet() {
  tin.assign(r * c, -1);
  lo.assign(r * c, INT_MAX);
  mytime = 0;
  art.clear();
  bool found = false;
  rep(ni, 0, r) {
    rep(nj, 0, c) {
      if (in_bound(ni, nj) && (grid[ni][nj] == '*' || grid[ni][nj] == 'f')) {
        dfs(ni * c + nj, -1);
        found = true;
        break;
      }
      if (found)
        break;
    }
  }
  rep(ni, 0, r) {
    rep(nj, 0, c) {
      if (in_bound(ni, nj) && grid[ni][nj] == '*' &&
          art.find(ni * c + nj) == art.end()) {
        return ni * c + nj;
      }
    }
  }
  return -1; // TODO
}

void expander(int i, int j, vpii &path) {
  if (!in_bound(i, j) || targ[i][j] != '*')
    return;
  targ[i][j] = 'f';
  path.push_back({i, j});
  for (auto [ni, nj] : dirs) {
    ni += i;
    nj += j;
    expander(ni, nj, path);
  }
}

void print() {
  for (auto row : grid)
    cout << row << endl;
  cout << endl;
}

int main() {
  cin >> r >> c;
  grid.resize(r);
  targ.resize(r);
  tin.resize(r * c);
  lo.resize(r * c);
  rep(i, 0, r) cin >> grid[i];
  rep(i, 0, r) cin >> targ[i];

  vvi dists(r, vi(c, INT_MAX));

  vvi backs(r, vi(c, -1));

  queue<int> q;
  rep(i, 0, r) rep(j, 0, c) if (grid[i][j] == '*') {
    dists[i][j] = 0;
    q.push(i * c + j);
  }

  while (sz(q)) {
    int ij = q.front();
    q.pop();
    int i = ij / c;
    int j = ij % c;

    int d = dists[i][j] + 1;

    for (auto [ni, nj] : dirs) {
      ni += i;
      nj += j;
      if (in_bound(ni, nj) && grid[ni][nj] != 'X' && d < dists[ni][nj]) {
        dists[ni][nj] = d;
        q.push(ni * c + nj);
        backs[ni][nj] = ij;
      }
    }
  }

  int ci = -1, cj = -1;
  int cdist = INT_MAX;

  rep(i, 0, r) rep(j, 0, c) if (targ[i][j] == '*' && dists[i][j] < cdist) {
    ci = i;
    cj = j;
    cdist = dists[i][j];
  }

  if (cdist == INT_MAX) {
    cout << "NO" << endl;
    return 0;
  }

  // find path to new spot
  vpii steps, steps2;

  int i_it = ci, j_it = cj;

  while (~backs[i_it][j_it]) {
    int ij = backs[i_it][j_it];
    i_it = ij / c;
    j_it = ij % c;
    steps.push_back({i_it, j_it});
  }

  // REMOVE START SQUARE
  // if (sz(steps)) steps.pop_back();

  reverse(all(steps));
  steps.push_back({ci, cj});

  // expand into new spot
  expander(ci, cj, steps2);
  steps2.erase(steps2.begin());

  vector<tuple<int, int, int, int>> output;

  int pi = -1, pj = -1;
  for (auto [ai, aj] : steps) {
    // print();

    if (grid[ai][aj] != '*') {
      int dij = delet();
      int di = dij / c;
      int dj = dij % c;
      // step here
      grid[di][dj] = '.';
      output.push_back({di, dj, ai, aj});
      // add to answer
    }

    if (~pi) {
      grid[pi][pj] = '*';
    }
    grid[ai][aj] = 'f';
    pi = ai;
    pj = aj;
  }

  for (auto [ai, aj] : steps2) {
    // print();

    if (grid[ai][aj] != '*') {
      int dij = delet();
      int di = dij / c;
      int dj = dij % c;
      // step here
      grid[di][dj] = '.';
      output.push_back({di, dj, ai, aj});
      // add to answer
    }

    grid[ai][aj] = 'f';
  }

  // print();

  cout << "YES\n";
  cout << sz(output) << endl;
  for (auto [a, b, c, d] : output)
    cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << ' ' << d + 1 << endl;

  return 0;
}
