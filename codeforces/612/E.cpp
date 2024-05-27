// LUOGU_RID: 160397189
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int maxn = 1000000 + 10;
int a[maxn], v[maxn], b[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    vector<vector<int> > s;
    for (int i=1;i<=n;++i)
        if (!v[i])
        {
            vector<int> t;
            for (int j=i;!v[j];j=a[j]) t.emplace_back(j), v[j] = 1;
            if (t.size() & 1)
            {
                for (int j=i,x=a[t[t.size()/2]];!b[j];j=a[j],x=a[x]) b[j] = x;
            }
            else s.emplace_back(t);
        }
    sort(s.begin(), s.end(), [](auto x, auto y) {return x.size() < y.size(); });
    if (s.size() & 1) return cout << "-1\n", 0;
    for (int i=0;i<s.size();i+=2)
    {
        auto x = s[i], y = s[i + 1];
        if (x.size() != y.size()) return cout << "-1\n", 0;
        for (int i=0;i<x.size();++i) b[x[i]] = y[i];
        for (int i=0;i<x.size();++i) b[y[i]] = x[(i + 1) % x.size()];
    }
    for (int i=1;i<=n;++i) cout << b[i] << ' ';
    return 0;
}