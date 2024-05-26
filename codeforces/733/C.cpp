#include<bits/stdc++.h>
using namespace std;
#define INF 1e17
#define FOR(a, b, c) for (int a = b; a < c; a++)
#define int long long
#define pb push_back
typedef vector <int> vint;
const int N = 510;
vector < pair < int , char > > ans ;
vector < vint > dp(N+1,vint(N+1)), p(N+1, vint(N+1,0));
vint v(N+1), pref(N+1,0);
void f(int i , int j, int pos){
    if( i >= j ) return;
    int k = p[i][j], left = pref[k] - pref[i-1], right = pref[j] - pref[k];
    f(i, k, pos);
    f(k + 1, j, pos+1);
    if(left > right) ans.pb({pos, 'R'});
    else ans.pb({pos+1, 'L'});
}
void solve(){
    int n;
    cin >> n;
    FOR(i,1,n+1){
        cin >> v[i];
        pref[i] = pref[i-1] + v[i];
    }
    int k;
    cin >> k;
    vint b(k+1);
    FOR(i,1,k+1) cin >> b[i];
    FOR(i,1,n+1) FOR(j,1,n+1){
        dp[i][i] = 1;
        p[i][i] = i;
    }
    for(int i = n ; i >= 1 ; i--){
        FOR(j,i+1,n+1){
            FOR(k,i,j){
                int left = pref[k] - pref[i-1], right = pref[j] - pref[k];
                if(dp[i][k] && dp[k+1][j] && (left != right)){
                    dp[i][j] = 1;
                    p[i][j] = k;
                }
            }
        }
    }
    int flag = 0, sum = 0, r = 0, l = 0;
    FOR(i,1,k+1){
        l = r + 1;
        sum = 0;
        while(sum < b[i] && r < n){
            r++;
            sum += v[r];
        }
        if(sum != b[i] || !dp[l][r] ){
            flag = 1;
            break;
        }
        f(l,r,i);
    }   
    if( r!= n) flag = 1;
    if(flag){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for(auto [x, y] : ans) cout << x << " " << y << endl;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);
    int t;
    t = 1;
    while(t--)
    solve();
}