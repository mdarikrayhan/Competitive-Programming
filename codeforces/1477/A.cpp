#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline int read(){
    int x = 0, f = 1; char c = getchar();
    while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x * f;
}
template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
template <typename T>
void print(T x, char ch) {
    print(x), putchar(ch);
}
ll a[200005];
inline void solve(){
    ll n,k,q;
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    q=a[2]-a[1];
    for (int i=3;i<=n;i++){
        q=__gcd(q,a[i]-a[i-1]);
    }
    for (int i=1;i<=n;i++){
        if ((k-a[i])%q==0) {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}
int main(){
    int t;
    cin>>t;
    while (t--){
        solve();
    }
    return 0;
}