// LUOGU_RID: 160398468
#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pp = pair<int, int>;
#define pb push_back
const int mx = 3e5 + 2;
int bo[mx];
int bor(string a, string b) {
  string combined = b + '&' + a;
  int j = 0;
  for (int i = 1; i < combined.size(); ++i) {
    while (j > 0 && combined[i] != combined[j]) j = bo[j - 1];
    if (combined[i] == combined[j]) ++j;
    bo[i] = j;
  }
  for (int i = b.size() + 1; i < combined.size(); ++i)
    if (bo[i] == b.size()) return b.size();
  return bo[combined.size() - 1];
}
int gt(string a, string b, string c) {
  // cout << a << '&' << b << '&' << c << '\n';
  string x = a;
  x += b.substr(bor(x, b));
  x += c.substr(bor(x, c));
  // cout << x << '\n';
  return x.size();
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);
  string a, b, c;
  cin >> a >> b >> c;
  cout << min({gt(a, b, c), gt(a, c, b), gt(b, a, c), gt(b, c, a), gt(c, a, b),
               gt(c, b, a)})
       << '\n';
}