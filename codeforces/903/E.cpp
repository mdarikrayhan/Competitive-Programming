/*
Problem: 903E
Date: 28-05-2024 04:32 AM
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

// K^2 N or K N^2 seem to be ok complexities
// take first string, loop through all possible strings where we swap two characters
// check against all other strings
// at most two characters differ
// if exactly 2, they should be swapped
// if exactly 1, impossible
// if 0, there should be a duplicate character somewhere

const int K = 2505, N = 5005, KN = 5005;
int k, n;
string s[K];
bool dup = false;
int dist[K];
vi dif[K];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> k >> n;
    for(int i = 0; i < k; i++) {
        cin >> s[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(s[0][i] == s[0][j]) dup = true;
        }
    }
    for(int i = 1; i < k; i++) {
        for(int j = 0; j < n; j++) {
            if(s[0][j] != s[i][j]) {
                dist[i]++;
                dif[i].push_back(j);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int l = 1; l < k; l++) {
                int cnt = dist[l] + (s[0][i] != s[l][j]) + (s[0][j] != s[l][i])
                        - (s[0][i] != s[l][i]) - (s[0][j] != s[l][j]);
                if(cnt == 0) {
                    if(!dup) goto endloop;
                }else if(cnt == 2) {
                    vi ve;
                    #define Y(x) ((x) == i ? j : (x) == j ? i : (x))
                    auto check = [&](int x) {
                        int y = Y(x);
                        if(s[l][x] != s[0][y]) ve.push_back(x);
                    };
                    for(int x : dif[l]) check(x);
                    check(i);
                    check(j);
                    sort(ve.begin(), ve.end());
                    ve.erase(unique(ve.begin(), ve.end()), ve.end());
                    assert(sz(ve) == 2);
                    int y0 = Y(ve[0]), y1 = Y(ve[1]);
                    if(s[l][ve[0]] != s[0][y1] || s[l][ve[1]] != s[0][y0]) goto endloop;
                }else goto endloop;
            }

            // if ok
            swap(s[0][i], s[0][j]);
            cout << s[0] << '\n';
            return 0;
            endloop:;
        }
    }
    cout << "-1\n";
}