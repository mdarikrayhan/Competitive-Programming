#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

template<typename T> void chmin(T& x, T y) { x = min(x, y); }

struct cell;
cell* emp[25];

int sign(int k) { return k ? -1 : 1; }

struct cell {
  cell* children[4];
  long long dp[4][4][2], cyc[2];
  // dp[i][j] = edges to get from corner i to corner j of this cell while
  // passing through all active vertices (0 = min, 1 = negative max)
  //
  // cyc = same for cycle
  int lvl, active, corner;
  cell (int _lvl): lvl(_lvl) {
    corner = -1;
    cyc[0] = cyc[1] = 0;
    for (int i = 0; i < 4; i++) {
      children[i] = nullptr;
      for (int j = 0; j < 4; j++) {
        for (int k: {0, 1}) {
          dp[i][j][k] = 0;
        }
      }
    }

    if (lvl) {
      for (int i = 0; i < 4; i++) {
        if (emp[lvl-1] == nullptr) emp[lvl-1] = new cell(lvl-1);
        children[i] = emp[lvl-1];
      }
      merge();
    }
  }

  void modify(string& s) {
    if (lvl == 0) {
      active ^= 1;
      corner = (active ? 0 : -1);
      return;
    }
    int i = s.back()-'a';
    s.pop_back();
    if (children[i] == emp[lvl-1]) children[i] = new cell(lvl-1);
    children[i]->modify(s);
    merge();
  }

  void merge() {
    corner = -1;
    active = 0;
    for (int i = 0; i < 4; i++) {
      active += children[i]->active;
      if (children[i]->corner != -1) {
        if (lvl == 1 || children[i]->corner == i) corner = i;
      }
    }

    for (int k: {0, 1}) {
      for (int i = 0; i < 4; i++) {
        // i to i+1
        int j = (i+1)&3;
        dp[i][j][k] = INF;
        // go directly from i to j
        bool direct = 1;
        for (int l: {(i+2)&3, (i+3)&3}) {
          if (children[l]->active) direct = 0;
        }
        if (direct) {
          chmin(dp[i][j][k], children[i]->dp[i][j][k] + children[j]->dp[i][j][k] + sign(k));
        }
        // go around
        chmin(dp[i][j][k], children[i]->dp[i][(i+3)&3][k] + children[(i+3)&3]->dp[i][(i+2)&3][k]
            + children[(i+2)&3]->dp[(i+3)&3][(i+1)&3][k] + children[j]->dp[(i+2)&3][j][k]
            + 3*sign(k));

        dp[j][i][k] = dp[i][j][k];

        // i to i+2
        if (i > 1) continue;
        j = (i+2)&3;
        dp[i][j][k] = INF;
        for (int z: {1, -1}) {
          // i -> i+z -> j
          if (children[(i-z)&3]-> active) continue;
          chmin(dp[i][j][k], children[i]->dp[i][(i+z)&3][k] +
              children[(i+z)&3]->dp[i][j][k] + children[j]->dp[(i+z)&3][j][k] + 2*sign(k));
        }
        dp[j][i][k] = dp[i][j][k];
      }
    }

    for (int k: {0, 1}) {
      cyc[k] = INF;
      for (int i = 0; i < 4; i++) {
        if (children[i]->active == active) {
          chmin(cyc[k], children[i]->cyc[k]);
        }
      }
      long long val = 4*sign(k);
      for (int i = 0; i < 4; i++) {
        val += children[i]->dp[(i+1)&3][(i+3)&3][k];
      }
      chmin(cyc[k], val);
    }

    // corner case
    if (active == 2) {
      for (int i = 0; i < 4; i++) {
        int j = (i+1)&3;
        if (children[i]->corner == j && children[j]->corner == i) cyc[0] = 2;
        else if (lvl == 1 &&
            children[i]->corner != -1 && children[j]->corner != -1) cyc[0] = 2;
      }
    }
  }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  cell* root = new cell(n);
  while (q--) {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    root->modify(s);
    if (root->cyc[0] == INF) cout << "-1\n";
    else {
      cout << max(2LL, root->cyc[0]) << ' ' << max(2LL, -root->cyc[1]) << '\n';
    }
  }
}
