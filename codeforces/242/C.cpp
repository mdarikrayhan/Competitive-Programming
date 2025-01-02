#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "cplib.h"
#endif
#define boost std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
typedef long long ll;
typedef long double ld;
using namespace std;
const ll MOD = 1e9 + 7;
const int MAXM = 2e5 + 1;
// --------------------------------
// ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣦⣄⡀⠄⠄⠄⠄⠄⠄⠄
// ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣤⡀⠄⠄⠄⠄⠄
// ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⠄⠄⠄⠄
// ⣿⣿⣿⠟⠋⠁⣀⣀⡈⠙⣿⣿⣿⣿⡿⠿⠿⠿⠿⢡⣤⣄⡈⠙⢧⠄⠄⠄
// ⣏⣉⣀⣠⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠷⠶⠶⠤⣉⠙⠷⣼⣇⠄⠄
// ⠿⠿⠿⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⡀⠄⠄⣿⣿⣶⣈⠙⣄⠄
// ⣿⣷⡶⠶⠶⠶⠒⠂⠄⠈⣽⣿⣿⣿⣿⣿⣿⣿⣿⣆⠄⣿⣿⣷⡶⠖⠄⣶
// ⣁⣤⣴⣶⣶⠾⠟⠛⠛⢛⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⠄⣿⣿⣿⣓⠂⠄⣤
// ⠟⢛⣉⣥⣤⣶⡶⠛⢋⣉⡴⢟⣙⠶⣋⣿⣿⣿⠿⠛⠄⠛⠻⢧⡙⠾⢂⣄
// ⣾⣿⣿⡿⠓⣀⠐⠲⠞⣡⣶⠟⢁⣴⠽⠛⣉⣠⣶⣿⣿⣿⣶⣤⠉⣠⣌⠻
// ⣿⣿⣫⣶⣾⣿⡟⣠⣤⣤⠄⣀⣤⣤⣴⣾⣿⣿⣿⣿⣿⣿⡿⢋⡄⢻⣿⣷
// --------------------------------
// stumble and fall, but never stay down
// you can only go up from there

void solve() {
    // take start and end points
    int stx, sty, enx, eny;
    cin >> stx >> sty >> enx >> eny;

    // use maps instead of vectors bc range is 1e9
    map<pair<ll, ll>, ll> dist;
    map<pair<ll, ll>, bool> allowed;
    map<pair<ll, ll>, bool> visited;

    int qry; cin >> qry;
    while(qry--) {
        // take x to y for each row r
        int r, x, y;
        cin >> r >> x >> y;

        //  map each pair of allowed x and y
        for(int c = x; c <= y; c++) {
            allowed[{r, c}] = true;
        }
    }
    
    // start and end points are allowed
    allowed[{stx, sty}] = true;
    allowed[{enx, eny}] = true;

    // queue for bfs and distance of start point is 0
    queue<pair<ll, ll>> q;
    dist[{stx, sty}] = 0;
    q.push({stx, sty});

    // arrays for square cell traversal
    int dx[] = {-1, -1, -1, 1, 1, 1, 0, 0};
    int dy[] = {-1, 0, 1, -1, 0, 1, 1, -1};

    // start of bfs
    while(!q.empty()) {

        // take start cell (pair)
        pair<ll, ll> s = q.front(); q.pop();

        // check all cells
        for(int i = 0; i < 8; i++) {

            int newX = s.first + dx[i];
            int newY = s.second + dy[i];

            // make sure new cell is allowed (in range) and not visited before
            if(allowed[{newX, newY}] && !visited[{newX, newY}]) {

                // if new cell isnt computed then its valid
                if(!dist[{newX, newY}])
                dist[{newX, newY}] = dist[{s.first, s.second}] + 1, q.push({newX, newY});
            }

            // mark cell as visited
            visited[{s.first, s.second}] = true;
        }

    }

    // end point is reachable only if it gets computed
    if(visited[{enx, eny}]) {
        cout << dist[{enx, eny}];
    } else cout << -1;
}

int main() {

    boost;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
        cout << '\n';
    }

}