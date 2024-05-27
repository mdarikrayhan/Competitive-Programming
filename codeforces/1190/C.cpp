/*
Problem: 1190C
Date: 24-05-2024 11:34 AM
*/


#include <bits/stdc++.h>

#define ll long long
using namespace std;

// if a k-window contains all the 0's or all the 1's, tokitsukaze wins
// if this is impossible, but every k-window creates this situation for
// the other player, quality wins
// otherwise, once again.

// we can tell if a k-window contains all 0's or all 1's by 
// keeping track of the leftmost (rightmost) 0 (1).
// to see if an interval creates the winning situation
// we test a k-window [j, j + k). Assume you change it to 0's.
// the new leftmost 0 is either the old leftmost 0 or j.
// the new leftmost 1 is either the leftmost 1 in the interval [0, j),
// or the leftmost 1 in the interval [j, n).

const int MAX_N = 1e5 + 5;
int n, k;
string s;

// pos[a][b][c][j].
// a tells us 0 or 1
// b tells us leftmost or rightmost of bit a
// c tells us if it's the interval [0, j) or [j, n) we are concerned about.
int pos[2][2][2][MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k >> s;
    for(int i = 0; i <= n; i++) {
        for(int a = 0; a < 2; a++) {
            pos[a][0][0][i] = pos[a][0][1][i] = n;
            pos[a][1][0][i] = pos[a][1][1][i] = -1;
        }
    }
    for(int i = 0; i < n; i++) {
        // rightmost in [0, j)
        pos[0][1][0][i + 1] = (s[i] == '0' ? i : pos[0][1][0][i]);
        pos[1][1][0][i + 1] = (s[i] == '1' ? i : pos[1][1][0][i]);
        // leftmost in [0, j)
        pos[0][0][0][i + 1] = (s[i] == '0' ? min(pos[0][0][0][i], i) : pos[0][0][0][i]);
        pos[1][0][0][i + 1] = (s[i] == '1' ? min(pos[1][0][0][i], i) : pos[1][0][0][i]);
    }
    for(int i = n - 1; i >= 0; i--) {
        // leftmost in [j, n)
        pos[0][0][1][i] = (s[i] == '0' ? i : pos[0][0][1][i + 1]);
        pos[1][0][1][i] = (s[i] == '1' ? i : pos[1][0][1][i + 1]);
        // rightmost in [j, n)
        pos[0][1][1][i] = (s[i] == '0' ? max(pos[0][1][1][i + 1], i) : pos[0][1][1][i + 1]);
        pos[1][1][1][i] = (s[i] == '1' ? max(pos[1][1][1][i + 1], i) : pos[1][1][1][i + 1]);
    }
    if(pos[0][1][0][n] - pos[0][0][0][n] < k || pos[1][1][0][n] - pos[1][0][0][n] < k) {
        cout << "tokitsukaze" << endl;
        return 0;
    }
    for(int i = 0; i <= n - k; i++) {
        // test interval [i, i + k)
        // changing to 0's
        int left0 = min(pos[0][0][0][n], i);
        int right0 = max(pos[0][1][0][n], i + k - 1);
        int left1 = min(pos[1][0][0][i], pos[1][0][1][i + k]);
        int right1 = max(pos[1][1][0][i], pos[1][1][1][i + k]);
        if(right0 - left0 >= k && right1 - left1 >= k) {
            cout << "once again" << endl;
            return 0;
        }
        // changing to 1's

        left1 = min(pos[1][0][0][n], i);
        right1 = max(pos[1][1][0][n], i + k - 1);
        left0 = min(pos[0][0][0][i], pos[0][0][1][i + k]);
        right0 = max(pos[0][1][0][i], pos[0][1][1][i + k]);
        if(right0 - left0 >= k && right1 - left1 >= k) {
            cout << "once again" << endl;
            return 0;
        }
    }
    cout << "quailty" << endl;
}