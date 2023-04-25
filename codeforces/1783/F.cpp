#include <bits/stdc++.h>
using namespace std;

const int N = 3005;

int n, ans;
int a[N], b[N];
bitset<N> vs;
int ida[N], idb[N];
vector<int> adj[N];
int match[N];

void build(int *a, int *ida) {
for (int i = 1; i <= n; i++) cin >> a[i];
vs.reset();
for (int i = 1, m = 0; i <= n; i++) {
m++;
int now = i;
while (!vs[now]) {
vs[now] = 1;
ida[now] = m;
now = a[now];
}
}
}

bool dfs(int x) {
for (int y : adj[x]) if (!vs[y]) {
vs[y] = 1;
if (!match[y] || dfs(match[y])) {
match[y] = x;
return 1;
}
}
return 0;
}

int main() {
ios::sync_with_stdio(false), cin.tie(0);
cin >> n;
build(a, ida);
build(b, idb);
for (int i = 1; i <= n; i++) adj[ida[i]].emplace_back(idb[i]);
ans = n;
for (int i = 1; i <= n; i++) {
vs.reset();
ans -= dfs(i);
}
cout << ans << '\n';
for (int i = 1; i <= n; i++) {
if (match[idb[i]] == ida[i]) match[idb[i]] = 0;
else cout << i << ' ';
}
}
