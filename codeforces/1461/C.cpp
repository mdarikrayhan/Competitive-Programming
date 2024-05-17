#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<numeric>
#include<map>
#include<queue>
#include<stack>
#include<math.h>
#include<iomanip>
#include<array>
// #include<bits/stdc++.h>
 
#define ll long long
#define double long double
#define str string
#define ins insert
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
 
using namespace std;

void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    } vector<int> is(n,0);
    int mx=0;
    for (int i=0; i<n; i++) {
        mx=max(mx,v[i]);
        if (mx==i+1) {
            is[i]=1;
        }
    } for (int i=n-2; i>=0; i--) {
        is[i]&=is[i+1]; 
    } vector<double> a(n,0);
    double t=1;
    for (int i=0; i<m; i++) {
        int q;
        double p;
        cin >> q >> p;
        q--;
        if (is[q]) {
            a[q]+=t*p;
            t-=t*p;
        }
    } double ans=0;
    for (int i=0; i<n; i++) {
        ans+=a[i]; 
    } if (is[0]) {
        ans+=t;
    } cout << ans << "\n";
}
 
int main() {
    //freopen("moocast.in", "r", stdin);
    //freopen("moocast.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt=1;
    cin >> tt;
    cout << setprecision(7);
    while (tt--) {
        //cout << "Case#" << tt <<":\n";
        solve();
    }
    return 0;
}
 
//use setprecision(20) for double baka