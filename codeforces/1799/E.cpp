#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
using namespace std;

using ll = long long; using ld = long double; 
using pii = pair<int,int>; using pll = pair<ll,ll>;
using vi = vector<int>; using vl = vector<ll>; using vc = vector<char>; using vb = vector<bool>;
const int INF = 1e9+10; const ll INF_LL = 2e18; const ld PI = atan2(0,-1);
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define forn(i,a,b) for(auto i=a; i<b; ++i)
#define forr(i,a,b) for(auto i=a; i>b; --i)

#ifdef LOCAL
    #include "/home/dulustan/disk/projects/LIBR/Debug/debug.hpp"
#else
    #define deb(...) 0
#endif

void solve(){
    int n,m; cin >> n >> m;
    vector<vi> a(n+1, vi(m+1));
    vector<vector<array<bool,4>>> b(n+1, vector<array<bool,4>>(m+1));
    vector<vector<array<bool,4>>> p(n+1, vector<array<bool,4>>(m+1));
    forn(i,1,n+1)
        forn(j,1,m+1){
            char x; cin >> x;
            a[i][j] = (x == '#');
        }
    forn(i,1,n+1){
        int x=0, y=-1;
        forn(j,1,m+1){
            if(!a[i][j]) continue;
            if(!x) x = j;
            y = j;
        }
        forn(j,x,y+1)
            a[i][j] = 1;   
    }
    forn(j,1,m+1){
        int x=0, y=-1;
        forn(i,1,n+1){
            if(!a[i][j]) continue;
            if(!x) x = i;
            y = i;
        }
        forn(i,x,y+1)
            a[i][j] = 1;        
    }

    forn(i,1,n+1)
        forn(j,1,m+1){
            if(a[i][j]){
                forn(ii, i+1, n+1)
                    forn(jj, j+1, m+1)
                        p[ii][jj][1] = 1;
                forn(ii, i+1, n+1)
                    forn(jj, 1, j)
                        p[ii][jj][0] = 1;
                forn(ii, 1, i)
                    forn(jj, 1, j)
                        p[ii][jj][3] = 1;
                forn(ii, 1, i)
                    forn(jj, j+1, m+1)
                        p[ii][jj][2] = 1;
            }
            bool u=0, d=0, l=0, r=0;
            forn(ii,i,n+1) d |= a[ii][j];
            forn(ii,1,i+1) u |= a[ii][j];
            forn(jj,j,m+1) r |= a[i][jj];
            forn(jj,1,j+1) l |= a[i][jj];
            if(r && u) b[i][j][0] = 1;
            if(l && u) b[i][j][1] = 1;
            if(l && d) b[i][j][2] = 1;
            if(r && d) b[i][j][3] = 1;
        }
    vector<pii> cor(4);
    forn(i,1,n+1)
        forn(j,1,m+1){
            if(b[i][j][0] && p[i][j][2]) a[i][j] = 1;
            if(b[i][j][1] && p[i][j][3]) a[i][j] = 1;
            if(b[i][j][2] && p[i][j][0]) a[i][j] = 1;
            if(b[i][j][3] && p[i][j][1]) a[i][j] = 1;
        }
    forn(i,1,n+1)
        forn(j,1,m+1){
            if(!a[i][j]) continue;
            if(i<n && j<m && !a[i+1][j] && !a[i][j+1] && p[i][j][3]) cor[1] = {i,j};
            if(i<n && j>1 && !a[i+1][j] && !a[i][j-1] && p[i][j][2]) cor[0] = {i,j};
            if(i>1 && j<m && !a[i-1][j] && !a[i][j+1] && p[i][j][0]) cor[2] = {i,j};
            if(i>1 && j>1 && !a[i-1][j] && !a[i][j-1] && p[i][j][1]) cor[3] = {i,j};
        }
    deb(cor);
    if(cor[0].F && cor[2].F){
        forn(j,cor[2].S,cor[0].S+1) a[cor[2].F][j] = 1;
        forn(i,cor[0].F,cor[2].F+1) a[i][cor[0].S] = 1;
    }
    else if(cor[1].F && cor[3].F){
        forn(j,cor[1].S,cor[3].S+1) a[cor[1].F][j] = 1;
        forn(i,cor[1].F,cor[3].F+1) a[i][cor[3].S] = 1;
    }

    forn(i,1,n+1){
        forn(j,1,m+1)
            cout << (a[i][j] ? '#' : '.');
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef LOCAL
        freopen("_in.txt", "r", stdin);
        freopen("_out.txt", "w", stdout);
    #endif    

    int T=1;
    cin >> T;
    for(int t=1; t<=T; ++t){
        solve();
        #ifdef LOCAL
            cout << "\n";
        #endif    
    }
}