// #pragma GCC target( "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <queue>
#include <numeric>
#include <bitset>
#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <random>
#include <chrono>
// #include <bits/stdc++.h>

// #define int long long
#define pb push_back
#define f first
#define s second
#define ndl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ryoiki_tenkai ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define muryokusho srand(time(0));

const double pi = 3.14159265359;
const int mod = 998244353;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const long long inf = 1ll<<62;
const int P = 31, P1 = 37;
const int maxn = 200200;

using namespace std;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void infinite() {
    int n; cin>>n;
    int x = max((int)sqrt(n), 2);
    int delta = n % x;
    for(int i=delta;i>=1;i--) {
        cout<<i<<' ';
    }
    for(int i=delta+1;i<=n;i+=x) {
        vector<int> p;
        for(int j=i;j<=min(n, i + x - 1);j++) {
            p.pb(j);
        }
        reverse(all(p));
        for(int to: p) cout<<to<<' ';
    }
}
signed main() {
    ryoiki_tenkai
    muryokusho
    #ifndef ONLINE_JUDGE

        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);

    #endif
    srand(time(0));
    int tt=1;
    // cin>>tt;
    for(int i=1;i<=tt;i++) {
        // cout<<"Case "<<i<<": ";
        infinite();
    }
    return 0;
}