#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int trans[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
const int N = 1001, M = 1001;
char grid[N][M];
int dis[4][N][M];
int n,m;

void calDist( deque<pii> &dq, int v ){
    while( dq.size() ){
        int x = dq.front().first, y = dq.front().second;
        dq.pop_front();
        for( int i = 0 ; i < 4 ; i++ ){
            int nx = x + trans[i][0], ny = y + trans[i][1];
            if( nx < 0 || nx >= n || ny < 0 || ny >= m ) continue;
            if( grid[nx][ny] == '#' ) continue;
            if( grid[nx][ny] == '.' ){
                if( dis[v][nx][ny] > dis[v][x][y] + 1 ){
                    dis[v][nx][ny] = dis[v][x][y] + 1;
                    dq.push_back({nx,ny});
                }
            }else{
                if( dis[v][nx][ny] > dis[v][x][y] ){
                    dis[v][nx][ny] = dis[v][x][y];
                    dq.push_front({nx,ny});
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;

    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < m ; j++ ){
            cin >> grid[i][j];
        }
    }

    deque<pii> dq1,dq2,dq3;
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < m ; j++ ){
            for( int k = 0 ; k < 4 ; k++ ) dis[k][i][j] = 1e8;
            if( grid[i][j] == '1' ){
                dis[1][i][j] = 0;
                dq1.push_back({i,j});
            }else if( grid[i][j] == '2' ){
                dis[2][i][j] = 0;
                dq2.push_back({i,j});
            }else if( grid[i][j] == '3' ){
                dis[3][i][j] = 0;
                dq3.push_back({i,j});
            }

        }
    }

    calDist(dq1,1);
    calDist(dq2,2);
    calDist(dq3,3);

    int ans = 1e8;  
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < m ; j++ ){
            ans = min(ans, dis[1][i][j] + dis[2][i][j] + dis[3][i][j] - 2*(grid[i][j] == '.'));
        }
    }

    if( ans == 1e8 ) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}