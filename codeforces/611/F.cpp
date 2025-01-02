#include <bits/stdc++.h>
using namespace std;

template<int MOD_> struct modnum {
  static constexpr int MOD = MOD_;
  static_assert(MOD_ > 0, "MOD must be positive");

private:
  using ll = long long;

  int v;

  static int minv(int a, int m) {
    a %= m;
    assert(a);
    return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
  }

public:

  modnum() : v(0) {}
  modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
  explicit operator int() const { return v; }
  friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
  friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }

  friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
  friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

  modnum inv() const {
    modnum res;
    res.v = minv(v, MOD);
    return res;
  }
  friend modnum inv(const modnum& m) { return m.inv(); }
  modnum neg() const {
    modnum res;
    res.v = v ? MOD-v : 0;
    return res;
  }
  friend modnum neg(const modnum& m) { return m.neg(); }

  modnum operator- () const {
    return neg();
  }
  modnum operator+ () const {
    return modnum(*this);
  }

  modnum& operator ++ () {
    v ++;
    if (v == MOD) v = 0;
    return *this;
  }
  modnum& operator -- () {
    if (v == 0) v = MOD;
    v --;
    return *this;
  }
  modnum& operator += (const modnum& o) {
    v += o.v;
    if (v >= MOD) v -= MOD;
    return *this;
  }
  modnum& operator -= (const modnum& o) {
    v -= o.v;
    if (v < 0) v += MOD;
    return *this;
  }
  modnum& operator *= (const modnum& o) {
    v = int(ll(v) * ll(o.v) % MOD);
    return *this;
  }
  modnum& operator /= (const modnum& o) {
    return *this *= o.inv();
  }

  friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
  friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
  friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
  friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
  friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
  friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

template<typename T> T pow(T a, long long b) {
  assert(b >= 0);
  T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}

template<int M> string to_string(modnum<M> x) {
  return to_string(int(x));
}

using num = modnum<int(1e9) + 7>;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, h, w;
  string s;
  while (cin >> n >> h >> w >> s)
  {
    int x = 0, minX = 0, maxX = 0;
    int y = 0, minY = 0, maxY = 0;
    vector<tuple<int, int, int>> changes;
    for (int i = 0; i < n; i++)
      if (s[i] == 'U')
      {
        x--;
        if (x < minX)
        {
          minX = x;
          changes.push_back({x, i + 1, 0});
        }
      }
      else if (s[i] == 'D')
      {
        x++;
        if (x > maxX)
        {
          maxX = x;
          changes.push_back({x, i + 1, 0});
        }
      }
      else if (s[i] == 'L')
      {
        y--;
        if (y < minY)
        {
          minY = y;
          changes.push_back({y, i + 1, 1});
        }
      }
      else
      {
        y++;
        if (y > maxY)
        {
          maxY = y;
          changes.push_back({y, i + 1, 1});
        }
      }

    // first turn
    int row = h, col = w;
    num ans = 0;
    for (auto [_, step, isY] : changes)
    {
      if (!isY)
      {
        ans += num(step) * col;
        row--;
      }
      else
      {
        ans += num(step) * row;
        col--;
      }

      if (!row || !col)
        break;
    }

    if (!row || !col)
    {
      cout << ans << endl;
      continue;
    }

    if (!x && !y)
    {
      cout << -1 << endl;
      continue;
    }

    // remove changes that don't hit the wall from now on
    vector<tuple<int, int, int>> validChanges;
    for (auto [v, step, isY] : changes)
      if (!isY)
      {
        if (v + x < minX || v + x > maxX)
          validChanges.push_back({v, step, isY});
      }
      else
      {
        if (v + y < minY || v + y > maxY)
          validChanges.push_back({v, step, isY});
      }

    for (int turn = 1; row && col; turn++)
      for (auto [_, step, isY] : validChanges)
      {
        num totalStep = num(turn) * n + step;
        if (!isY)
        {
          ans += totalStep * col;
          row--;
        }
        else
        {
          ans += totalStep * row;
          col--;
        }

        if (!row || !col)
          break;
      }

    cout << ans << endl;
  }
}
