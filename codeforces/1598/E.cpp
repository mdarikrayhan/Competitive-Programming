#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "Reference/debug.h"
#else
#define debug(...) 42
#endif

#define forn(i,a,n) for(int i = a; i < n; i++)
#define endl '\n'
#define __ ios_base::sync_with_stdio(0);cin.tie(0);
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
typedef long long int lli;
typedef long double Double;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const lli MAXV = 100000000000ll;
const int MAXN = 1e3+5;
const int mod = 1e9+7;

int mat[MAXN][MAXN];
lli dp[MAXN][MAXN][2]; // 0 der, 1 abajo
lli ans = 0, libres = 0;
int n, m, q;

void update(int a, int b){
    // debug(a,b,mat[a][b]);
    if(mat[a][b]){
        // la volveremos libres
        dp[a][b][0] = dp[a][b][1] = 1;
        if(a+1 <= n && !mat[a+1][b])
            dp[a][b][1]+=dp[a+1][b][0];
        if(b+1 <= m && !mat[a][b+1])
            dp[a][b][0]+=dp[a][b+1][1];
        ans+=(dp[a][b][0] + dp[a][b][1]);
        libres++;
    }
    else{
        // volveremos locked
        ans-=(dp[a][b][0] + dp[a][b][1]);
        dp[a][b][0] = dp[a][b][1] = 0;
        libres--;
    }
    mat[a][b] = !mat[a][b];

    queue<pii> q;
    if(a-1 >= 1 && !mat[a-1][b])
        q.push(pii(a-1, b));
    if(b-1 >= 1 && !mat[a][b-1])
        q.push(pii(a, b-1));
    
    // debug(q.size());
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        int x,y;
        tie(x,y) = p;
        if(x+1 <= n){
            lli old = dp[x][y][1];
            lli nuevo = 1 + dp[x+1][y][0];
            if(old != nuevo){
                ans-=old;
                ans+=nuevo;
                dp[x][y][1] = nuevo;
                if(y-1 >= 1 && !mat[x][y-1])
                    q.push(pii(x, y-1));
            }
        }

        if(y+1 <= m){
            lli old = dp[x][y][0];
            lli nuevo = 1 + dp[x][y+1][1];
            if (old != nuevo){
                ans-=old;
                ans+=nuevo;
                dp[x][y][0] = nuevo;
                if(x-1 >= 1 && !mat[x-1][y])
                    q.push(pii(x-1,y));
            }
        }
    }
}

void solve(){
    cin >> n >> m >> q;
    libres = n * m;
    
    for(int i=n; i >= 1; i--){
        for(int j=m; j >= 1; j--){
            dp[i][j][0] = dp[i][j][1] = 1;
            if(i + 1 <= n)
                dp[i][j][1]+=dp[i+1][j][0];
            if(j+1 <= m)
                dp[i][j][0]+=dp[i][j+1][1];
            ans += dp[i][j][0] + dp[i][j][1];
        }
    }
    
    forn(k,0,q){
        int a,b;
        cin >> a >> b;
        update(a,b);
        cout << ans - libres << endl;
    }
}

int main(){__
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
