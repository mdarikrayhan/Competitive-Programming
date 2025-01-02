#include <bits/stdc++.h>

using namespace std;

const int MAX = 1111111;

struct Node {
  int sum;
  int val;
  Node() {
    sum = 0;
    val = 0;
  }
};

Node st[8 * MAX];

Node operator + (Node a, Node b) {
  Node ret;
  ret.sum = a.sum + b.sum;
  ret.val = max(a.val + b.sum, b.val);
  return ret;
}

void Modify(int v, int l, int r, int i, int x) {
  if (l == r) {
    st[v].sum += x;
    st[v].val += x;
    return;
  }
  int mid = (l + r) >> 1;
  if (i <= mid) {
    Modify(v * 2, l, mid, i, x);
  } else {
    Modify(v * 2 + 1, mid + 1, r, i, x);
  }
  st[v] = st[v * 2] + st[v * 2 + 1];
}

Node Query(int v, int l, int r, int ll, int rr) {
  if (ll <= l && r <= rr) {
    return st[v];
  }
  int mid = (l + r) / 2;
  if (rr <= mid) {
    return Query(v * 2, l, mid, ll, rr);
  } else if (ll > mid) {
    return Query(v * 2 + 1, mid + 1, r, ll, rr);
  } else {
    return Query(v * 2, l, mid, ll, rr) + Query(v * 2 + 1, mid + 1, r, ll, rr);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    Modify(1, 1, MAX, a[i], +1);
  }
  for (int i = 0; i < m; i++) {
    Modify(1, 1, MAX, b[i], -1);
  }
  int q;
  cin >> q;
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int i, x;
      cin >> i >> x;
      --i;
      Modify(1, 1, MAX, a[i], -1);
      a[i] = x;
      Modify(1, 1, MAX, a[i], +1);
    } else {
      int i, x;
      cin >> i >> x;
      --i;
      Modify(1, 1, MAX, b[i], +1);
      b[i] = x;
      Modify(1, 1, MAX, b[i], -1);
    }
    int low = 1, high = MAX, res = -1;
    while (low <= high) {
      int mid = (low + high) >> 1;
      if (Query(1, 1, MAX, mid, MAX).val > 0) {
        res = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    cout << res << '\n';
  }
  return 0;
}