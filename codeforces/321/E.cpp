#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using ll = long long;

const int MX = 4005;
int u[MX][MX];
int dp[805][MX];

int get_cost(int l, int r) {
  if (l > r) return 0;
  int ret = u[r][r] - u[l-1][r] - u[r][l-1] + u[l-1][l-1]; 
  return ret/2;
}

void go(int ind, int l, int r, int opt_l, int opt_r) {
  if (l > r) return;
  int i, opt, curr, mid;
  mid = (l+r)/2;
  dp[ind][mid] = INT_MAX;
  opt = l;
  for (i = opt_l; i <= min(mid, opt_r); ++i) {
    curr = dp[ind-1][i-1] + get_cost(i, mid);
    if (curr < dp[ind][mid]) {
      dp[ind][mid] = curr;
      opt = i;
    }
  }
  go(ind, l, mid-1, opt_l, opt);
  go(ind, mid+1, r, opt, opt_r);
}

int main() {
  FAST;
  
  int n, k, i, j;
  cin >> n >> k;

  for (i = 1; i <= n; ++i) {
    for (j = 1; j <= n; ++j) {
      cin >> u[i][j];
      u[i][j] += u[i-1][j] + u[i][j-1] - u[i-1][j-1];
    }
  }

  for (i = 1; i <= n; ++i) dp[1][i] = get_cost(1, i);

  for (i = 2; i <= k; ++i) {
    go(i, i, n, i, n);
  }
  
  cout << dp[k][n] << "\n";

  return 0;
}

	 		 										 			   				