#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int n, mn = -1;
    cin >> n;
    string a = to_string(n);
    for (int i = 1; i < 100000; ++i) {
        string b = to_string(i * i);
        int j = 0, cnt = 0;
        while (j < b.size() && cnt < a.size()) {
            if (b[j] == a[cnt]) j++;
            cnt++;
        }
        if (j == b.size()) mn = a.size() - j;
    }
    cout << mn;
    return 0;
}