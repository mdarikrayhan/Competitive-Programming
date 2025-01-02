/*
Problem: 703C
Date: 28-05-2024 01:25 AM
*/


#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// pretend bus is constant,
// and we run at slope u / v
// find maximum Y coordinate so that the line Y + (u / v) x[i] <= y[i] for all points i
// Y <= y[i] - (u / v) x[i]
// v Y = min_i (v * y[i] - u * x[i])
// time to run is distance (w - vY / v) / u

const int N = 1e4 + 5;
int n;
double w;
ll v, u, x[N], y[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> w >> v >> u;
    ll vY = 0, vy2 = 0;
    rep(i, 0, n) {
        cin >> x[i] >> y[i];
        vY = min(vY, v * y[i] - u * x[i]);
        vy2 = max(vy2, v * y[i] - u * x[i]);
    }
    if(vy2 <= 0) {
        vY = 0;
    }
    double ans = (w - 1.0 * vY / v) / u;
    cout << fixed << setprecision(8);
    cout << ans << endl;
}