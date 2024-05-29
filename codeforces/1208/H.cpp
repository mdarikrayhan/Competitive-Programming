#include <bits/stdc++.h>
using namespace std;
const int N = 400005;
using pii = pair<int,int>;
using ll = long long;
int n,kk,q,sz[N],fa[N],ans[N],clr[N];vector<int> v[N];
void dfs(int pos,int f)
{
sz[pos] = 1;fa[pos] = f;
for (auto &i : v[pos]) if (i != f) dfs(i,pos),sz[pos] += sz[i];
}
int op[N][3];
int sum[N];bool lim[N];
vector<pii> qq[N];
void calc()
{
priority_queue<pii> pq;
for (int i = 1;i <= n;i++) if (clr[i] == -1) clr[i] = 1;
for (int i = 1;i <= n;i++)
for (auto &j : v[i]) if (j != fa[i]) sum[i] += 2 * clr[j] - 1;
for (int i = 1;i <= n;i++)
if (v[i].size() - !!fa[i]) pq.push({-sum[i] - 1,i});
for (int i = -n;i <= n;i++)
{
while (!pq.empty() && -pq.top().first <= i)
{
int nd = pq.top().second;pq.pop();
clr[nd] = 0;lim[nd] = 1;
if (fa[nd] && !lim[fa[nd]])
pq.push({-(sum[fa[nd]] -= 2) - 1,fa[nd]});
}
for (auto &j : qq[n + i])
ans[j.second] = 2 * clr[j.first] - 1;
}
}
int calc(int pos)
{
if (clr[pos] != -1) return clr[pos];
int sum = 0;
for (int i = 0;i < int(v[pos].size()) && !(sum + int(v[pos].size()) - i < kk ||
sum - int(v[pos].size()) + i >= kk);i++)
if (v[pos][i] != fa[pos]) sum += 2 * calc(v[pos][i]) - 1;
return sum >= kk;
}
void solve()
{
for (int i = 1;i <= n;i++)
sort(v[i].begin(),v[i].end(),[](int a,int b) {return sz[a] < sz[b];});
for (int i = 1;i <= q;i++)
{
int tp = op[i][0],x = op[i][1];
if (tp == 1) cout << calc(x) << endl;
else if (tp == 2) clr[x] = op[i][2];
else kk = x;
}
}
int main ()
{
ios::sync_with_stdio(false);
cin >> n >> kk;int t1,t2;
for (int i = 1;i < n;i++)
{
cin >> t1 >> t2;v[t1].push_back(t2);v[t2].push_back(t1);
}
for (int i = 1;i <= n;i++) cin >> clr[i];
dfs(1,0);bool fl = 1;cin >> q;
for (int i = 1;i <= q;i++)
{
cin >> op[i][0] >> op[i][1];
if (op[i][0] == 2) {cin >> op[i][2];fl = 0;}
}
if (fl)
{
for (int i = 1;i <= q;i++)
{
int tp = op[i][0],x = op[i][1];
if (tp == 3) kk = x;else qq[kk + n].push_back({x,i});
}
calc();
for (int i = 1;i <= q;i++)
if (ans[i]) cout << (ans[i] + 1) / 2 << endl;
return 0;
}
solve();
return 0;
}