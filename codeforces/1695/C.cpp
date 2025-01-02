#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define lli int
#define endl '\n'
const int MOD = 1e8;
const int INF = 1e18;


const int N = 1e3+5;
int n,m;
int grid[N][N];

void solve(){   
    cin >> n >> m;
    for(int i =0; i<n;i++){
        for(int j = 0; j<m; j++){
            cin >> grid[i][j];
        }
    }

    if(((n+m-1) % 2) == 1){
        cout << "NO" << endl;
        return;
    }

    vector<vector<int>> maxm(n+1,vector<int>(m+1,INF));
    vector<vector<int>> minm(n+1,vector<int>(m+1,INF));

    minm[0][0] = grid[0][0];
    maxm[0][0] = grid[0][0];

    for(int i = 1;i<n;i++){
        minm[i][0] = minm[i-1][0] + grid[i][0];
        maxm[i][0] = maxm[i-1][0] + grid[i][0];
    }

    for(int i = 1;i < m; i++){
        minm[0][i] = minm[0][i-1] + grid[0][i];
        maxm[0][i] = maxm[0][i-1] + grid[0][i];
    }

    for(int i = 1;i<n;i++){
        for(int j = 1; j< m;j++){
            minm[i][j] = min(minm[i-1][j],minm[i][j-1]) + grid[i][j];
            maxm[i][j] = max(maxm[i-1][j],maxm[i][j-1]) + grid[i][j];
        }
    }

    if(minm[n-1][m-1]<=0 && maxm[n-1][m-1]>=0){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;


}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t;
    cin >> _t;
    while (_t--)
        solve();
    return 0;
}