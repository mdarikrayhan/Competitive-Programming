#include<iostream>
#include<queue>
using namespace std;
#define int long long 
#define N 200005
#define pii pair<int, int>
#define pip pair<int, pii> // pip install orz
#define F first 
#define S second
int mp[25][25];
int f(int x, int y){
    int ret = 0;
    for (int i = x; i < x + 4; i++){
        for (int j = y; j < y + 4; j++)
            ret += mp[i][j];
    }
    return ret;
}
void solve(){
    string s;
    for (int i = 1; i <= 21; i++){
        cin >> s;
        for (int j = 1; j <= 21; j++)
            mp[i][j] = s[j - 1] - '0';
    }
    int ans = 0;
    for (int i = 1; i <= 18; i++){
        for (int j = 1; j <= 18; j++){
            ans = max(ans, f(i, j));
        }
    }
    cout << ans << "\n";
}
signed main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}