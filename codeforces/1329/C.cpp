/*
Problem: 1329C
Date: 24-05-2024 11:25 PM
*/


#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int H = (1 << 21) + 5;
int t, h, g, a[H];

vector<int> ve;

ll solve(int i) {
    ll ans = 0;
    while(true) {
        int j = i;
        while(a[2 * j] != 0 || a[2 * j + 1] != 0) {
            j = (a[2 * j] > a[2 * j + 1] ? 2 * j : 2 * j + 1);
        }
        if(j < (1 << g)) break;
        ve.push_back(i);
        ans += a[i];
        int i2 = i;
        while(i2 != j) {
            int k = (a[2 * i2] > a[2 * i2 + 1] ? 2 * i2 : 2 * i2 + 1);
            a[i2] = a[k];
            i2 = k;
        }
        a[j] = 0;
    }
    if(i < (1 << (g - 1))) {
        ans += solve(2 * i) + solve(2 * i + 1);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> h >> g;
        ll sum = 0;
        for(int i = 1; i < (1 << h); i++) {
            cin >> a[i];
            sum += a[i];
        }
        fill(a + (1 << h), a + (1 << (h + 1)), 0);
        ve.clear();
        cout << sum - solve(1) << '\n';
        for(int x : ve) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}