#include <iostream>
typedef long long ll;
using namespace std;
int main()
{
  ll n, m;
  cin >> n;
  ll a[n + 1];
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  cin >> m;
  ll b[m + 1];
  for (int j = 1; j <= m; ++j) {
    cin >> b[j];
  }
  ll d[n + 1][m + 1];
  int prev[n + 1][m + 1];
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      prev[i][j] = 0;
      d[i][j] = 0;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i] == b[j]) {
      d[i][j] = 1;
      for (int k = 1; k < i; ++k) {
        if (a[k] < a[i] && d[i][j] < d[k][j] + 1) {
          d[i][j] = d[k][j] + 1;
          prev[i][j] = k;
        }
      }
  } else {
          d[i][j] = d[i][j - 1];
          prev[i][j] = prev[i][j - 1];
  }
 }
 }
 int answer[n + 1];
 int pos = 0;
 for (int i = 1; i <= n; ++i) {
  if (d[pos][m] < d[i][m]) {
    pos = i;
  }
 }
 int cnt = 0;
 int j = m;
 while (pos != 0) {
  while (d[pos][j] == d[pos][j - 1])
    j--;
  answer[cnt++] = pos;
  pos = prev[pos][j];
 }
 cout << cnt << endl;
 for (ll i = cnt - 1; i >= 0; --i) {
  cout << a[answer[i]] << " ";
  }
}