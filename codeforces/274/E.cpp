#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mp make_pair
#define F first
#define S second

int n, m, k, res, tarx, tary, tard, x, y, d, a, b, ove = 1, dx[] = {-1, -1, 1, 1}, dy[] = {1, -1, -1, 1};
string dir;
map<int, int> g[100010];
set<pair<int, int> > s[2][200010];

void add(int X, int Y){
    s[0][X + Y].insert(mp(X, Y)), s[1][X + (m + 1 - Y)].insert(mp(X, Y)), g[X][Y] = 1;
}

void run(int cc){
    auto id = s[d & 1][(d & 1 ? x + (m + 1 - y) : x + y)].lower_bound(mp(x, y));
    int fil;
    if(d < 2)
        id--;
    res += cc * abs(x - (*id).F), x = (*id).F - dx[d], y = (*id).S - dy[d], fil = g[x][y + dy[d]] + g[x + dx[d]][y];
    if(fil == 1){
        if(g[x][y + dy[d]])
            x += dx[d], d ^= 1;
        else
            y += dy[d], d ^= 3;
    }
    if(fil == 0 || fil == 2)
        ove = 2, d ^= 2;
}

signed main(){
    cin >> n >> m >> k;
    while(k--)
        cin >> a >> b, add(a, b);
    cin >> x >> y >> dir;
    for(int i = 0; i <= n + 1; i++)
        add(i, 0), add(i, m + 1);
    for(int i = 0; i <= m + 1; i++)
        add(0, i), add(n + 1, i);
    if(dir == "NE")
        d = 0;
    if(dir == "NW")
        d = 1;
    if(dir == "SW")
        d = 2;
    if(dir == "SE")
        d = 3;
    run(0), tarx = x, tary = y, tard = d, run(1);
    while(x != tarx || y != tary || d != tard)
        run(1);
    cout << res / ove << endl;
}
 	  	   	  	     	 	 	   		 		