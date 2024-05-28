#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll const LIMIT = 1e18+1;

int const NMAX = 200;
int mat[1 + NMAX][1 + NMAX];
int perm[1 + NMAX];
int ind[1 + NMAX];

char ans[1 + NMAX];
ll dp[1 + NMAX][1 + NMAX];

bool compareInd(int a, int b) {
  return (perm[a] < perm[b]);
}

void buildDp(int len) {
  dp[0][0] = 1;
  for(int i = 1;i <= len;i++) {
    for(int j = 0;j <= i;j++) {
      if(ans[i] == '*') {
        if(j == 0) {
          dp[i][j] = dp[i-1][j+1];
        }else {
          dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
        }
      }else if(ans[i] == '(') {
        if(j != 0){
          dp[i][j] = dp[i-1][j-1];
        }else {
          dp[i][j] = 0;
        }
      }else {
        dp[i][j] = dp[i-1][j+1];
      }
      if(dp[i][j] > LIMIT) {
        dp[i][j] = LIMIT;
      }
    }
  }
}

int main() {

  int n, m, len;
  ll k;
  cin >> n >> m >> k;
  len = n + m - 1;
  for(int i = 1;i <= len;i++) {
    perm[i] = NMAX * NMAX;
    ind[i] = i;
    ans[i] = '*';
  }
  for(int i = 1;i <= n;i++) {
    for(int j = 1;j <= m;j++) {
      cin >> mat[i][j];
      perm[i + j - 1] = min(perm[i + j - 1], mat[i][j]);
    }
  }
  sort(ind+1, ind+len+1, compareInd);
  for(int i = 1;i <= len;i++) {
    int pos = ind[i];
    ans[pos] = '(';
    buildDp(len);
    if(dp[len][0] < k) {
      k -= dp[len][0];
      ans[pos] = ')';
    }
  }
  for(int i = 1;i <= n;i++) {
    for(int j = 1;j <= m;j++) {
      cout << ans[i + j - 1];
    }
    cout << '\n';
  }
  return 0;
}
