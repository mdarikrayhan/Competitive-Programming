/*
Problem: 1201D
Date: 23-05-2024 07:19 AM
*/


#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 2e5 + 5;
int n, m, k, q, r, c;
pair<int, int> chests[MAX_N];
int b[MAX_N];
int lcol[MAX_N], rcol[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k >> q;
    set<int> rows;
    int maxrow = 0;
    for(int i = 0; i < k; i++) {
        cin >> r >> c;
        chests[i] = {r - 1, c - 1};
        maxrow = max(maxrow, r - 1);
    }
    for(int i = 0; i < q; i++) {
        cin >> b[i];
        b[i]--;
    }
    sort(b, b + q);
    // compute nearest column to the left; to the right.
    for(int i = 0; i < m; i++) {
        lcol[i] = b[0];
        rcol[i] = b[q - 1];
    }
    for(int i = 0; i < q - 1; i++) {
        for(int j = b[i]; j < b[i + 1]; j++) {
            lcol[j] = b[i];
            rcol[j + 1] = b[i + 1];
        }
    }
    for(int i = b[q - 1]; i < m; i++) {
        lcol[i] = b[q - 1];
    }
    for(int i = 0; i <= b[0]; i++) {
        rcol[i] = b[0];
    }

    sort(chests, chests + k);
    int row = -1;
    int mincol = -1, maxcol = m;
    int safecols[4], safecols2[4];
    ll dist[4], dist2[4];
    for(int i = 0; i < k; i++) {
        if(row != chests[i].first) {
            if(i == 0) {
                for(int j = 0; j < 4; j++) {
                    safecols[j] = (chests[i].first == 0 ? 0 : rcol[0]);
                    dist[j] = safecols[j];
                }
            }else {
                maxcol = chests[i - 1].second;

                safecols2[0] = lcol[mincol];
                safecols2[1] = rcol[mincol];
                safecols2[2] = lcol[maxcol];
                safecols2[3] = rcol[maxcol];

                for(int j = 0; j < 4; j++) {
                    dist2[j] = LLONG_MAX;
                    for(int l = 0; l < 4; l++) {
                        dist2[j] = min(dist2[j], dist[l] + min(
                                abs(safecols[l] - maxcol) + maxcol - mincol + abs(mincol - safecols2[j]),
                                abs(safecols[l] - mincol) + maxcol - mincol + abs(maxcol - safecols2[j])));
                    }
                }
                for(int j = 0; j < 4; j++) {
                    safecols[j] = safecols2[j];
                    dist[j] = dist2[j];
                }
            }
            row = chests[i].first;
            mincol = chests[i].second;
        }
    }
    ll ans = LLONG_MAX;
    maxcol = chests[k - 1].second;
    for(int j = 0; j < 4; j++) {
        ans = min(ans, dist[j] + min(
            abs(safecols[j] - maxcol) + maxcol - mincol,
            abs(safecols[j] - mincol) + maxcol - mincol));
    }
    cout << (ans + maxrow) << endl;
}