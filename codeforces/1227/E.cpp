#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second

int n, t, m;
int nx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int ny[8] = {1, -1, 1, -1, 0, 1, -1, 0};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
  
    cin >> n >> m;
    
    vector<vector<bool>> grid(n + 2, vector<bool>(m + 2));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char ch;
            cin >> ch;
            if(ch == 'X'){
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }

    queue<pair<ll, ll>> q;
    vector<vector<ll>> dist(n + 2, vector<ll>(m + 2, -1));
    for(int i = 0; i <= n + 1; i++){
        for(int j = 0; j <= m + 1; j++){
            if(grid[i][j] == 0){
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    
    while(!q.empty()){
        int x = q.front().fi, y = q.front().se;
        q.pop();
        for(int i = 0; i < 8; i++){
            ll next_x = x + nx[i];
            ll next_y = y + ny[i];
            if(next_x < 0 || next_x > n + 1 || next_y < 0 || next_y > m + 1 || dist[next_x][next_y] != -1) continue;
            dist[next_x][next_y] = dist[x][y] + 1;
            q.push({next_x, next_y});
        }
    }
    
    auto cek = [&](ll mid){
        queue<pair<ll, ll>> q2;
        vector<vector<ll>> udah(n + 2, vector<ll>(m + 2));
        vector<vector<ll>> dist2(n + 2, vector<ll>(m + 2)); 
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(dist[i][j] > mid){
                    q2.push({i, j});
                    udah[i][j] = true;
                }
            }
        }
        
        while(!q2.empty()){
            int x = q2.front().fi, y = q2.front().se;
            q2.pop();
            if(dist2[x][y] == mid) continue;
            for(int i = 0; i < 8; i++){
                ll next_x = x + nx[i];
                ll next_y = y + ny[i];
                if(next_x <= 0 || next_x > n || next_y <= 0 || next_y > m || udah[next_x][next_y]) continue;
                udah[next_x][next_y] = true;
                dist2[next_x][next_y] = dist2[x][y] + 1;
                q2.push({next_x, next_y});
            }
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if((grid[i][j] == 1 && !udah[i][j]) || (grid[i][j] == 0 && udah[i][j])){
                    return false;
                }
            }
        }
        
        return true;
    };
    
    int l = 0, r = min(n, m), ans;
    while(l < r){
        int mid = (l + r) / 2;
        if(cek(mid)){
            ans = mid;
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    
    cout << ans << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            (dist[i][j] > ans) ? cout << 'X' : cout << '.';
        }
        cout << '\n';
    }
    
    return 0;
}