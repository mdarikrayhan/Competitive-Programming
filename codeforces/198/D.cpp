#include<bits/stdc++.h>
using namespace std;
#define L long long
struct S {
  int fx=0,fy=1,fz=0;
  int lx=0,ly=0,lz=1;
  int ux=1,uy=0,uz=0;
};

void print(vector<vector<vector<int>>>&v) {
  for (vector<vector<int>>&a : v) {
    for (vector<int>&b : a) {
      for (int c : b) {
        cout << c << " ";
      }
      cout << '\n';
    }
    cout << '\n';
  }
}

void solve(vector<vector<vector<int>>>&v, S s, int&c, int n, int&x, int&y, int&z, bool first) {
  // cout << "START CALL TO " << n << " at " << x << " " << y << " " << z << "\n";
  // print(v);
  #define MOVE_F(a) x += (a)*s.fx; y += (a)*s.fy; z += (a)*s.fz;
  #define MOVE_L(a) x += (a)*s.lx; y += (a)*s.ly; z += (a)*s.lz;
  #define MOVE_U(a) x += (a)*s.ux; y += (a)*s.uy; z += (a)*s.uz;
  if (n == 1) {
    // cout << x << " " << y << " " << z << " " << n << endl;
    v[x][y][z] = c++;
    if (!first) {
      MOVE_U(1);
      // cout << x << " " << y << " " << z << " " << n << endl;
      v[x][y][z] = c++;
    }
    return;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // cout << x << " " << y << " " << z << " " << n << endl;
      v[x][y][z] = c++;
      if (j != n-1) {
        if (i&1) {
          MOVE_F(-1);
        } else {
          MOVE_F(1);
        }
      }
    }
    if (i != n-1) {
      MOVE_L(1);
    }
  }
  MOVE_U(1);
  if (n&1) {
    S ns;
    ns.fx = -s.lx; ns.fy = -s.ly; ns.fz = -s.lz;
    ns.lx = s.ux; ns.ly = s.uy; ns.lz = s.uz;
    ns.ux = -s.fx; ns.uy = -s.fy; ns.uz = -s.fz;
    solve(v,ns,c,n-1,x,y,z,false);
  } else {
    S ns;
    ns.fx = -s.lx; ns.fy = -s.ly; ns.fz = -s.lz;
    ns.lx = s.ux; ns.ly = s.uy; ns.lz = s.uz;
    ns.ux = s.fx; ns.uy = s.fy; ns.uz = s.fz;
    solve(v,ns,c,n-1,x,y,z,false);
  }
  // cout << "END CALL TO " << n-1 << " at " << x << " " << y << " " << z << "\n";
  // print(v);
  MOVE_L(-1);
  for (int i = 0; i < n-(n&1); i++) {
    for (int j = 0; j < n-1+(n&1); j++) {
      // cout << x << " " << y << " " << z << " " << n << endl;
      v[x][y][z] = c++;
      if (j != n-2+(n&1)) {
        if (n&1) {
          if (i&1) {
            MOVE_F(-1);
          } else {
            MOVE_F(1);
          }
        } else {
          if (i&1) {
            MOVE_U(1);
          } else {
            MOVE_U(-1);
          }
        }
      }
    }
    if (i != n-1-(n&1)) {
      if (n&1) {
        MOVE_U(1);
      } else {
        MOVE_F(-1);
      }
    }
  }
  if (!first) {
    MOVE_U(1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        // cout << x << " " << y << " " << z << " " << n << endl;
        v[x][y][z] = c++;
        if (j != n-1) {
          if (i&1) {
            MOVE_L(-1);
          } else {
            MOVE_L(1);
          }
        }
      }
      if (i != n-1) {
        MOVE_F(1);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<vector<vector<int>>> v(n, vector<vector<int>>(n, vector<int>(n,0)));
  int c = 1, x = 0, y = 0, z = 0;
  solve(v,S(),c,n,x,y,z,true);
  print(v);
}