#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int>> grid;

int n,m;
int getsum(int x1, int y1, int x2, int y2) {
    if (x1==x2 && y1==y2) {
        return grid[x1][y1];
    }
    int su = 0;
    for (int i=x1; i<=x2; i++) {
        su+=grid[i][y1];
        su+=grid[i][y2];
    }
    for (int i=y1; i<=y2; i++) {
        su+=grid[x1][i];
        su+=grid[x2][i];
    }
    su-=grid[x1][y1];
    su-=grid[x1][y2];
    su-=grid[x2][y1];
    su-=grid[x2][y2];
    return su;
}
void assign(int x, int y, int v) {
    if (grid[x][y]==0) grid[x][y] = v;
}
void display(vector<int> coo) {
    int x1,y1,x2,y2;
    x1=coo[0];
    y1=coo[1];
    x2=coo[2];
    y2=coo[3];
    for (int i=x1; i<=x2; i++) {
        assign(i,y1,2);
        assign(i,y2,2);
    }
    for (int i=y1; i<=y2; i++) {
        assign(x1,i,2);
        assign(x2,i,2);
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (grid[i][j]==1) {
                cout << 'w';
            }
            else if (grid[i][j]==2) {
                cout << '+';
            }
            else {
                cout << '.';
            }
        }
        cout << endl;
    }
}

signed main() {
    #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif
    /*#ifdef ONLINE_JUDGE
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    #endif*/ //fast IO
    cin >> n >> m;
    grid=vector<vector<int>>(n,vector<int>(m,-1));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            char c;
            cin >> c;
            if (c=='w') {
                grid[i][j] = 1;
            }
            else {
                grid[i][j] = 0;
            }
        }
    }
    int INF = 1000000007;
    int minx=INF;
    int maxx=-1;
    int miny=INF;
    int maxy=-1;
    int cw=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (grid[i][j] == 1) {
                minx = min(minx, i);
                miny = min(miny, j);
                maxx = max(maxx, i);
                maxy = max(maxy, j);
                cw++;
                //cout << i <<" " << j << " " << endl;
            }
        }
    }
    //cout << minx <<" " << maxx <<" " << miny <<" " << maxy << endl;
    //consider the x span is full    
    vector<vector<int>> answers;
    int delta = maxx-minx;
    for (int j=0; j<m-delta; j++) {
        int x1 = minx;
        int y1 = j;
        int x2 = maxx;
        int y2 = j+delta;
        //cout << x1<<y1<<x2<<y2<<endl;
        if (getsum(x1,y1,x2,y2)==cw) {
            answers.push_back({x1,y1,x2,y2});
        }
    }

    //consider the y span is full    
    delta = maxy-miny;
    for (int j=0; j<n-delta; j++) {
        int x1 = j;
        int y1 = miny;
        int x2 = j+delta;
        int y2 = maxy;
        //cout << x1<<y1<<x2<<y2<<endl;
        if (getsum(x1,y1,x2,y2)==cw) {
            vector<int> v = {x1,y1,x2,y2};
            answers.push_back(v);
        }
    }
    if (!answers.size()) {
        cout << -1 << endl;
        return 0;
    }
    sort(answers.begin(), answers.end(), [&](const vector<int> &v1, const vector<int> &v2) {
        return (v1[2]-v1[0]+v1[3]-v1[1])<(v2[2]-v2[0]+v2[3]-v2[1]);
    });
    vector<int> dis = answers[0];
    display(dis);
    /*for (auto i:dis) {
        cout << i <<" ";

    }
    cout << endl;*/

    
}

