#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("popcnt")
#define ll long long
#define int long long
#define pii pair<int, int>

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> next(n), pos(n + 1, n);
    for (int i = n - 1; i >= 0; i--){
        next[i] = pos[a[i]];
        pos[a[i]] = i;
    }
    // next[0] = n + 1;

    int num1 = 0, num2 = 0, next1 = n + 1, next2 = n + 1, ans = 0;
    for (int i = 0; i < n; i++){
        if (a[i] == num1){
            ans++ ;
            next1 = next[i];
        }
        else if (a[i] == num2){
            ans++ ;
            next2 = next[i];
        }
        else{
            if (next1 > next2){
                num1 = a[i];
                next1 = next[i];
            }
            else{
                num2 = a[i];
                next2 = next[i];
            }
        }
    }
    cout << n - ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll numTests = 1;
    // cin >> numTests;
    while(numTests-- ){
        solve();
    }
    return 0;
}