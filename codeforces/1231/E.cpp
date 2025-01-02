/*
Problem: 1231E
Date: 28-05-2024 02:06 PM
*/


#include <bits/stdc++.h>

#define ll long long
using namespace std;

int q, n;
string s, t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> n >> s >> t;
        int M = 0;
        for(int i = 0; i < n; i++) {
            int j = i, k = 0;
            while(k < n && j < n) {
                if(s[k] == t[j]) {
                    j++;
                }
                k++;
            }
            M = max(M, j - i);
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s == t) {
            cout << (n - M) << endl;
        }else {
            cout << -1 << endl;
        }
    }
}