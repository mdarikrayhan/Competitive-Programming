#include <bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    cout<<s<<'\n';
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--) solve();
    return 0;
}