#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n, a, b, c, cnt = 0; cin >> n >> a >> b >> c;
    ll diff = b - c;
    if(diff >= a){
        cout << n / a;
        return 0;
    }
    if(b > n){cout << n / a; return 0;}
    //if(b == n){cout << 1 + diff / a; return 0;}
    ll t = n - b;
    ll ans = (t / diff) * diff;
    cnt += t / diff;
    if(ans + b > n){
        if(n - ans >= a)cout << cnt + (n - ans) / a;
        else cout << cnt;
        return 0;
    }
    ans += diff; cnt++;
    if(ans + a <= n){cout << cnt + (n - ans) / a;}
    else cout << cnt;
    //n -= ans * b;
}
