#include<bits/stdc++.h>
using namespace std;
#define  int       long long
void solve(){
    int n; cin >> n;
    vector < int > v(n);
    map < int , int > mp;
    for(int i = 0; i < n; i++)
    cin >> v[i] , mp[v[i]]++;
//     for(auto x : mp)
//     cout << x.first << ' ' << x.second << endl;
//    // cout << endl;
//    cout << mp.size() << endl;
    if(mp.size() > 1)
    cout << 1 << endl;
    else
    cout << n << endl;

}
int32_t main(){
    int t; cin >> t;
    while(t--)
    solve();
}