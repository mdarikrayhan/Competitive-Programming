//
// Created by Om Biradar on 4/29/2024.
//

#include<bits/stdc++.h>
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    if (a[a.size() - 1] < b[b.size() - 1]) {
        cout << '>' << '\n';
        return;
    } else if (a[a.size() - 1] > b[b.size() - 1]) {
        cout << "<\n";
        return;
    } else {
        if ( a == b ) {
            cout << "=\n";
            return;
        }
        int ans = 0;
        // default assumes a is L and XXXX
        // 0 means a is greater
        if (a.size() < b.size()) {
            ans = 1;
        }
        if (a[a.size() - 1] == 'S') {
            if (ans == 1) ans = 0;
            else ans = 1;
        }
        if (ans == 1) {
            cout << "<\n";
            return;
        } else {
            cout << ">\n";
            return;
        }
    }
}

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fast();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}