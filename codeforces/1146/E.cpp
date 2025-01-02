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
#define MOD 1000000007
#define LIM 120000
class SegmentTree {
public:
    vector<int> aint; // Segment tree array
    vector<int> up;   // Lazy propagation array
    vector<int> v;    // Input data array
    int N;         // Maximum size of the array
    void cha(int nn, int od) {
      if (up[nn] == 2 && up[od] == 2) {
        up[nn] = 0;
      }
      else if (up[nn] == 1 && up[od] == 2) {
        up[nn] = -1;
      }
      else if (up[nn] == -1 && up[od] == 2) {
        up[nn] = 1;
      }
      else up[nn] = up[od];
    }
    // Function to apply lazy propagation
    void relax(int nod, int st, int dr, int u) {
        if (!up[nod]) return;
        int l = dr - st + 1;
        if (up[nod] == 2) {
          aint[nod] = l - aint[nod];
        }
        if (up[nod] == 1) {
          aint[nod] = l;
        }
        if (up[nod] == -1) {
          aint[nod] = 0;
        }
        if (st != dr) {
          cha(2*nod, nod);
          cha(2 * nod + 1, nod);    
        }
        up[nod] = 0;
    }
 
    // Utility function to merge child node values
    void make(int nod, int st, int dr) {
        int mij = (st + dr) / 2;
        relax(nod, st, dr, 1);
        relax(2 * nod, st, mij, 1);
        relax(2 * nod + 1, mij + 1, dr, 1);
        aint[nod] = aint[2 * nod] + aint[2 * nod + 1];
    }

    SegmentTree(int Nx, int pos) {
      N = Nx + 5;
      aint.resize(4 * N);
      up.resize(4 * N);
      init(1, 0, N - 1, pos);
    }
 
 
    // Function to update the segment tree
    void update(int nod, int ist, int idr, int st, int dr, int val) {
      relax(nod, st, dr, 1);
      if (ist <= st && idr >= dr) {
        up[nod] = val;
        relax(nod, st, dr, 1);
      } else {
        int mij = (st + dr) / 2;
        if (ist <= mij) update(2 * nod, ist, idr, st, mij, val);
        if (idr > mij) update(2 * nod + 1, ist, idr, mij + 1, dr, val);
        make(nod, st, dr);
      }
    }
 
    void update(int st, int dr, int val) {
      if (st > dr) return;
      //cout << st - LIM << " " << dr - LIM << " " << val << endl;
      update(1, st, dr, 0, N-1, val);
    }
 
    // Function to query the sum in a range
    int query(int nod, int ist, int idr, int st, int dr) {
      relax(nod, st, dr, 1);
      if (ist <= st && idr >= dr) {
        return aint[nod];
      } else {
        int mij = (st + dr) / 2;
        int ret = 0;
        if (ist <= mij) ret = max(ret, query(2 * nod, ist, idr, st, mij));
        if (idr > mij) ret = max(ret, query(2 * nod + 1, ist, idr, mij + 1, dr));
        make(nod, st, dr);
        return ret; 
      }
    }
 
    int query(int st, int dr) {
      return query(1, st, dr, 0, N-1);
    }
 
    // Function to initialize the segment tree
    void init(int nod, int st, int dr, int pos) {
      if (st == dr) {
        if (pos && st >= LIM){
          aint[nod] = 1;
        } else if (!pos && st <= LIM) {
          aint[nod] = 1;
        } else {
          aint[nod] = 0;
        }
      } else {
        int mij = (st + dr) / 2;
        init(2 * nod, st, mij, pos);
        init(2 * nod + 1, mij + 1, dr, pos);
        make(nod, st, dr);
      }
    }
};

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int N,M;
  cin>>N >> M;
  vi v;
  FOR(i, N) {
    int x;
    cin >> x;
    v.pb(x);
  }

  SegmentTree sgpos(LIM * 2 + 10, 1);
  SegmentTree sgneg(LIM * 2 + 10, 0);
  FOR(i, M) {
    string s;
    int x;
    cin >> s >> x;
    if (s == ">") {
      int nx = x;
      if (x < 0) {
        x *= -1;
        --x;
      }
      sgpos.update(x+LIM+1, LIM*2, -1);
      sgneg.update(x+LIM+1, LIM*2, -1);

      sgpos.update(0, -x + LIM - 1, 1);
      sgneg.update(0, -x + LIM - 1, 1);
      
      if (nx < 0) {
        x = nx;
        sgpos.update(x + LIM + 1, -x+LIM -1, 2);
        sgneg.update(x + LIM + 1, -x+LIM -1, 2);
      }
    }
    if (s == "<") {
      int nx = x;
      if (x > 0) {
        x *= -1;
        ++x;
      }
      sgpos.update(0, x + LIM-1, -1);
      sgneg.update(0, x + LIM-1, -1);

      sgpos.update(-x + LIM+1, 2 * LIM, 1);
      sgneg.update(-x + LIM+1, 2 * LIM, 1);
      if (nx > 0) {
        x = nx;
        sgpos.update(-x + LIM + 1, x + LIM - 1, 2);
        sgneg.update(-x + LIM + 1, x + LIM - 1, 2);
      }
    }
  }
  map<int,int> hp,hn;
  for (int i=-100000;i<=100000;++i) {
    if (i >= 0) {
      if (sgpos.query(i+LIM,i+LIM)) {
        hp[i] = i;
      } else {
        hp[i] = -i;
      }
    }
    if (i <= 0) {
      if (sgneg.query(i+LIM, i + LIM)) {
        hn[-abs(i)] = i;
      } else {
        hn[-abs(i)] = -i;
      }
    }
  }
  FOR(i, sz(v)) {
    if (v[i] < 0) {
      cout << hn[v[i]] << " ";
    } else {
      cout << hp[v[i]] << " ";
    }
  }
  return 0;
}