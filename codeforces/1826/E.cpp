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
int N,M;

vector<int> v[5555];

class Bitset {
private:
    std::vector<__int128> bits;
    int size;
    int chunks;

    int getChunkIndex(int pos) const {
        return pos >> 7; // equivalent to pos / 128
    }

    int getBitIndex(int pos) const {
        return pos & 127; // equivalent to pos % 128
    }

public:
    Bitset() {}
    Bitset(int n) : size(n), chunks((n + 127) / 128) {
        bits.resize(chunks, 0);
    }

    // Set all bits to 1
    void set() {
        for (int i = 0; i < chunks; ++i) {
            bits[i] = ~(__int128)0;
        }
        int extraBits = 128 * chunks - size;
        if (extraBits > 0) {
            bits[chunks - 1] >>= extraBits;
        }
    }

    // Reset all bits to 0
    void reset() {
        for (int i = 0; i < chunks; ++i) {
            bits[i] = 0;
        }
    }

    // Set a specific bit
    void set(int pos) {
        if (pos >= 0 && pos < size) {
            bits[getChunkIndex(pos)] |= ((__int128)1 << getBitIndex(pos));
        }
    }

    // Reset a specific bit
    void reset(int pos) {
        if (pos >= 0 && pos < size) {
            bits[getChunkIndex(pos)] &= ~((__int128)1 << getBitIndex(pos));
        }
    }

    // Check if a specific bit is set
    bool test(int pos) const {
        if (pos >= 0 && pos < size) {
            return (bits[getChunkIndex(pos)] & ((__int128)1 << getBitIndex(pos))) != 0;
        }
        return false;
    }

    // Print the bitset
    void print() const {
        for (int i = size - 1; i >= 0; --i) {
            std::cout << test(i);
            if (i % 4 == 0) std::cout << ' '; // Optional: Add space for better readability
        }
        std::cout << std::endl;
    }
    // Perform a bitwise AND operation with another bitset
    void bitwiseAnd(const Bitset& other) {
        if (size != other.size) {
            std::cerr << "Bitsets must be of the same size to perform AND operation." << std::endl;
            return;
        }
        for (int i = 0; i < chunks; ++i) {
            bits[i] &= other.bits[i];
        }
    }
};


Bitset edg[5005];

void make(vi &vx) {
  vpi v;
  FOR(i, sz(vx)) {
    v.pb({vx[i], i});
  }
  sort(all(v));
  Bitset b(5050);
  int pos = 0;
  FOR(i, sz(v)) {
    while(pos < i && v[pos].fs < v[i].fs) {
      b.set(v[pos].sc);
      ++pos;
    }
    edg[v[i].sc].bitwiseAnd(b);
  }
}

ll best[5050];
ll cost[5555];
ll maked(vi &vx) {
  vpi v;
  FOR(i, sz(vx)) {
    v.pb({vx[i], i});
  }
  sort(all(v));
  FOR(ai, sz(v)) {
    int i = v[ai].sc;
    best[ai] = cost[i];
    FOR(aj, ai) {

      int j = v[aj].sc;
      if (edg[i].test(j)) {
        best[ai] = max(best[ai], best[aj] + cost[i]);
      }
    }
  }
  ll ret = 0;
  FOR(i, sz(v)) {
    ret = max(ret, best[i]);
  }
  return ret;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  FOR(i, M) {
    edg[i] = Bitset(5050);
    cin >> cost[i];
  }
  FOR(i, N) {
    FOR(j, M) {
      int x;
      cin >> x;
      v[i].pb(x);
    }
  }

  FOR(i, M) {
    edg[i].set();
  }
  FOR(i, N) {
    make(v[i]);
  }/*
  FOR(i, M) {
    FOR(j, M) {
      cout << edg[i][j];
    }
    cout << endl;
  }*/
  cout << maked(v[0]) << endl;

}