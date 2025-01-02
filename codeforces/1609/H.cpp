#include <bits/stdc++.h>
using namespace std;
 
template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) 
{
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
 
struct hash61 {
  static const uint64_t md = (1LL << 61) - 1;
  static uint64_t step;
  static vector<uint64_t> pw;
 
  uint64_t addmod(uint64_t a, uint64_t b) const {
    a += b;
    if (a >= md) a -= md;
    return a;
  }
 
  uint64_t submod(uint64_t a, uint64_t b) const {
    a += md - b;
    if (a >= md) a -= md;
    return a;
  }
 
  uint64_t mulmod(uint64_t a, uint64_t b) const {
    uint64_t l1 = (uint32_t) a, h1 = a >> 32, l2 = (uint32_t) b, h2 = b >> 32;
    uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    uint64_t ret = (l & md) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & md) + (ret >> 61);
    ret = (ret & md) + (ret >> 61);
    return ret - 1;
  }
 
  void ensure_pw(int sz) {
    int cur = (int) pw.size();
    if (cur < sz) {
      pw.resize(sz);
      for (int i = cur; i < sz; i++) {
        pw[i] = mulmod(pw[i - 1], step);
      }
    }
  }
 
  vector<uint64_t> pref;
  int n;
 
  template<typename T>
  hash61(const T& s) {
    n = (int) s.size();
    ensure_pw(n + 1);
    pref.resize(n + 1);
    pref[0] = 1;
    for (int i = 0; i < n; i++) {
      pref[i + 1] = addmod(mulmod(pref[i], step), s[i]);
    }
  }
 
  inline uint64_t operator()(const int from, const int to) const {
    assert(0 <= from && from <= to && to <= n - 1);
    return submod(pref[to + 1], mulmod(pref[from], pw[to - from + 1]));
  }
};
 
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
 
uint64_t hash61::step = (md >> 2) + rng() % (md >> 1);
vector<uint64_t> hash61::pw = vector<uint64_t>(1, 1);
 
hash61 hasher((string) "a");
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<long long> init_x(n);
  for (int i = 0; i < n; i++) {
    cin >> init_x[i];
  }
  vector<vector<int>> f(n, vector<int>(k));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      cin >> f[i][j];
    }
  }
  const long long inf = (long long) 1.01e18;
  vector<vector<long long>> x(1, init_x);
  vector<long long> t(1, 0);
  vector<int> link(1, -1);
  map<uint64_t, int> mp;
  while (t.back() < inf) {
    int j = (int) (t.back() % k);
    if (j == 0) {
      uint64_t h = 0;
      for (int i = 0; i < n - 1; i++) {
        long long diff = x.back()[i + 1] - x.back()[i];
        h = hasher.addmod(hasher.mulmod(h, hash61::step), min(diff, 2LL * k) + 42);
      }
      auto it = mp.find(h);
      if (it != mp.end()) {
        int from = it->second;
        int span = ((int) t.size() - 1) - from;
        assert(span % k == 0);
        long long reps = inf;
        for (int i = 0; i < n - 1; i++) {
          long long diff_old = x[from][i + 1] - x[from][i];
          long long diff_new = x.back()[i + 1] - x.back()[i];
          if (diff_new < diff_old) {
            long long decay = diff_old - diff_new;
            long long mn = inf;
            for (int z = from; z < (int) t.size() - 1; z++) {
              mn = min(mn, x[z][i + 1] - x[z][i]);
            }
            reps = min(reps, (mn - 2) / decay - 1);
          }
        }
        if (reps > 0) {
          link.push_back(from);
          if (reps >= inf / span) {
            break;
          }
          t.push_back(t.back() + reps * span);
          x.push_back(x.back());
          for (int i = 0; i < n; i++) {
            x.back()[i] += reps * (x[x.size() - 2][i] - x[from][i]);
          }
          mp.clear();
          continue;
        }
      }
      mp[h] = (int) t.size() - 1;
    }
    t.push_back(t.back() + 1);
    x.push_back(x.back());
    link.push_back(-1);
    vector<tuple<int, int, int>> st;
    for (int i = 0; i < n; i++) {
      st.emplace_back(i, i, f[i][j]);
      while (st.size() >= 2) {
        if ((get<2>(st.back()) < 0 || get<2>(st[st.size() - 2]) > 0) && x.back()[get<1>(st[st.size() - 2])] + 1 == x.back()[get<0>(st.back())]) {
          get<1>(st[st.size() - 2]) = get<1>(st.back());
          get<2>(st[st.size() - 2]) += get<2>(st.back());
          st.pop_back();
        } else {
          break;
        }
      }
    }
    for (int i = 0; i < (int) st.size(); i++) {
      int dir = (get<2>(st[i]) > 0 ? 1 : (get<2>(st[i]) < 0 ? -1 : 0));
      if (dir == 1 && i + 1 < (int) st.size() && x[x.size() - 2][get<0>(st[i + 1])] - x[x.size() - 2][get<1>(st[i])] == 2 && get<2>(st[i + 1]) < 0 && abs(get<2>(st[i])) <= abs(get<2>(st[i + 1]))) {
        dir = 0;
      }
      if (dir == -1 && i - 1 >= 0 && x[x.size() - 2][get<0>(st[i])] - x[x.size() - 2][get<1>(st[i - 1])] == 2 && get<2>(st[i - 1]) > 0 && abs(get<2>(st[i])) < abs(get<2>(st[i - 1]))) {
        dir = 0;
      }
      for (int z = get<0>(st[i]); z <= get<1>(st[i]); z++) {
        x.back()[z] += dir;
      }
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int rid;
    long long T;
    cin >> rid >> T;
    --rid;
    auto it = lower_bound(t.begin(), t.end(), T);
    if (it != t.end() && *it == T) {
      int id = (int) (it - t.begin());
      cout << x[id][rid] << '\n';
      continue;
    }
    assert(it != t.begin());
    --it;
    int id = (int) (it - t.begin());
    assert(link[id + 1] != -1);
    long long span = id - link[id + 1];
    assert(span % k == 0);
    long long reps = (T - t[id]) / span + 1;
    long long rm = (T - t[id]) % span;
    long long ans = x[link[id + 1] + rm][rid];
    ans += (x[id][rid] - x[link[id + 1]][rid]) * reps;
    cout << ans << '\n';
  }
  return 0;
}
