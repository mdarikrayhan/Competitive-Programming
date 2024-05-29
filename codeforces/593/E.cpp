/*
Problem: 593E
Date: 29-05-2024 07:04 AM
*/


#include <bits/stdc++.h>

#define ll long long
using namespace std;

// sort all queries by time
// n * m dimensional vector storing for each position, number of ways to be in that cell
// store normal adjacency matrix
// cat enters => replace vector's value with 0
// cat enters or cat leaves => change adjacency matrix
// cat enters, then move, then cat leaves

#define INVITE 1
#define ENTER 2
#define LEAVE 3

const int M = 1e9 + 7, Q = 1e4 + 5, NM = 21;
int n, m, q;
ll t, vec[NM], adj[NM][NM], vectmp[NM], tmp[2][NM][NM];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool cat[NM];
ll T = 1;

struct event {
    int tp, x, y;
    ll t;
} e[Q];

inline bool inbounds(const int x, const int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}
inline int getidx(const int x, const int y) {
    return x * m + y;
}
inline pair<int, int> getpos(const int idx) {
    return {idx / m, idx % m};
}

void upd(ll t) {
    if(t <= 0) return;
    ll p = t - T;
    // set tmp[0] to adjacency matrix
    // vectmp will be new vec, reset to 0
    for(int i = 0; i < n * m; i++) {
        for(int j = 0; j < n * m; j++) {
            tmp[0][i][j] = adj[i][j];
        }
    }
    while(p > 0) {
        if(p & 1) {
            // multiply vec = tmp[0] * vec
            for(int i = 0; i < n * m; i++) {
                vectmp[i] = 0;
                for(int j = 0; j < n * m; j++) {
                    vectmp[i] = (vectmp[i] + tmp[0][i][j] * vec[j]) % M;
                }
            }
            for(int i = 0; i < n * m; i++) {
                vec[i] = vectmp[i];
            }
        }
        for(int i = 0; i < n * m; i++) {
            for(int j = 0; j < n * m; j++) {
                tmp[1][i][j] = 0;
                for(int k = 0; k < n * m; k++) {
                    tmp[1][i][j] = (tmp[1][i][j] + tmp[0][i][k] * tmp[0][k][j]) % M;
                }
            }
        }
        for(int i = 0; i < n * m; i++) {
            for(int j = 0; j < n * m; j++) {
                tmp[0][i][j] = tmp[1][i][j];
            }
        }
        p /= 2;
    }
    T = t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    for(int i = 0; i < q; i++) {
        cin >> e[i].tp >> e[i].x >> e[i].y >> e[i].t;
        e[i].x--;
        e[i].y--;
    }
    vec[0] = 1;
    int idx1, idx2;
    for(int i = 0; i < n * m; i++) {
        auto [x, y] = getpos(i);
        for(int d = 0; d < 4; d++) {
            if(inbounds(x + dx[d], y + dy[d])) {
                int j = getidx(x + dx[d], y + dy[d]);
                adj[i][j] = adj[j][i] = 1;
            }
        }
        adj[i][i] = 1;
    }
    for(int i = 0; i < q; i++) {
        switch(e[i].tp) {
        case INVITE:
            upd(e[i].t);
            cout << vec[getidx(e[i].x, e[i].y)] << endl;
            break;
        case ENTER:
            upd(e[i].t);
            idx1 = getidx(e[i].x, e[i].y);
            cat[idx1] = true;
            vec[idx1] = 0;
            for(int d = 0; d < 4; d++) {
                if(inbounds(e[i].x + dx[d], e[i].y + dy[d])) {
                    idx2 = getidx(e[i].x + dx[d], e[i].y + dy[d]);
                    adj[idx1][idx2] = adj[idx2][idx1] = 0;
                }
            }
            adj[idx1][idx1] = 0;
            break;
        case LEAVE:
            upd(e[i].t);
            idx1 = getidx(e[i].x, e[i].y);
            cat[idx1] = false;
            for(int d = 0; d < 4; d++) {
                if(inbounds(e[i].x + dx[d], e[i].y + dy[d])) {
                    idx2 = getidx(e[i].x + dx[d], e[i].y + dy[d]);
                    if(!cat[idx2]) {
                        adj[idx1][idx2] = adj[idx2][idx1] = 1;
                    }
                }
            }
            adj[idx1][idx1] = 1;
            break;
        }
    }
}