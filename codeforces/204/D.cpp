#include <bits/stdc++.h>
using namespace std;

/**
 * Author: Lukas Polacek
 * Date: 2009-09-28
 * License: CC0
 * Source: folklore
 * Description: Operators for modular arithmetic. You need to set {\tt mod} to
 * some number first and then you can use the structure.
 */
/**
 * Author: Unknown
 * Date: 2002-09-15
 * Source: predates tinyKACTL
 * Description: Finds two integers $x$ and $y$, such that $ax+by=\gcd(a,b)$. If
 * you just need gcd, use the built in \texttt{\_\_gcd} instead.
 * If $a$ and $b$ are coprime, then $x$ is the inverse of $a \pmod{b}$.
 */
int64_t euclid(int64_t a, int64_t b, int64_t &x, int64_t &y) {
  if (!b) return x = 1, y = 0, a;
  int64_t d = euclid(b, a % b, y, x);
  return y -= a / b * x, d;
}
const int64_t mod = 1'000'000'007;
struct Mod {
  int64_t x;
  Mod(int64_t xx) : x(xx) {}
  Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
  Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
  Mod operator*(Mod b) { return Mod((x * b.x) % mod); }
  Mod operator/(Mod b) { return *this * invert(b); }
  Mod invert(Mod a) {
    int64_t x, y, g = euclid(a.x, mod, x, y);
    assert(g == 1);
    return Mod((x + mod) % mod);
  }
  Mod operator^(int64_t e) {
    if (!e) return Mod(1);
    Mod r = *this ^ (e / 2);
    r = r * r;
    return e & 1 ? *this * r : r;
  }
};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T> inline T get_rand(T le, T ri) {
  assert(le <= ri);
  return uniform_int_distribution<T>(le, ri)(rng);
}

vector<Mod> go(const string& s, int k, char black, char white) {
  int n = ssize(s);
  vector<Mod> dp(n, 0);
  //dp[i] = # strings of [0..i] with no runs of len k of all B's (backdoor), and s[i] = 'A'

  vector<Mod> pref(n, 0);
  int last_w = -1;
  for(int i = 0; i < n; i++) {
    if(s[i] != black) {
      Mod curr_dp = 0;
      int prev_white = max(i-k, last_w);
      if(prev_white == -1) {
        curr_dp = (i ? pref[i-1] : Mod(0)) + Mod(1);
      } else {
        assert(i);
        curr_dp = pref[i-1] - (prev_white>0?pref[prev_white - 1]:0);
      }
      pref[i] = curr_dp;
    }

    if(i) pref[i] = pref[i] + pref[i-1];
    if(s[i] == white) last_w = i;

    int prev_white = max(i-k+1, last_w);
    if(prev_white == -1) {
      dp[i] = pref[i] + Mod(1);
    } else {
      dp[i] = pref[i] - (prev_white>0?pref[prev_white - 1]:0);
    }
  }
  return dp;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;

  vector<int> pref(n);
  vector<int> pref_w(n);
  for(int i = 0; i < n; i++) {
    pref[i] = (s[i] == 'X');
    pref_w[i] = (s[i] == 'W');
    if(i) {
      pref[i] += pref[i-1];
      pref_w[i] += pref_w[i-1];
    }
  }

  auto sum = [&](int le, int ri) -> int {
    int sum = 0;
    if(ri) sum += pref[ri-1];
    if(le) sum -= pref[le-1];
    return sum;
  };

  auto sum_w = [&](int le, int ri) -> int {
    int sum = 0;
    if(ri) sum += pref_w[ri-1];
    if(le) sum -= pref_w[le-1];
    return sum;
  };

  auto dp1 = go(s, k, 'B', 'W');
  auto dp2 = go(string(rbegin(s), rend(s)), k, 'W', 'B');

  reverse(begin(dp2), end(dp2));
  /*
  for(Mod val : dp1) cout << val.x << " ";
  cout << endl;


  for(Mod val : dp2) cout << val.x << " ";
  cout << endl;
  */


  Mod res = 0;
  for(int i = 0; i+k <= n; i++) {
    //[i,i+k) is first range of B's

    if(sum_w(i,i+k) > 0) {
      continue;
    }
    if(i && s[i-1] == 'B') continue;

    Mod before = 1;
    if(i-2>=0) before = dp1[i-2];

    Mod after = 0;
    if(i+k<n) after = (Mod(2)^sum(i+k,n)) - dp2[i+k];

    res = res + before * after;
  }
  cout << res.x << '\n';

  return 0;
}
