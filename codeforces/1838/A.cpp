#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstring>
#include <bitset>
#include <numeric>
#include <algorithm>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define cY cout << "YES\n"
#define cN cout << "NO\n"
#define c0 cout << "0\n"
#define c1 cout << "-1\n"
#define cA cout << ans << '\n'
#define pb push_back
#define mem(a, b) memset((a), (b), sizeof((a)))
#define sort(a) sort((a).begin(), (a).end());
const int N = 2e5 + 10;
const ll mod = 998244353;
const ll MOD = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;

void crossparallel() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    int mn = inf, mx = -inf;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }

    if (mn < 0)
        cout << mn << '\n';

    else
        cout << mx << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        crossparallel();
    }
    return 0;
}