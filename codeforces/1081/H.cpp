#include <bits/stdc++.h>

using namespace std;

const int N = 234567;
const int LOG = 18;
const int ALPHA = 26;
const int base = 2333;
const int md0 = 1e9 + 7;
const int md1 = 1e9 + 9;

struct hash_t {
  int hash0, hash1;

  hash_t(int hash0 = 0, int hash1 = 0):hash0(hash0), hash1(hash1) {
  }

  hash_t operator + (const int &x) const {
    return hash_t((hash0 + x) % md0, (hash1 + x) % md1);
  };

  hash_t operator * (const int &x) const {
    return hash_t((long long)hash0 * x % md0, (long long)hash1 * x % md1);
  }

  hash_t operator + (const hash_t &x) const {
    return hash_t((hash0 + x.hash0) % md0, (hash1 + x.hash1) % md1);
  };

  hash_t operator - (const hash_t &x) const {
    return hash_t((hash0 + md0 - x.hash0) % md0, (hash1 + md1 - x.hash1) % md1);
  };

  hash_t operator * (const hash_t &x) const {
    return hash_t((long long)hash0 * x.hash0 % md0, (long long)hash1 * x.hash1 % md1);
  }

  long long get() {
    return (long long)hash0 * md1 + hash1;
  }
} ha[N], hb[N], power[N];

struct palindrome_tree_t {
  int n, total, p[N], pos[N], value[N], parent[N], go[N][ALPHA], ancestor[LOG][N];
  char s[N];

  palindrome_tree_t() {
    parent[0] = 1;
    value[1] = -1;
    total = 1;
    p[0] = 1;
  }

  int extend(int p, int w, int n) {
    while (s[n] != s[n - value[p] - 1]) {
      p = parent[p];
    }
    if (!go[p][w]) {
      int q = ++total, k = parent[p];
      while (s[n] != s[n - value[k] - 1]) {
        k = parent[k];
      }
      value[q] = value[p] + 2;
      parent[q] = go[k][w];
      go[p][w] = q;
      pos[q] = n;
    }
    return go[p][w];
  }

  void init() {
    for (int i = 1; i <= n; ++i) {
      p[i] = extend(p[i - 1], s[i] - 'a', i);
    }
    for (int i = 0; i <= total; ++i) {
      ancestor[0][i] = parent[i];
    }
    for (int i = 1; i < LOG; ++i) {
      for (int j = 0; j <= total; ++j) {
        ancestor[i][j] = ancestor[i - 1][ancestor[i - 1][j]];
      }
    }
  }

  int query(int r, int length) {
    r = p[r];
    if (value[r] <= length) {
      return value[r];
    }
    for (int i = LOG - 1; ~i; --i) {
      if (value[ancestor[i][r]] > length) {
        r = ancestor[i][r];
      }
    }
    return value[parent[r]];
  }

  bool check(int r, int length) {
    r = p[r];
    for (int i = LOG - 1; ~i; --i) {
      if (value[ancestor[i][r]] >= length) {
        r = ancestor[i][r];
      }
    }
    return value[r] == length;
  }
} A, B, RA, RB;

map<long long, int> fa, fb, ga, gb;
long long answer;
char a[N], b[N];
int n, m;

hash_t get_hash(hash_t *h, int l, int r) {
  return h[r] - h[l - 1] * power[r - l + 1];
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  scanf("%s %s", a + 1, b + 1);
  n = strlen(a + 1);
  m = strlen(b + 1);
  A.n = RA.n = n;
  B.n = RB.n = m;
  for (int i = 1; i <= n; ++i) {
    A.s[i] = RA.s[n - i + 1] = a[i];
    ha[i] = ha[i - 1] * base + a[i];
  }
  for (int i = 1; i <= m; ++i) {
    B.s[i] = RB.s[m - i + 1] = b[i];
    hb[i] = hb[i - 1] * base + b[i];
  }
  power[0] = hash_t(1, 1);
  for (int i = 1; i <= max(n, m); ++i) {
    power[i] = power[i - 1] * base;
  }
  A.init();
  B.init();
  RA.init();
  RB.init();
  answer = (long long)(A.total - 1) * (B.total - 1);
  for (int i = 2; i <= A.total; ++i) {
    ++fa[get_hash(ha, A.pos[i] - A.value[i] + 1, A.pos[i]).get()];
    int p = A.parent[i];
    if (p < 2) {
      continue;
    }
    int l = A.pos[i] - (A.value[i] - A.value[p]) + 1, r = A.pos[i];
    if (A.value[i] <= A.value[p] << 1) {
      ++ga[get_hash(ha, l, r).get()];
    }
  }
  for (int i = 2; i <= B.total; ++i) {
    ++fb[get_hash(hb, B.pos[i] - B.value[i] + 1, B.pos[i]).get()];
    int p = B.parent[i];
    if (p < 2) {
      continue;
    }
    int l = B.pos[i] - B.value[i] + 1, r = B.pos[i] - B.value[p];
    if (B.value[i] <= B.value[p] << 1) {
      ++gb[get_hash(hb, l, r).get()];
    }
  }
  for (int i = 2; i <= A.total; ++i) {
    int p = A.parent[i];
    if (p < 2) {
      continue;
    }
    int l = A.pos[i] - (A.value[i] - A.value[p]) + 1, r = A.pos[i];
    long long value = get_hash(ha, l, r).get();
    if (gb.count(value)) {
      answer -= gb[value];
    }
    int longest_palindrome_suffix = A.query(r, r - l + 1);
    if (longest_palindrome_suffix == r - l + 1) {
      continue;
    }
    if (RA.check(n - l + 1, r - l + 1 - longest_palindrome_suffix)) {
      int length = r - l + 1 - longest_palindrome_suffix;
      if (fb.count(get_hash(ha, l, l + length - 1).get()) && fb.count((get_hash(ha, l, r) * power[length] + get_hash(ha, l, l + length - 1)).get())) {
        --answer;
      }
      continue;
    }
    int longest_palindrome_prefix = RA.query(n - l + 1, r - l + 1);
    if (A.check(r, r - l + 1 - longest_palindrome_prefix)) {
      int length = longest_palindrome_prefix;
      if (fb.count(get_hash(ha, l, l + length - 1).get()) && fb.count((get_hash(ha, l, r) * power[length] + get_hash(ha, l, l + length - 1)).get())) {
        --answer;
      }
      continue;
    }
  }
  for (int i = 2; i <= B.total; ++i) {
    int p = B.parent[i];
    if (p < 2) {
      continue;
    }
    int l = B.pos[i] - B.value[i] + 1, r = B.pos[i] - B.value[p];
    long long value = get_hash(hb, l, r).get();
    if (ga.count(value)) {
      answer -= ga[value];
    }
    int longest_palindrome_suffix = B.query(r, r - l + 1);
    if (longest_palindrome_suffix == r - l + 1) {
      continue;
    }
    if (RB.check(m - l + 1, r - l + 1 - longest_palindrome_suffix)) {
      int length = longest_palindrome_suffix;
      if (fa.count(get_hash(hb, r - length + 1, r).get()) && fa.count((get_hash(hb, r - length + 1, r) * power[r - l + 1] + get_hash(hb, l, r)).get())) {
        --answer;
      }
      continue;
    }
    int longest_palindrome_prefix = RB.query(m - l + 1, r - l + 1);
    if (B.check(r, r - l + 1 - longest_palindrome_prefix)) {
      int length = r - l + 1 - longest_palindrome_prefix;
      if (fa.count(get_hash(hb, r - length + 1, r).get()) && fa.count((get_hash(hb, r - length + 1, r) * power[r - l + 1] + get_hash(hb, l, r)).get())) {
        --answer;
      }
      continue;
    }
  }
  for (int i = 2; i <= A.total; ++i) {
    int p = A.parent[i];
    if (p < 2) {
      continue;
    }
    int l = A.pos[i] - (A.value[i] - A.value[p]) + 1, r = A.pos[i];
    if (A.value[i] > A.value[p] << 1) {
      ++ga[get_hash(ha, l, r).get()];
    }
  }
  
  for (int i = 2; i <= B.total; ++i) {
    int p = B.parent[i];
    if (p < 2) {
      continue;
    }
    int l = B.pos[i] - B.value[i] + 1, r = B.pos[i] - B.value[p];
    if (B.value[i] > B.value[p] << 1) {
      ++gb[get_hash(hb, l, r).get()];
    }
  }
  
  for (auto p : ga) 
  {
    answer += (long long)p.second * gb[p.first];
  }
  printf("%lld\n", answer);
  return 0;
}