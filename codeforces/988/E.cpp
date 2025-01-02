/*
Problem: 988E
Date: 25-05-2024 03:16 PM
*/


#include <bits/stdc++.h>

#define ll long long
using namespace std;

// what a retarded problem

// ends with 25, 50, 75, or 00
// try to move one of these to last two digits
// for 00 and 05, move 0 to right first, then other digit
// exception: 5001 for example
// 5001 -> 5010 -> 5100 -> 1500 -> 1050

vector<int> pos[10];
string s;
int n;

int solve(int i, int j) {
    if(i == 1) {
        int k = 2;
        for(; k <= n && (s[k] == '0' || k == j); k++);
        if(k <= n && s[k] != 0 && k != j) {
            return (k - 2) - (k > j) + (n - j) + (n - 1 - i);
        }else return 1e9;
    }else if(j == 1) {
        int k = 2;
        for(; k <= n && (s[k] == '0' || k == i); k++);
        if(k <= n && s[k] != 0 && k != i) {
            return (k - 2) - (k > i) + (n - j) + (n - 1 - i) + 1;
        }else return 1e9;
    }
    return (n - j) + (n - 1 - (i - (i > j)));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    if(s.length() <= 2) {
        if(s == "25" || s == "50" || s == "75") {
            cout << 0 << endl;
        }else if(s == "52" || s == "57") {
            cout << 1 << endl;
        }else {
            cout << -1 << endl;
        }
        return 0;
    }
    n = (int) s.length();
    s = "$" + s;
    for(int i = 1; i <= n; i++) {
        pos[s[i] - '0'].push_back(i);
    }
    int ans = 1e9;
    // 00
    if((int) pos[0].size() >= 2) {
        int k = (int) pos[0].size();
        ans = min(ans, n - pos[0][k - 1] + (n - 1) - pos[0][k - 2]);
    }
    // 50
    if(!pos[5].empty() && !pos[0].empty()) {
        ans = min(ans, solve(pos[5].back(), pos[0].back()));
    }
    // 25
    if(!pos[2].empty() && !pos[5].empty()) {
        ans = min(ans, solve(pos[2].back(), pos[5].back()));
    }
    // 75
    if(!pos[7].empty() && !pos[5].empty()) {
        ans = min(ans, solve(pos[7].back(), pos[5].back()));
    }
    cout << (ans == 1e9 ? -1 : ans) << endl;
}