#include <bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define pb push_back
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mk make_pair
#define yes cout << "YES" << '\n'
#define no cout << "NO" << '\n'
#define all(x) x.begin(),x.end()
#define sz(x) (int) x.size()
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target( "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native" )
#pragma GCC optimize("unroll-loops")
#define int long long
//stoi(s)
using namespace std;
unordered_map <int, int> mp1;
unordered_map <int, int> mp2;
const int MAXN = 1e6;
int cnt[MAXN + 1];

void solve(){
    int n;
    cin >> n;
    pair <int, int> a[n + 1];
    int st = 0;
    int fn = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i].f >> a[i].s;
        mp1[a[i].f] = a[i].s;
        mp2[a[i].s] = a[i].f;
        cnt[a[i].f]++;
        cnt[a[i].s]++;
    }
    for (int i = 1;  i<= n; i++){
        if (cnt[a[i].f] == 1){
            st = a[i].f;
        }
        if (!a[i].f){
            fn = a[i].s;
        }
    }
    int ans[n + 1];
    int cur = st;
    for (int i = 1; i <= n; i += 2){
        ans[i] = cur;
        cur = mp1[cur];
    }
    cur = fn;
    for (int i = 2; i <= n; i += 2){
        ans[i] = cur;
        cur = mp1[cur];
    }
    for (int i = 1; i <= n; i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';

}

signed main() {
    IOS;
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }

}

