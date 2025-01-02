#include<bits/stdc++.h>
using ll = long long;
using namespace std;
typedef pair<int, int> pii;

const int N = 1010;
const int M = 41;
const int inf = 0x3f3f3f3f;

bool vis[M];
int dis[M][N][N];
int a[N][N];
vector<pii> pos[M];

int n, m, k;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int k){
    memset(vis, 0, sizeof vis);
    
    vis[k] = 1;
    queue<pii> q;
    for(auto [x, y] : pos[k]){
        dis[k][x][y] = 0;
        q.push({x, y});
    }

    while(q.size()){
        auto [x, y] = q.front();
        q.pop();

        int c = a[x][y], d = dis[k][x][y];

        if(!vis[c]){
            vis[c] = 1;
            
            for(auto [x1, y1] : pos[c]){
                if(dis[k][x1][y1] < 0){
                    dis[k][x1][y1] = d + 1;
                    q.push({x1, y1});
                }
            }
        }

        for(int i = 0; i < 4; i++){
            int x1 = x + dx[i];
            int y1 = y + dy[i];

            if(x1 > 0 && x1 <= n && y1 > 0 && y1 <= m && dis[k][x1][y1] < 0){
                dis[k][x1][y1] = d + 1;
                q.push({x1, y1});
            }
        }
    }
}

void work(){
    memset(dis, -1, sizeof dis);
    
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int col;
            cin >> col;

            a[i][j] = col;

            pos[col].push_back({i, j});
        }
    }

    for(int i = 1; i <= k; i++){
        bfs(i);
    }

    int q;
    cin >> q;

    for(int i = 1; i <= q; i++){
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        int res = abs(x1 - x2) + abs(y1 - y2);
        for(int j = 1; j <= k; j++){
            res = min(res, dis[j][x1][y1] + dis[j][x2][y2] + 1);
        }

        cout << res << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr), cout.tie(nullptr);

    int T = 1; //cin >> T;
    while(T--) work();

    return 0;
}