#include <bits/stdc++.h>

#define int long long

using namespace std;

int n;
string s;

map<char, int> ch { {'G', 0}, {'H', 1}, {'R', 2}, {'S', 3} };
map<int, string> rch { {0, "Gryffindor"}, {1, "Hufflepuff"}, {2, "Ravenclaw"}, {3, "Slytherin"} };

set<string> ans;

map<pair<int, vector<int>>, bool> memoization;

void f(int pos, vector<int>& S) {
    if (memoization[{pos, S}]) return;
    // в состоянии S храним {G / H / R / S}
    if (pos == n) {
        int min_el = *min_element(S.begin(), S.end());
        for (int i = 0; i < 4; i++)
            if (S[i] == min_el)
                ans.insert(rch[i]);
        return;
    }
    if (s[pos] == '?') {
        int min_el = *min_element(S.begin(), S.end());
        for (int i = 0; i < 4; i++) {
            if (S[i] == min_el) {
                S[i]++;
                f(pos + 1, S);
                S[i]--;
            }
        }
    } else {
        S[ch[s[pos]]]++;
        f(pos + 1, S);
        S[ch[s[pos]]]--;
    }
    memoization[{pos, S}] = true;
}

void solve() {
    cin >> n >> s;
    vector<int> S {0, 0, 0, 0};
    f(0, S);
    for (auto x : ans) cout << x << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t; while (t--)
    solve();
}