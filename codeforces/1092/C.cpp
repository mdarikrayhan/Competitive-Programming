#include <bits/stdc++.h>

#define int long long
#define all(v) v.begin(),v.end()
#define input(v)  for(auto&it:v) cin >> it;

using namespace std;

/*
Many Mistakes Breed Mastery!
*/
void Fast() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

map<string, vector<int>> idx;
vector<string> v, trace, ans;
int n;
bool ok = 0;

void step(string a, string b) {
    a += b.back();
  
    vector<string> c;
    string s, ss;
    for (int i = 0; i < n - 1; i++) {
        s += a[i];
        c.push_back(s);
    }
    for (int i = n - 1; i >= 1; i--) {
        ss += a[i];
        string k = ss;
        reverse(all(k));
        c.push_back(k);
    }
    sort(all(c));

    if (c == v) {
        ok = 1;
        string c1;
        for (int i = 0; i < n-1; i++) {
            c1 += a[i];
            ans[idx[c1].back()] = "P";
            idx[c1].pop_back();
        }
        c1 = "";
        for (int i =n-1; i >= 1; i--) {
            c1 += a[i];
            string k = c1;
            reverse(all(k));
            ans[idx[k].back()] = "S";
            idx[k].pop_back();
        }
        for (auto it: ans)cout << it;
    }

}

void solve() {
    cin >> n;
    ans = v = vector<string>(n * 2 - 2);
    for (int i = 0; i < n * 2 - 2; i++) {
        cin >> v[i];
        idx[v[i]].push_back(i);
        if (v[i].size() == n - 1)trace.push_back(v[i]);
    }
    sort(all(v));
    step(trace[0], trace[1]);
    if (!ok)step(trace[1], trace[0]);
}

int32_t main() {

    int t = 1;
    // cin >> t;
    while (t--)
        solve();


    return 0;
}