#include <bits/stdc++.h>
#define int long long
#define rep(i, j, n) for (int i = j; i <= n; i++)
#define pii pair<int, int>
using namespace std;
int n, m;
char c[1000][1000];
int gx[10] = {0, 0, 1, 0, -1};
int gy[10] = {0, 1, 0, -1, 0};
void solve() {
  cin >> n >> m;
  rep(i, 1, n) {
    rep(i2, 1, m) { cin >> c[i][i2]; }
  }
  int aws = 0;
  rep(i, 2, n-1) {
    rep(i2, 2, m-1) {
      if (c[i][i2] == '*') {
        int ct = 0;
        rep(i3, 0, 4) { ct += (c[i + gy[i3]][i2 + gx[i3]] == '*'); }
        if (ct == 5) {
          aws++;
          c[i][i2] = '.';
          for (int i3 = i-1; i3 >= 1; i3--) {
          	if(c[i3][i2]=='.'){
            	break;
            }
            c[i3][i2] = '.';
            
          }
          for (int i3 = i+1; i3 <= n; i3++) {
          	if(c[i3][i2]=='.'){
            	break;
            }
            c[i3][i2] = '.';
          }
          for (int i3 = i2-1; i3 >= 1; i3--) {
          	if(c[i][i3]=='.'){
            	break;
            }
            c[i][i3] = '.';
          }
          for (int i3 = i2+1; i3 <= m; i3++) {
          	if(c[i][i3]=='.'){
            	break;
            }
            c[i][i3] = '.';
          }
        }
      }
    }
  }
  rep(i, 1, n) {
    rep(i2, 1, m) {
      if (c[i][i2] == '*') {
        cout << "NO";
        return;
      }
    }
  }
  cout << (aws == 1 ? "YES" : "NO");
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

  solve();

  return 0;
}

		  	 			       			 		 					