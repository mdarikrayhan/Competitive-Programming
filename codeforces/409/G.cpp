// Author: Klay Thompson
// Problem: G. On a plane
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define rep(i, j, k) for (int i = (j); i <= (k); ++i)
#define per(i, j, k) for (int i = (j); i >= (k); --i)
#define SZ(v) int((v).size())
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
using ll = long long;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

template<class T>inline void chkmn(T &x, T y) { if (y < x) x = y; }
template<class T>inline void chkmx(T &x, T y) { if (y > x) x = y; }

using namespace std;

const int maxn = 1010;

int n;
double a[maxn], b[maxn], s;

int main() {
  cin.tie(nullptr) -> ios::sync_with_stdio(false);
  cin >> n;
  rep (i, 1, n) cin >> a[i] >> b[i], s += b[i];
  cout << fixed << setprecision(3) << 5 + s / n << '\n';
}