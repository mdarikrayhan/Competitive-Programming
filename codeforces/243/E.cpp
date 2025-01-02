#include <bits/stdc++.h>
using namespace std;

const int maxn = 510;
int n, r[maxn], c[maxn], p[maxn], cnt[maxn];
bool vis[maxn];
string s[maxn];

int main() {
ios::sync_with_stdio(0), cin.tie(0);
cin >> n;
for (int i = 0; i < n; i++) {
cin >> s[i];
for (int j = 0; j < n; j++) {
if (s[i][j] == '1') r[i]++, c[j]++;
}
}
vector<int> id(n);
iota(id.begin(), id.end(), 0);
sort(id.begin(), id.end(), [&](int x, int y) { return c[x] < c[y]; });
function<void(int)> dfs = [&](int cur) {
if (cur == n) {
cout << "YES\n";
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) cout << s[i][p[j]];
cout << '\n';
}
exit(0);
}
for (int i : id) if (!vis[i]) {
bool flag = 1;
for (int j = 0; j < n && flag; j++) {
if (s[j][i] == '0' && cnt[j]) flag &= cnt[j] == r[j];
}
if (!flag) continue;
p[cur] = i, vis[i] = 1;
for (int j = 0; j < n; j++) {
if (s[j][i] == '1') cnt[j]++;
}
dfs(cur + 1), vis[i] = 0;
for (int j = 0; j < n; j++) {
if (s[j][i] == '1') cnt[j]--;
}
}
};
dfs(0), cout << "NO\n";
return 0;
}
