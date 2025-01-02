#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define INF 1e18
#define ll long long
#define ul unsigned long
#define ld long double
#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

void IN_OUT() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

string solve(string s) {
    int n = s.size();

    ll cnt = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '1')
            cnt++;

    string ans;
    int i = 0;
    while (i < n && s[i] != '2') {
        if (s[i] == '0')
            ans += s[i];
        i++;
    }

    while (cnt > 0) {
        ans += '1';
        cnt--;
    }

    while (i < n) {
        if (s[i] != '1')
            ans += s[i];
        i++;
    }

    return ans;
}

int main() {
    fastio();
    IN_OUT();

    string s;
    cin >> s;

    cout << solve(s);

    return 0;
}