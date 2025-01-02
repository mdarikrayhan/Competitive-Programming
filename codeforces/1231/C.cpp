/*
Problem: 1231C
Date: 25-05-2024 03:37 PM
*/


#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 505;
int n, m;
int a[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = n - 2; i > 0; i--) {
        for(int j = m - 2; j > 0; j--) {
            if(a[i][j] == 0) {
                a[i][j] = min(a[i + 1][j], a[i][j + 1]) - 1;
            }
        }
    }
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if((j < m - 1 && a[i][j + 1] <= a[i][j]) || (i < n - 1 && a[i + 1][j] <= a[i][j])) {
                cout << -1 << endl;
                return 0;
            }
            sum += a[i][j];
        }
    }
    cout << sum << endl;
}