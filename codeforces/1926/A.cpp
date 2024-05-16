#include <bits/stdc++.h>

using namespace std;

void solve(){
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (const char c : s){
        a += (c == 'A' ? 1 : 0);
        b += (c == 'B' ? 1 : 0);
    }
    cout << (a > b ? 'A' : 'B');
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
    solve();
    }
    return 0;
}
