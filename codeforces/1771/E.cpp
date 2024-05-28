#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define FOR(i, to) for (int i = 0; i < (to); ++i)
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pair<int, int> > vpi;
typedef pair<ll,ll> pll;
typedef vector<pair<ll, ll> > vpl;
typedef vector<string> vs;
char en = '\n';
#define MOD 998244353
string s,s1;
#define KMAX 80
#define MX 202020

template<int MODX>
struct ModInt {
  unsigned x;
  ModInt() : x(0) { }
  ModInt(signed sig) : x(((sig%MODX)+MODX)%MODX) {  }
  ModInt(signed long long sig) : x(((sig%MODX)+MODX)%MODX) { }
  int get() const { return (int)x; }
  ModInt pow(ll p) { ModInt res = 1, a = *this; while (p) { if (p & 1) res *= a; a *= a; p >>= 1; } return res; }
 
  ModInt &operator+=(ModInt that) { if ((x += that.x) >= MODX) x -= MODX; return *this; }
  ModInt &operator-=(ModInt that) { if ((x += MODX - that.x) >= MODX) x -= MODX; return *this; }
  ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MODX; if (x < 0) x += MODX; return *this; }
  ModInt &operator/=(ModInt that) { return (*this) *= that.pow(MODX - 2); }
 
  ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
  ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
  ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
  ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
  bool operator<(ModInt that) const { return x < that.x; }
  friend ostream& operator<<(ostream &os, ModInt a) { os << a.x; return os; }
};

class PartialSum2D {
public:
    PartialSum2D(const std::vector<std::vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = rows > 0 ? matrix[0].size() : 0;
        sums.resize(rows + 1, std::vector<int>(cols + 1, 0));
        
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                sums[i][j] = matrix[i-1][j-1] + sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1];
            }
        }
    }

    int sum(int row1, int col1, int row2, int col2) {
        return sums[row2 + 1][col2 + 1] - sums[row1][col2 + 1] - sums[row2 + 1][col1] + sums[row1][col1];
    }

private:
    std::vector<std::vector<int>> sums;
};

  int N,M;
int make1(int j1, int j2, PartialSum2D &s, vvi &m) {
  int left = 0;
  int b1 = 0;
  int b2 = 0;
  int goodInd = 0;
  int ret = 0;
  FOR(i, N) {
    if (m[i][j1] == 2 || m[i][j2] == 2) {
      left = i + 1;
      b1 = b2 = 0;
      continue;
    }
    if (m[i][j1] == 1) ++b1;
    if (m[i][j2] == 1) ++b2;
    while (b1 + b2 >= 2) {
      b1 -= m[left][j1];
      b2 -= m[left][j2];
      ++left;
    }
    if (i) {
      if (s.sum(i-1, j1+1, i-1, j2-1) == 0)  goodInd = i-1;
    }
    if (left + 2 <= i) {
      if (goodInd > left) {
        ret = max(ret, (i - left + 1) * 2 + (j2 - j1-1));
      }
    }
  }
  return ret;
}

int make2(int j1, int j2, PartialSum2D &s, vvi &m) {
  int left = 0;
  int b1 = 0;
  int b2 = 0;
  int goodInd = 0;
  int ret = 0;
  FOR(i, N) {
    if (m[i][j1] || m[i][j2]) {
      left = i + 1;
      continue;
    }
    
    if (i) {
      if (s.sum(i-1, j1+1, i-1, j2-1) <= 1)  goodInd = i-1;
    }
    if (left + 2 <= i) {
      if (goodInd > left) {
        ret = max(ret, (i - left + 1) * 2 + (j2 - j1-1));
      }
    }
  }
  return ret;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  vvi m(N, vector<int>(M,0));

  FOR(i, N) {
    string s;
    cin >> s;
    FOR(j, M) {
      if (s[j] == '#') m[i][j] = 2;
      if (s[j] == 'm') m[i][j] = 1;
    }
  }
  PartialSum2D s(m);
  int ret = 0;
  FOR(j1, M) {
    rep(j2, j1 + 2, M) {
      ret = max(ret, make1(j1,j2,s,m));
      ret = max(ret, make2(j1,j2,s,m));
    }  
  }
  cout << ret << endl;

}