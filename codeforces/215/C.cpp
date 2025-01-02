/*
Problem: 215C
Date: 29-05-2024 05:15 AM
*/


#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// union of two rectangles with same center
// 1. count cases where one rectangle entirely inside other,
// 2. where the two rectangles are identical,
// 3. and where rectangles are not nested

// 1. pairs (a, b) with (2a + 1) * (2b + 1) = s,
//    Then we decide c and d with 0 <= c <= a, 0 <= d <= b, so we count (a + 1) * (b + 1) for the pair
//    Then we decide (x, y). Must have 1 <= x - a, x + a <= n. 1 <= y - b, y + b <= m
//    (n - a) - (1 + a) + 1 = n - 2a, so we count (n - 2a) * (m - 2b)
//    everything requires 2a <= n and 2b <= m
//    multiply part 1 by 2 if we swap (a, b) and (c, d)

// 2. we have double counted coincident rectangles, so we subtract these cases
//    for each valid rectangle (a, b), we subtract (n - 2a) * (m - 2b)

// 3. decide dimensions of intersection. c < a and d < b
//    for each valid rectangle with area 

// you know what, let's just try to code this instead of thinking too hard

int n, m, s;

ll area(int a, int b, int c, int d) {
    return (2 * a + 1) * (2 * b + 1) + (2 * c + 1) * (2 * d + 1) - (2 * min(a, c) + 1) * (2 * min(b, d) + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> s;
    ll ans = 0;
    for(int a = 0; 2 * a + 1 <= n; a++) {
        for(int b = 0; 2 * b + 1 <= m; b++) {
            for(int c = 0; 2 * c + 1 <= n; c++) {
                if(c <= a) {
                    int d = b + max(0, (s - (2 * a + 1) * (2 * b + 1)) / (4 * c + 2));
                    if(area(a, b, c, d) == s && 2 * d + 1 <= m) {
                        ll xy = (n - 2 * max(a, c)) * (m - 2 * max(b, d));
                        if(d == b) {
                            ans += xy * (b + 1);
                        }else {
                            ans += xy;
                        }
                    }
                }else {
                    int d = max(0, (s - (2 * a + 1) * (2 * b + 1) - 2 * (c - a)) / (4 * (c - a)));
                    if(d > b) {
                        d = b + max(0, (s - (2 * c + 1) * (2 * b + 1)) / (4 * c + 2));
                    }
                    if(area(a, b, c, d) == s && 2 * d + 1 <= m) {
                        ll xy = (n - 2 * max(a, c)) * (m - 2 * max(b, d));
                        ans += xy;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}