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
typedef ModInt<MOD> mint;

struct ups {
  int e;
  mint t;
};

class SegmentTree {
public:
    vector<mint> aint; // Segment tree array
    vector<ups> up;   // Lazy propagation array
    vector<int> v;    // Input data array
    int N;         // Maximum size of the array
    ups combine(ups up1, ups up2) {
      if (up2.e == 0) return up1;

      if (up1.e == 2) return up1;
      if (up1.e == 3) return up1;
      if (up1.e == 1) {
        if (up2.e == 1) {
          up1.t *= up2.t;
          return up1;
        } else {
          return up2;
        }
      }
      return up1;
    }
    // Function to apply lazy propagation
    void relax(int nod, int st, int dr) {
        if (up[nod].e == 0) return;
        if (up[nod].e == 1) {
          aint[nod] *= up[nod].t;
        } else if (up[nod].e == 2) {
          aint[nod] += up[nod].t;
        } else if (up[nod].e == 3) {
          aint[nod] = 0;
        }
        if (st != dr) {
          up[2 * nod] = combine(up[nod], up[nod*2]);
          up[2 * nod + 1] = combine(up[nod], up[2 * nod + 1]);    
        }
        up[nod].e = 0;
    }
 
    // Utility function to merge child node values
    void make(int nod, int st, int dr) {
        int mij = (st + dr) / 2;
        relax(nod, st, dr);
        relax(2 * nod, st, mij);
        relax(2 * nod + 1, mij + 1, dr);
        aint[nod] = aint[2 * nod] + aint[2 * nod + 1];
    }

    vector<mint> gall;

    void maker(int nod, int st,int dr) {
      relax(nod, st, dr);
      if (st == dr) {
        gall.pb(aint[nod]);
      } else {

      int mij = (st + dr) / 2;
      maker(2 * nod, st, mij);
      maker(2 * nod + 1, mij + 1, dr);
      }
    }

    vector<mint> getAll() {
      gall.clear();
      maker(1, 0, N-1);
      return gall;
    }
 
 
    SegmentTree(int Nx) {
      N = Nx + 5;
      aint.resize(4 * N);
      up.resize(4 * N);
    }
 
 
    // Function to update the segment tree
    void update(int nod, int ist, int idr, int st, int dr, ups val) {
      relax(nod, st, dr);
      if (ist <= st && idr >= dr) {
        up[nod] = val;
        relax(nod, st, dr);
      } else {
        int mij = (st + dr) / 2;
        if (ist <= mij) update(2 * nod, ist, idr, st, mij, val);
        if (idr > mij) update(2 * nod + 1, ist, idr, mij + 1, dr, val);
        make(nod, st, dr);
      }
    }
 
    void update1(int st, int dr, int toup) {
      if (st > dr) return;
      ups val;
      val.e = 2;
      val.t = toup;
      update(1, st, dr, 0, N-1, val);
    }

    void update2(int st, int dr) {
      if (st > dr) return;
      ups val;
      val.e = 3;
      update(1, st, dr, 0, N-1, val);
    }
    void update3(int st, int dr) {
      if (st > dr) return;
      ups val;
      val.e = 1;
      val.t = 2;
      update(1, st, dr, 0, N-1, val);
    }
 
    // Function to query the sum in a range
    mint query(int nod, int ist, int idr, int st, int dr) {
      relax(nod, st, dr);
      if (ist <= st && idr >= dr) {
        return aint[nod];
      } else {
        int mij = (st + dr) / 2;
        mint ret = 0;
        if (ist <= mij) ret += query(2 * nod, ist, idr, st, mij);
        if (idr > mij) ret += query(2 * nod + 1, ist, idr, mij + 1, dr);
        make(nod, st, dr);
        return ret; 
      }
    }
 
    mint query(int st, int dr) {
      return query(1, st, dr, 0, N-1);
    }
};


int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  SegmentTree st(MX + 10100);
  ll toRem = 0;
  int L = 0;
  FOR(i, N) {
    //cout << i << endl;
    int t,x, y;
    cin >> t;
    if (t == 1) {
      cin >> x;
      st.update1((x+L)%MX, (x + L)%MX, 1);
    }
    if (t == 2) {
      cin >> x;
      toRem += x;
      int OP = L;
      L += x;
      if (L < MX) {
        st.update2(OP, L);
      } else {
        st.update2(OP, MX);
        L %= MX;
        st.update2(0, L);
      }
    }
    if (t == 3) {
      if (toRem > MX) {
        continue;
      }
      else if (toRem == 0) {
        st.update3(0, MX);
      } else {
        vector<mint> vx;
        auto gall = st.getAll();
        for(int i=0;i<MX;++i) {
          vx.pb(gall[(i + L) % MX]);
        }
        for (int i=1;i<MX;++i) {
          if (i + toRem < MX) {
            vx[i] += vx[i + toRem];
          }
        }
        st.update2(0, MX);
        FOR(i, MX) {
          st.update1(i, i, vx[i].x);
        }
        L = 0;
        toRem *= 2;
      }
    }
  }
  cout << st.query(0, MX).x << endl;
}