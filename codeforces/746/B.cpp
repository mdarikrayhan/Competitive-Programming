#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int n; cin >> n;
    string s; cin >> s;
    std::vector<char> v(n);
    int i = n / 2, j = n / 2, x = 0;
    if (n % 2) {
        v[i] = s[x];
        x++;
        while (i && j) {
            i--, j++;
            v[i] = s[x];
            v[j] = s[x + 1];
            x += 2;
        }
    } else {
        i--;
        v[i] = s[x];
        v[j] = s[x + 1];
        x += 2;
        while (i && j) {
            i--, j++;
            v[i] = s[x];
            v[j] = s[x + 1];
            x += 2;
            if (x > n - 1) break;
        }
    }
    for (auto &i:v) cout << i;
    return 0;
}