#include <bits/stdc++.h>
using namespace std;
using lli = int64_t;

#define INFILE "821D.inp"
#define OUTFILE "821D.out"

const int inf = 0x3f3f3f3f;

int minimise(int& x, int y) {
    if (x > y) return x = y, true;
    return false;
}

const int MAX_QUEUE = (int) 3e4;
int pos_queue[2 * MAX_QUEUE + 5], state_queue[2 * MAX_QUEUE + 5];
int qu_L = 0, qu_R = 0;


const int MAX_N = (int) 1e4;
int dist[MAX_N][3]; pair <int, int> point[MAX_N];
int ID_row[MAX_N], ID_col[MAX_N];
void add_back(int x, int y, int state) {
    if (minimise(dist[x][y], state)) {
        pos_queue[++qu_R] = x;
        state_queue[qu_R] = y;
    }
}
void add_front(int x, int y, int state) {
    if (minimise(dist[x][y], state)) {
        pos_queue[--qu_L] = x;
        state_queue[qu_L] = y;
    }
}
void solve() {
    int N, M, K; cin >> N >> M >> K;
    memset(dist, 0x3f, sizeof dist);

    vector <vector <int>> compress_row(N), compress_col(M);
    for (int i = 0; i < K; ++i) {
        pair <int, int>& P = point[i]; cin >> P.first >> P.second;
        P.first -= 1; P.second -= 1;
        compress_row[P.first].push_back(i);
        compress_col[P.second].push_back(i);
    }

    for (int i = 0; i < N; ++i) {
        sort(compress_row[i].begin(), compress_row[i].end(), [&] (int u, int v) {
            return point[u].second < point[v].second;
        });

        for (int j = 0; j < (int) compress_row[i].size(); ++j) {
            ID_row[compress_row[i][j]] = j;
        }
    }
    for (int i = 0; i < M; ++i) {
        sort(compress_col[i].begin(), compress_col[i].end(), [&] (int u, int v) {
            return point[u].first < point[v].first;
        });

        for (int j = 0; j < (int) compress_col[i].size(); ++j) {
            ID_col[compress_col[i][j]] = j;
        }
    }

    
    for (int i = 0; i < K; ++i) {
        pair <int, int>& T = point[i];
        if (T.first == 0 and T.second == 0) {
            dist[i][0] = 0;

            pos_queue[MAX_QUEUE] = i; state_queue[MAX_QUEUE] = i;
        }
    }

    qu_L = qu_R = MAX_QUEUE;
    while (qu_L <= qu_R) {
        int nxt_pos = pos_queue[qu_L], nxt_state = state_queue[qu_L];
        int nxt_dist = dist[nxt_pos][nxt_state];
        qu_L += 1;
    
        add_back(nxt_pos, 1, nxt_dist + 1);
        add_back(nxt_pos, 2, nxt_dist + 1);

        for (int T = 0; T < K; ++T) {
            if (point[T].first != point[nxt_pos].first and point[T].second != point[nxt_pos].second) {
                int first_option = abs(point[T].first - point[nxt_pos].first) == 1;
                int second_option = abs(point[T].second - point[nxt_pos].second) == 1;

                if (first_option and second_option) {
                    if (nxt_state == 0) {
                        add_back(T, 1, nxt_dist + 1);
                        add_back(T, 2, nxt_dist + 1);
                    } else {
                        add_front(T, 0, nxt_dist);
                        add_back(T, 3 - nxt_state, nxt_dist + 1);
                    }
                } else if (first_option) {
                    if (nxt_state == 0 or nxt_state == 2) {
                        add_back(T, 1, nxt_dist + 1);
                        add_back(T, 0, nxt_dist + 1);
                    } else {
                        add_front(T, 0, nxt_dist);
                    }
                } else if (second_option) {
                    if (nxt_state == 0 or nxt_state == 1) {
                        add_back(T, 0, nxt_dist + 1);
                        add_back(T, 2, nxt_dist + 1);
                    } else {
                        add_front(T, 0, nxt_dist);
                    }
                }

                first_option = abs(point[T].first - point[nxt_pos].first) == 2;
                second_option = abs(point[T].second - point[nxt_pos].second) == 2;

                if (first_option or second_option) {
                    add_back(T, 0, nxt_dist + 1);
                }

                continue;
            }

            if (point[T].first == point[nxt_pos].first) {
                if (ID_row[T] - ID_row[nxt_pos] == point[T].second - point[nxt_pos].second or nxt_state == 1) {
                    add_front(T, nxt_state == 1, nxt_dist);
                } else {
                    add_back(T, 1, nxt_dist + 1);
                }
            }

            if (point[T].second == point[nxt_pos].second) {
                if (ID_col[T] - ID_col[nxt_pos] == point[T].first - point[nxt_pos].first or nxt_state == 2) {
                    add_front(T, nxt_state == 2 ? 2 : 0, nxt_dist);
                } else {
                    add_back(T, 2, nxt_dist + 1);
                }
            }
        }
    }

    int finale = inf;
    for (int i = 0; i < K; ++i) {
        pair <int, int>& T = point[i];  

        if (T.first == N - 1 and T.second == M - 1) {
            minimise(finale, min({dist[i][0], dist[i][1], dist[i][2]}));
        } else if (T.first == N - 1) {
            minimise(finale, min(dist[i][0], dist[i][2]) + 1);
            minimise(finale, dist[i][1]);
        } else if (T.second == M - 1) {
            minimise(finale, min(dist[i][0], dist[i][1]) + 1);
            minimise(finale, dist[i][2]);
        }

        if (T.first == N - 2 or T.second == M - 2) {
            minimise(finale, min({dist[i][0], dist[i][1], dist[i][2]}) + 1);
        }
    }

    if (finale == inf) finale = -1;
    cout << finale << '\n';
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    if (fopen(INFILE, "r")) {
        freopen(INFILE, "r", stdin);
        freopen(OUTFILE, "w", stdout);
    }

    int T = 1; //cin >> T;
    for (; T; --T) solve();
    return 0;
}

/*
Spring-Autumn Training 2024
Tasks: 126 / 200
*/