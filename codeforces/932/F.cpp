#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <complex>
#include <iomanip>
#include <numeric>
#include <cassert>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

const ll INF = 1e18;
const ll MAXN = 2e5;

ll lmin(ll a, ll b) {
  return a < b ? a : b;
}

ll dmin(ll a, ll b) {
  return a < b ? a : b;
}

struct Line {
  ll m = 0, b = INF;

  ll apply(ll x) {
    return m * x + b;
  }

  Line() {}
  Line(ll _a, ll _b) : m(_a), b(_b) {}
};

struct Node {
  Line curr;
  Node *left, *right;
  Node(Line _curr) : curr(_curr), left(nullptr), right(nullptr) {}
};

struct LiChao {
  static void insert(Line new_line, ll l, ll r, Node *node) {
    if (r - 1 == l) {
      if (new_line.apply(l) < node->curr.apply(l)) {
        node->curr = new_line;
      }
      return;
    }
    ll mid = (l + r) / 2;
    if (new_line.m < node->curr.m) swap(new_line, node->curr);
    if (node->curr.apply(mid) > new_line.apply(mid)) {
      swap(new_line, node->curr);
      if (node->right != nullptr) {
        insert(new_line, mid, r, node->right);
      } else {
        node->right = new Node(new_line);
      }
    } else {
      if (node->left != nullptr) {
        insert(new_line, l, mid, node->left);
      } else {
        node->left = new Node(new_line);
      }
    }
  }

  static ll query(ll l, ll r, ll x, Node *node) {
    if (r - 1 == l) return node->curr.apply(x);
    ll mid = (l + r) / 2;
    if (x < mid && node->left) {
      return lmin(node->curr.apply(x), query(l, mid, x, node->left));
    } else if (node->right) {
      return lmin(node->curr.apply(x), query(mid, r, x, node->right));
    }
    return node->curr.apply(x);
  }

  static void delete_node(Node *node) {
    if (node->left) delete_node(node->left);
    if (node->right) delete_node(node->right);
    delete node;
  }

  static void merge(Node *new_node, Node *node) {
    if (node->curr.m != 0 || node->curr.b != INF) {
      insert(node->curr, -MAXN, MAXN, new_node);
    }
    if (node->left) merge(new_node, node->left);
    if (node->right) merge(new_node, node->right);
  }
};

vll a, b, dp;
vvll graph;

pair<ll, Node*> dfs(ll node, ll parent) {
  ll cnt = 0;
  Node *root = new Node(Line(0, INF));
  for (auto child : graph[node]) {
    if (child == parent) continue;
    if (child != parent) {
      auto [s, child_node] = dfs(child, node);
      if (cnt < s) swap(root, child_node);
      LiChao::merge(root, child_node);
      LiChao::delete_node(child_node);
      cnt += s;
    }
  }
  dp[node] = (cnt ? LiChao::query(-MAXN, MAXN, a[node], root) : 0);
  LiChao::insert(Line(b[node], dp[node]), -MAXN, MAXN, root);
  return make_pair(cnt + 1, root);
}

signed main() {
  ll n;
  cin >> n;
  a.resize(n);
  b.resize(n);
  dp.resize(n);
  graph.resize(n);
  for (ll i = 0; i < n; i++) cin >> a[i];
  for (ll i = 0; i < n; i++) cin >> b[i];
  for (ll i = 0; i < n - 1; i++) {
    ll u, v;
    cin >> u >> v;
    graph[u - 1].push_back(v - 1);
    graph[v - 1].push_back(u - 1);
  }
  dfs(0, -1);
  for (ll i = 0; i < n; i++) {
    cout << dp[i] << " ";
  }
  cout << endl;
  return 0;
}

