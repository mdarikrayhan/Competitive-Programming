#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(),a.rend()

const int mod = 998244353;
const int dx[] = { 1, 0, -1, 0 };                                                            
const int dy[] = { 0, 1, 0, -1 };     

int lcm(int a,int b){
    return a/__gcd(a,b)*b;
}

int maxN = 1000+ 1, n,m,k;
vector<vector<int>>vis(maxN,vector<int>(maxN)),a(maxN,vector<int>(maxN));

bool valid(int i,int j){
    return i < n && j < m && i >= 0 && j >= 0 && a[i][j];
}

void solve() {
    int x1,x2,y1,y2;
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;

            a[i][j] = (c=='.'?1:0);
        }
    }
    cin >> x1 >> y1 >> x2 >> y2;
    x1--,x2--,y1--,y2--;
    // BFS 01 pra preferir ficar na msm direcao
    if(x1 == x2 && y1 == y2){
        cout << 0 << endl;
        return;
    }
    vector<vector<int>>dist(n,vector<int>(m,1e9));

    queue<pair<int,int>>q;
    q.push({x1,y1});
    dist[x1][y1] = 0;
    while(!q.empty()){
        int i = q.front().first, j = q.front().second;
        q.pop();
        for(int d = 0; d < 4; d++){
            for(int step = 1; step <= k; step++){
                int ni = i + dx[d]*step, nj = j + dy[d]*step;


                if(!valid(ni,nj))break;
                // if(dist[ni][nj] != 1e9)continue;

                if(dist[ni][nj] > dist[i][j] + 1){
                    dist[ni][nj] = dist[i][j] + 1;
                    q.push({ni,nj});
                }


                if(ni == x2 && nj == y2){
                    cout << dist[ni][nj] << endl;
                    return;
                }

            }
        }
    }  
    cout << -1 << endl; 
    // int ans = dist[x2][y2];
    // if(ans == 1e9)ans = -1;
    // cout << ans << endl;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


