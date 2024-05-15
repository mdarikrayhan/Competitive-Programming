#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    int n, t;
    cin >> n >> t;
    vector<ll> q(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> q[i];
    sort(q.begin() + 1, q.end());
    for (int i = 1; i <= n; i++) q[i] += q[i - 1];
    while(t--){
        int x, y;
        cin >> x >> y;
        cout << q[n - x + y] - q[n - x] << endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while(t--)
    solve();
}