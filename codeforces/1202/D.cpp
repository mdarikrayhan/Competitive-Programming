/*
Problem: 1202D
Date: 23-05-2024 05:46 AM
*/


#include <bits/stdc++.h>

#define ll long long
using namespace std;

// 1 3 3 7 7 7 7 ... 7 3 3 3 3 3 ... 3 7?
// let x = # 7's, y = # 3's.
// n = x + (y + 2)(y + 3) / 2.

int q;
ll n;

int main() {
    ios::sync_with_stdio(false);
    cin >> q;
    while(q--) {
        cin >> n;
        if(n < 10) {
            cout << "133";
            for(int i = 0; i < n; i++) {
                cout << "7";
            }
            cout << endl;
            continue;
        }
        ll y = floor(sqrt(2 * n)) - 2;
        ll x = n - (y + 2) * (y + 1) / 2;
        ll z = floor(sqrt(2 * x)) - 2;
        x = n - (y + 2) * (y + 1) / 2 - (z + 2) * (z + 1) / 2;
        // cout << x + (y + 2) * (y + 1) / 2 + (z + 2) * (z + 1) / 2 << endl
            // << x << " " << y << " " << z << endl << (x + y + 5) << endl;
        
        cout << "133";
        for(int i = 0; i < x; i++) {
            cout << "7";
        }
        for(int i = 0; i < z; i++) {
            cout << "3";
        }
        cout << "7";
        for(int i = 0; i < y - z; i++) {
            cout << "3";
        }
        cout << "7" << endl;
    }
}