/*
Problem: 702E
Date: 27-05-2024 03:26 AM
*/


#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5, LG = 35;
int n, f[N][LG];
ll k, s[N][LG], m[N][LG], S[N], M[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> f[i][0];
    }
    for(int i = 0; i < n; i++) {
        cin >> s[i][0];
        m[i][0] = s[i][0];
        M[i] = LLONG_MAX;
    }
    for(int j = 1; j < LG; j++) {
        for(int i = 0; i < n; i++) {
            f[i][j] = f[f[i][j - 1]][j - 1];
            s[i][j] = s[i][j - 1] + s[f[i][j - 1]][j - 1];
            m[i][j] = min(m[i][j - 1], m[f[i][j - 1]][j - 1]);
        }
    }
    for(int i = 0; i < n; i++) {
        int x = i;
        for(int j = 0; j < LG; j++) {
            if((k >> j) & 1) {
                S[i] += s[x][j];
                M[i] = min(M[i], m[x][j]);
                x = f[x][j];
            }
        }
        cout << S[i] << " " << M[i] << endl;
    }
}