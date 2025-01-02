#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(),a.end()
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using pii = pair<int,int>;

void solve() {
    int inf = 1e9;
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) cin >> a[i];
    if(n == 1){
        cout << "YES\n";
        cout << inf << " " << 1 << '\n';
        return;
    }
    int col = 1;
    for(int i = 2; i <= n; i ++){
        int x = abs(a[i] - a[i - 1]);
        if(x == 0){
            cout << "NO\n";
            return;
        }else if(x != 1){
            col = x;
        }
    }
    if (col == 1) {
        cout << "YES" << endl;
        cout << inf << ' ' << 1 << endl;
        return;
    }
    for (int i = 2; i <= n; i ++ ) {
        int x = abs(a[i] - a[i-1]);
        if (x == 1 && ((a[i] - 1) / col != (a[i-1] - 1) / col)) {
            cout << "NO" << endl;
            return;
        }
        if (x != 1 && x != col) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    cout << inf << ' ' << col << endl;
}

int main()
{
    ios;
    int _ = 1;
    //cin >> _;
    while(_ --){
        solve();
    }
    return 0;
}