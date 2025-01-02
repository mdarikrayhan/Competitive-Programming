#include <bits/stdc++.h>

using namespace std;

const int inf = (int) 1e9;

struct Line {
  long long k;
  long long n;
  int idx;
  long long val(long long x) {
    return k * x + n;
  }
  Line(long long _k = 0, long long _n = (long long) -1e18) : k(_k), n(_n) {}
};

vector<int> xs;

const int MAX = 2e6;

int root, tsz, ch[MAX][2];
Line st[MAX];

void Modify(int &v, int l, int r, Line ln) {
  if (!v) {
    v = ++tsz;
    st[v].k = 0;
    st[v].n = (long long) -1e18;
  }
  int mid = (l + r) >> 1;
  if (ln.val(xs[mid]) > st[v].val(xs[mid])) {
    swap(ln, st[v]);
  }
  if (l == r) {
    return;
  }
  if (ln.val(xs[l]) > st[v].val(xs[l])) {
    Modify(ch[v][0], l, mid, ln);
  } else {
    Modify(ch[v][1], mid + 1, r, ln);
  }
}

pair<long long, int> Get(int v, int l, int r, int i) {
  if (l == r) {
    return {st[v].val(xs[i]), st[v].idx};
  }
  int mid = (l + r) >> 1;
  if (i <= mid) {
    return max({st[v].val(xs[i]), st[v].idx}, Get(ch[v][0], l, mid, i));
  } else {
    return max({st[v].val(xs[i]), st[v].idx}, Get(ch[v][1], mid + 1, r, i));
  }
}

void Clear() {
  while (tsz > 0) {
    ch[tsz][0] = 0;
    ch[tsz][1] = 0;
    st[tsz].k = 0;
    st[tsz].n = (long long) -1e18;
    tsz--;
  }
  ch[tsz][0] = 0;
  ch[tsz][1] = 0;
  st[tsz].k = 0;
  st[tsz].n = (long long) -1e18;
  root = 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 1; i < n; i++) {
    int u, v, w; 
    cin >> u >> v >> w;
    --u; --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  vector<pair<int, int>> all;
  vector<int> fir(n);
  vector<long long> d(n);
  vector<int> dfn(n);
  vector<int> dfo(n);
  vector<int> par(n);
  vector<long long> mx(n);
  int T = -1;
  function<void(int, int)> Dfs = [&](int v, int pv) {
    par[v] = pv;
    dfn[v] = ++T;
    fir[v] = (int) all.size();
    all.push_back({dfn[v], v});
    for (auto e : g[v]) {
      int to = e.first;
      int w = e.second;
      if (to == pv) {
        continue;
      }
      d[to] = d[v] + w;
      Dfs(to, v);
      mx[v] = max(mx[v], mx[to] + w);
      all.push_back({dfn[v], v});
    }
    dfo[v] = ++T;
  };
  Dfs(0, 0);
  int sz = (int) all.size();
  const int L = 20;
  vector<vector<pair<int, int>>> st_min(sz, vector<pair<int, int>>(L));
  for (int i = 0; i < sz; i++) {
    st_min[i][0] = all[i];
  }
  for (int j = 1; j < L; j++) {
    for (int i = 0; i + (1 << j) <= sz; i++) {
      st_min[i][j] = min(st_min[i][j - 1], st_min[i + (1 << (j - 1))][j - 1]);
    }
  }
  vector<int> logs(sz + 1);
  for (int i = 2; i <= sz; i++) {
    logs[i] = logs[i >> 1] + 1;
  }
  function<pair<int, int>(int, int)> Query = [&](int l, int r) {
    int k = logs[r - l + 1];
    return min(st_min[l][k], st_min[r - (1 << k) + 1][k]);
  };
  function<int(int, int)> LCA = [&](int x, int y) {
    if (fir[x] > fir[y]) {
      swap(x, y);
    }
    return Query(fir[x], fir[y]).second;
  };
  function<long long(int, int)> GetDist = [&](int x, int y) {
    return d[x] + d[y] - 2 * d[LCA(x, y)];
  };
  T += 1;
  vector<int> idx(T);
  for (int i = 0; i < n; i++) {
    idx[dfn[i]] = i;
    idx[dfo[i]] = i;
  }
  function<pair<int, int>(pair<int, int>, pair<int, int>)> Merge = [&](pair<int, int> a, pair<int, int> b) {
    tuple<long long, int, int> best = make_tuple(GetDist(a.first, a.second), a.first, a.second);
    best = max(best, make_tuple(GetDist(a.first, b.first), a.first, b.first));
    best = max(best, make_tuple(GetDist(a.first, b.second), a.first, b.second));
    best = max(best, make_tuple(GetDist(a.second, b.first), a.second, b.first));
    best = max(best, make_tuple(GetDist(a.second, b.second), a.second, b.second));
    best = max(best, make_tuple(GetDist(b.first, b.second), b.first, b.second));
    return make_pair(get<1>(best), get<2>(best));
  };
  vector<pair<int, int>> pref(T);
  vector<pair<int, int>> suff(T);
  pref[0] = make_pair(idx[0], idx[0]);
  for (int i = 1; i < T; i++) {
    pref[i] = Merge(pref[i - 1], make_pair(idx[i], idx[i]));
  }
  suff[T - 1] = make_pair(idx[T - 1], idx[T - 1]);
  for (int i = T - 2; i >= 0; i--) {
    suff[i] = Merge(suff[i + 1], make_pair(idx[i], idx[i]));
  }
  vector<vector<Line>> my(n);
  for (int i = 0; i < n; i++) {
    for (auto p : g[i]) {
      int to = p.first;
      int w = p.second;
      if (to == par[i]) {
        long long v = 0;
        pair<int, int> f = pref[dfn[i] - 1];
        v = max(v, GetDist(i, f.first));
        v = max(v, GetDist(i, f.second));
        f = suff[dfo[i] + 1];
        v = max(v, GetDist(i, f.first));
        v = max(v, GetDist(i, f.second));
        my[i].push_back({w, v - w});
        continue;
      }
      long long v = mx[to];
      my[i].push_back({w, v});
    }
  }
  int q;
  cin >> q;
  vector<vector<pair<int, int>>> qs(n);
  for (int i = 0; i < q; i++) {
    int v, k;
    cin >> v >> k;
    --v;
    qs[v].emplace_back(k, i);
  }
  long long diam = GetDist(pref[T - 1].first, pref[T - 1].second);
  vector<vector<long long>> res(q, vector<long long>(2));
  mt19937 rng(time(0));
  for (int i = 0; i < n; i++) {
    my[i].push_back(Line(0, 0));
    sort(qs[i].rbegin(), qs[i].rend());
    sort(my[i].begin(), my[i].end(), [&](Line a, Line b) {
      if (a.k != b.k) {
        return a.k < b.k;
      } else {
        return a.n < b.n;
      }
    });
    int sz = (int) my[i].size();
    xs.clear();
    for (auto &p : qs[i]) {
      xs.push_back(p.first);
    }
    xs.push_back(0);
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    for (int j = 0; j < sz; j++) {
      Line ln = my[i][j];
      ln.idx = j;
      Modify(root, 0, (int) xs.size() - 1, ln);
    }
    vector<vector<pair<int, int>>> pqs(sz), sqs(sz);
    for (auto &p : qs[i]) {
      int x = p.first;
      int qi = p.second;
      pair<long long, int> val = Get(root, 0, (int) xs.size() - 1, (int) (lower_bound(xs.begin(), xs.end(), x) - xs.begin()));
      res[qi][0] = val.first;
      int idx = val.second;
      if (idx > 0) {
        pqs[idx - 1].push_back(p);
      }
      if (idx + 1 < sz) {
        sqs[idx + 1].push_back(p);
      }
    }
    Clear();
    for (int j = 0; j < sz; j++) {
      Modify(root, 0, (int) xs.size() - 1, my[i][j]);
      for (auto &p : pqs[j]) {
        int k = p.first;
        int qi = p.second;
        res[qi][1] = max(res[qi][1], Get(root, 0, (int) xs.size() - 1, (int) (lower_bound(xs.begin(), xs.end(), k) - xs.begin())).first);
      }
    }
    Clear();
    for (int j = sz - 1; j >= 0; j--) {
      Modify(root, 0, (int) xs.size() - 1, my[i][j]);
      for (auto &p : sqs[j]) {
        int k = p.first;
        int qi = p.second;
        res[qi][1] = max(res[qi][1], Get(root, 0, (int) xs.size() - 1, (int) (lower_bound(xs.begin(), xs.end(), k) - xs.begin())).first);
      }
    }
    Clear();
  }
  for (int i = 0; i < q; i++) {
    cout << max(diam, res[i][0] + res[i][1]) << '\n';
  }
  return 0;
}