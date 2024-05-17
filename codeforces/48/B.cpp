/*
  In the name of Allah, The Most Gracious and The Most Merciful.

  Glory be to You! We have no knowledge except what You have taught us.
  It is you who are the Knowledgeable, the Wise.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 51;
int arr[N][N];
int n, m;

int cal(int x, int y) {
  int k = 1e9;
  for (int i = x; i <= n; ++i) {
    for (int j = y; j <= m; ++j) {
      int p = arr[i][j] - arr[i - x][j] - arr[i][j - y] + arr[i - x][j - y];
      k = min(k, p);
    }
  }
  return k;
}

int main() {
  ios_base :: sync_with_stdio(0); cin.tie(0);

  cin >> n >> m;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> arr[i][j];
    }
  }

  //
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + (arr[i][j] == 1);
    }
  }

  int a, b;
  cin >> a >> b;

  int ans = min(cal(a, b), cal(b, a));
  cout << ans << '\n';

  return 0;
}
    				   	  					  			  			 	