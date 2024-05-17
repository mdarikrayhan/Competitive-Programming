#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio();cin.tie(0);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define f first
#define s second
#define pb push_back
#define MAXN 200010
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
 
 
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    if(n<=m){
        bool dp[n+1][m] = {false};
        dp[1][a[1]%m] = true;

        for(int i = 1; i < n; i++){
            for(int j = m-1; j >= 0; j--){
                if(dp[i][j]){
                    dp[i+1][j] = true;
                    dp[i+1][(j + a[i+1]%m)%m] = true;
                }
            }
            dp[i+1][a[i+1]%m] = true; 
        }

        if(dp[n][0]){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    } else {
        cout << "YES\n";
    }

    return 0;
}