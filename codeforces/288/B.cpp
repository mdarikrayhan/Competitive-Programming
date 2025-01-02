#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;
int n, k, l, r, p[9];

bool canReach(int ch, int steps=0) {
    if(ch==1) return 1;
    if(steps==k+1) return 0;
    return canReach(p[ch], steps+1);
}

void dfs(int ch) {
    if(ch==k+1) {
        int reach = 1;
        for(int i=1; i<=k; i++) if(reach && !canReach(p[i])) reach = 0;
        l += reach;   
    }
    else for(int i=1; i<=9; i++) p[ch] = i, dfs(ch+1);
}

int powmod(int a, int b) {
    int ans = 1;
    while(b) {
        if(b&1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans % mod;
}

signed main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w" , stdout);
    freopen("error.txt", "w" , stderr);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    dfs(1);
    r = powmod(n-k,n-k)%mod;
    cout << (l*r)%mod;
    return 0;
}