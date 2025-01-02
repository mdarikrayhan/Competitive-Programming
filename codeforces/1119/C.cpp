/*
Problem: 1119C
Date: 24-05-2024 01:16 AM
*/


#include <bits/stdc++.h>

#define ll long long
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// each row and column does not change parity

const int N = 505;
int n, m;
bool b[N][N];
bool r[N], c[N];
bool x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, n) rep(j, 0, m) {
        cin >> b[i][j];
    }
    rep(i, 0, n) rep(j, 0, m) {
        cin >> x;
        b[i][j] ^= x;
    }
    rep(i, 0, n) rep(j, 0, m) {
        r[i] ^= b[i][j];
        c[j] ^= b[i][j];
    }
    rep(i, 0, n) {
        if(r[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    rep(j, 0, m) {
        if(c[j]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}