#include <bits/stdc++.h>
using namespace std;

// clang-format off
template <typename T, typename = void> struct is_iterable : false_type {};template <typename T>struct is_iterable<    T, void_t<decltype(begin(declval<T>())), decltype(end(declval<T>()))>>    : true_type {};template <typename T>typename enable_if<is_iterable<T>::value && !is_same<T, string>::value,ostream &>::type operator<<(ostream &cout, T const &v);template <typename A, typename B>ostream &operator<<(ostream &cout, pair<A, B> const &p) {  return cout << "(" << p.first << ", " << p.second << ")";}template <typename T>typename enable_if<is_iterable<T>::value && !is_same<T, string>::value, ostream &>::type operator<<(ostream &cout, T const &v) {  cout << "[";  for (auto it = v.begin(); it != v.end();) {cout << *it; if (++it != v.end()) cout << ", ";  } return cout << "]";}

#ifdef LOCAL
  void dbg_out() { cout << endl; } template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
  #define debug(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
  #define debug(...) "zzz"
#endif
// clang-format on

using ll = long long;
using ld = long double;
using pii = pair<ll, ll>;

#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second

constexpr int K = 26;
struct Vertex {
  array<int, K> next;
  bool terminal = false;
  int terminal_idx = -1;
  int p = -1;
  char pch;
  int depth = 0;
  int link = 0;
  int next_terminal = 0;
  array<int, K> go;

  Vertex(int p, char ch, int depth) : p(p), pch(ch), depth(depth) {
    fill(next.begin(), next.end(), 0);
    fill(go.begin(), go.end(), 0);
  }
};

class AhoCorasick {
public:
  AhoCorasick() : t(1, {-1, '$', 0}) {}

  int add_string(string const &s, int idx) {
    // returns idx of final node
    int v = 0;
    for (char ch : s) {
      int c = ch - 'a';
      if (!t[v].next[c]) {
        t[v].next[c] = t.size();
        t.emplace_back(v, ch, t[v].depth + 1);
      }
      v = t[v].next[c];
    }
    t[v].terminal = true;
    t[v].terminal_idx = idx;
    return v;
  }

  void push_links() {
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      int v = q.front();
      auto &cur = t[v];
      auto &link = t[cur.link];
      q.pop();
      cur.next_terminal = link.terminal ? cur.link : link.next_terminal;

      for (int c = 0; c < K; c++) {
        if (cur.next[c]) {
          t[cur.next[c]].link = v ? link.next[c] : 0;
          q.push(cur.next[c]);
        } else {
          cur.next[c] = link.next[c];
        }
      }
    }
  }

  int transition(int idx, char c) { return t[idx].next[c - 'a']; }

  Vertex const &getInfo(int idx) { return t[idx]; }

  vector<Vertex> t;
};

template <typename T> struct fen {
  vector<T> tr;
  ll mxn;

  fen(ll sz) {
    mxn = sz;
    tr.assign(sz + 5, 0);
  }

  void upd(ll g, T k) {
    g++;
    assert(g != 0);
    for (; g <= mxn; g += g & -g)
      tr[g] += k;
  }

  T ge(ll g) {
    g++;
    T res = 0;
    for (; g; g -= g & -g)
      res += tr[g];
    return res;
  }

  T rng(ll l, ll r) { return ge(r) - ge(l - 1); }
};

void solve() {
  // open
  int n;
  cin >> n;

  vector e(n, vector<int>());
  vector<char> ass(n);
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      char x;
      cin >> x;
      ass[i] = x;
    } else {
      int p;
      char x;
      cin >> p >> x;
      p--;
      e[p].pb(i);
      ass[i] = x;
    }
  }

  int q;
  cin >> q;

  vector<int> string_id(q, -1);
  vector query_bin(n, vector<int>());
  vector<string> what_string(q);

  for (int qid = 0; qid < q; qid++) {
    int i;
    cin >> i;
    i--;

    cin >> what_string[qid];
    query_bin[i].pb(qid);
  }

  vector<string> wt = what_string;
  sort(all(wt));
  wt.erase(unique(all(wt)), wt.end());

  for (int i = 0; i < q; i++) {
    string_id[i] = lower_bound(all(wt), what_string[i]) - wt.begin();
  }

  int cc = (int)wt.size();
  AhoCorasick ac;

  vector<int> aho_id(cc);
  for (int i = 0; i < cc; i++) {
    aho_id[i] = ac.add_string(wt[i], i);
  }
  ac.push_links();

  vector<bool> v(n);
  vector<ll> ans(q);

  int num_aho_states = (int)ac.t.size();
  vector elink(num_aho_states, vector<int>());
  for (int i = 1; i < num_aho_states; i++)
    elink[ac.t[i].link].pb(i);

  vector<int> tin(num_aho_states), tout(num_aho_states);
  int euler = 0;
  auto dfs_aho = [&](auto &dfs, int g) -> void {
    tin[g] = euler++;
    for (auto u : elink[g]) {
      dfs(dfs, u);
    }
    tout[g] = euler++;
  };
  dfs_aho(dfs_aho, 0);

  fen<ll> tree(euler * 2);
  auto dfs = [&](auto &dfs, int g, int p_aho) -> void {
    v[g] = true;
    int c_aho = ac.transition(p_aho, ass[g]);

    tree.upd(tin[c_aho], 1);

    for (const auto qid : query_bin[g]) {
      int st_id = string_id[qid];
      int tid = aho_id[st_id];
      ans[qid] = tree.rng(tin[tid], tout[tid]);
    }

    for (auto u : e[g]) {
      dfs(dfs, u, c_aho);
    }

    tree.upd(tin[c_aho], -1);
  };

  for (int i = 0; i < n; i++) {
    if (v[i])
      continue;
    dfs(dfs, i, 0);
  }

  for (auto &u : ans)
    cout << u << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(false);

  ll T = 1;
  // cin >> T;
  for (int t = 0; t < T; t++)
    solve();

  cout.flush();
  return 0;
}