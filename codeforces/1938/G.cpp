#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int MAXN = 400010;
const int64_t INF = 1e18;

void Solve(void) {
    int N, M, K; cin >> N >> M >> K;
    vector<vector<char>> s(N + 2, vector<char>(M + 2));
    vector<vector<vector<int>>> match(30, vector<vector<int>> (M + 3));
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= M; j ++) {
            cin >> s[i][j];
        }
    }
    vector<vector<int>> score(N + 2, vector<int> (N + 2, 0));
    for (int i = 1; i <= N; i ++) {
        int best = -1;
        for (int j = 1; j <= M; j ++) {
            if (s[i][j] != '.') {
                int sz = match[s[i][j] - 'A'][j].size();
                for (int z = sz - 1; z >= 0; z --) {
                    int ii = match[s[i][j] - 'A'][j][z];
                    score[ii][i] ++;
                    if (score[ii][i] >= K) {
                        best = max(best, ii);
                    }
                }
                match[s[i][j] - 'A'][j].pb(i);
            }
        }
        if (best != -1) {
            cout << best << " " << i << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int Tests = 1; // cin >> Tests; 
    while (Tests --) {
        Solve();    
    }
}