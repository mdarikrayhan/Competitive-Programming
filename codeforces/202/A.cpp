#include <bits/stdc++.h>
using namespace std;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    fast();
    string s; cin >> s;

    vector<char> c(s.begin(), s.end());
    sort(c.begin(), c.end()); reverse(c.begin(), c.end());

    string ans;

    for (int i = 0; i < s.length(); ++i) {
        if (c[i] == c[0]) ans += c[i];
    }

    cout << ans;
}
