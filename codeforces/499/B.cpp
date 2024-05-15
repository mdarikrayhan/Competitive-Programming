// Link : https://codeforces.com/problemset/problem/499/B
#include <bits/stdc++.h>
#include <utility>
#define ll long long
using namespace std;
#define all(x) (x).begin(), (x).end()
ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }
const int N = 1e5 + 10;
#define nl "\n"

void solution() {
    // write your code here
    int n, m;
    cin >> n >> m;
    unordered_map<string, string> mp1;
    for (int i = 0; i < m; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        mp1[s1] = s2;
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (mp1[s].size() < s.size())
            cout << mp1[s] << " ";
        else
            cout << s << " ";
    }
    cout << nl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solution();
    }

    return 0;
}
