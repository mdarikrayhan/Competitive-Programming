#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fi first
#define se second
#define pii pair<int, int>
#define pll pair<long long, long long>
using namespace std;

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n, a, b, k;
string s1, s2;
cin >> n;
map<pair<string, int>, vector<pair<string, int>>> mp;
vector<pair<string, int>> v1, v2, sol;
set<string> taken;

for (int i = 0; i < n; i++) {
cin >> s1 >> a >> k;
if (i == 0) {
v1.push_back({s1, a});
taken.insert(s1);
}

for (int j = 0; j < k; j++) {
cin >> s2 >> b;
mp[{s1, a}].push_back({s2, b});
}
}

while(!v1.empty()) {
for (auto e : v1) {
for (auto e2 : mp[e]) v2.push_back(e2);
}

v1.clear();
sort(v2.rbegin(), v2.rend());
for (auto e : v2) {
if (taken.count(e.fi)) continue;
v1.push_back(e);
sol.push_back(e);
taken.insert(e.fi);
}

v2.clear();
}

sort(sol.begin(), sol.end());
cout << sol.size() << "\n";
for (auto e : sol) cout << e.fi << " " << e.se << "\n";
return 0;
}
